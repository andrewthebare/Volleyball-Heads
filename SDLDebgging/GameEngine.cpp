#include "GameEngine.h"
#include "Player.h"
#include "GameObject.h"
#include "CollisionDetector.h"
#include"ParticleEffect.h"

GameEngine::GameEngine() {
	std::cout << "GameEngine Created";
}

void GameEngine::init() {
	col = CollisionDetector();

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
	}

	//Enable gpu_enhanced textures
	IMG_Init(IMG_INIT_PNG);

	my_window = SDL_CreateWindow("my_game",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT, 0);
	my_renderer = SDL_CreateRenderer(my_window, -1, 0);

}


/*
* This function is where I register all the global parts of the game to GameEngine();
*/
void GameEngine::registerPlayers(){
	SDL_Texture* wheelTexture = NULL;
	SDL_Surface* wheel = IMG_Load("./carwheel.png");

	wheelTexture = SDL_CreateTextureFromSurface(my_renderer, wheel);
	SDL_FreeSurface(wheel);

	
	SDL_Rect playerRect;
	playerRect.x = 60;
	playerRect.y = FLOOR;
	playerRect.w = 50;
	playerRect.h = 50;
	player1 = Player(playerRect, wheelTexture);

	//player2 = p2;
	//player3 = p3;
	//player4 = p4;


	//also GameObjects
	SDL_Rect backgroundRec;
	backgroundRec.x = 0;
	backgroundRec.y = 0;
	backgroundRec.w = SCREEN_WIDTH;
	backgroundRec.h = SCREEN_HEIGHT+60;

	SDL_Texture* beachTex = NULL;
	SDL_Surface* beach = IMG_Load("./beachBG.jpg");

	beachTex = SDL_CreateTextureFromSurface(my_renderer, beach);
	SDL_FreeSurface(beach);

	background = GameObject(backgroundRec, beachTex);


	SDL_Rect courtRect;
	courtRect.x = 0;
	courtRect.y = SCREEN_HEIGHT-60;
	courtRect.w = SCREEN_WIDTH;
	courtRect.h = 60;

	SDL_Texture* courtTexture = NULL;
	SDL_Surface* court = IMG_Load("./Court.png");

	courtTexture = SDL_CreateTextureFromSurface(my_renderer, court);
	SDL_FreeSurface(court);

	ground = GameObject(courtRect, courtTexture);
	
	SDL_Rect netRec;
	netRec.x = SCREEN_WIDTH/2-10;
	netRec.y = SCREEN_HEIGHT -300;
	netRec.w = 20;
	netRec.h = SCREEN_HEIGHT;

	net = GameObject(netRec, courtTexture);

	SDL_Rect trampolineRect;
	trampolineRect.x = SCREEN_WIDTH / 2 - 100;
	trampolineRect.y = SCREEN_HEIGHT - 60;
	trampolineRect.w = 60;
	trampolineRect.h = 20;

	Trampoline = GameObject(trampolineRect, beachTex);

	SDL_Rect trampolineRectR;
	trampolineRectR.x = SCREEN_WIDTH / 2 +40;
	trampolineRectR.y = SCREEN_HEIGHT - 60;
	trampolineRectR.w = 60;
	trampolineRectR.h = 20;

	TrampolineRight = GameObject(trampolineRectR, beachTex);



	grass = ParticleEffect(5, 250, 250, 20, 250);
	black = ParticleEffect(15, 0, 0, 0, 250);

	SDL_Rect ballRec;
	ballRec.x = SCREEN_WIDTH / 2 - 10;
	ballRec.y = 100;
	ballRec.w = 40;
	ballRec.h = 40;

	ball = Ball(ballRec, wheelTexture);

}

void GameEngine::handleEvents() {
	SDL_Event game_event;
	SDL_PollEvent(&game_event);
	SDL_PumpEvents();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_LEFT]) {
		player1.move = player1.left;
	}
	else if (keystate[SDL_SCANCODE_RIGHT]) {
		player1.move = player1.right;
	}
	else {
		player1.move=player1.nothing;
	}


	switch (game_event.key.keysym.sym) {	//one time hits
	case SDLK_UP:
		player1.jump = true;

		if (col.RectangleCollision(Trampoline.getRect(), player1.getRect())) {
			player1.trampJump = true;
		}
		break;
	}

}

void GameEngine::updateMechanics() {
	//switch statement based on which moving enum is active
	//player
	switch (player1.move)
	{
		case 0:{
			player1.slowDown();
			break;
		}
		case 1: {
			player1.moveLeft();
			break;
		}
		case 2: {
			player1.moveRight();
			break;
		}
	default:
		//check for collisison between player and net
		break;
	}

	//check for colission with ball
	if (col.RectangleCollision(player1.getRect(), ball.getRect())) {
		//here we calcualte angle into an x and y and bounce accordingly
		pair<int, int> anglePair = col.CalculateAngle(ball.getRect(), player1.getRect(),ball.currentLateralVelocity, ball.currentVerticalVelocity,player1.currentLateralVelocity,player1.currentVerticalVelocity);
		ball.Bounce(anglePair.first, anglePair.second);
	}

	//ball to net
	if (col.RectangleCollision(ball.getRect(), net.getRect())) {
		if (ball.getRect().y + ball.getRect().h < net.getRect().y + 40) {
			ball.currentVerticalVelocity *= -.7;
		}
		else {
			ball.currentLateralVelocity *= -.7;
		}
	}

	//testing purposes
	if (col.RectangleCollision(ball.getRect(), ground.getRect())) {
		ball.currentVerticalVelocity *= -1;
	}

	//testing my collision system
	bool b = col.RectangleCollision(player1.getRect(), net.getRect());
	SDL_Rect q;
	q.x = 0;
	q.y = 0;
	q.h = SCREEN_HEIGHT;
	q.w = 1;
	bool c = col.RectangleCollision(player1.getRect(), q);
	if (b || c) {
		player1.currentLateralVelocity = -1*player1.currentLateralVelocity;
		black.trigger(player1.getRect().x+20, player1.getRect().y+32);
		//COLLIDE
	}
	player1.moveRect();
	ball.Update();

	//texture
	black.update();
}

void GameEngine::render() {

	//maybe store all players in array and loop through
	//need a copy of the environment as well

	//all environment variables
	SDL_RenderClear(my_renderer);

	//environment
	background.render(my_renderer);

	//SDL_SetRenderDrawColor(my_renderer, 255, 0, 190, 250);
	//SDL_RenderClear(my_renderer);
	ground.renderSolidRect(my_renderer, 250, 230, 0, 250);
	net.renderSolidRect(my_renderer, 0, 0, 0, 250);
	Trampoline.renderSolidRect(my_renderer, 250, 40, 40, 250);
	TrampolineRight.renderSolidRect(my_renderer, 250, 40, 40, 250);

	
	
	player1.render(my_renderer);
	ball.render(my_renderer);


	black.render(my_renderer);

	//SDL_RenderCopy(my_renderer, wheelTexture, NULL, &wheelFront);
	//SDL_RenderCopy(my_renderer, wheelTexture, NULL, &wheelBack);
	SDL_RenderPresent(my_renderer);


}

void GameEngine::quit() {
	SDL_DestroyRenderer(my_renderer);
	SDL_DestroyWindow(my_window);

	IMG_Quit();
	SDL_Quit();

}

