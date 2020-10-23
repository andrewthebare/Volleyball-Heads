#include "GameEngine.h"
#include "Player.h"
#include "GameObject.h"

GameEngine::GameEngine() {
	std::cout << "GameEngine Created";
}

void GameEngine::init() {
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
	playerRect.x = 30;
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
		break;
	}

}

void GameEngine::updateMechanics() {
	//switch statement based on which moving enum is active
	//player
	switch (player1.move)
	{
		case 0:{
			std::cout << "-- --- --" << endl;
			player1.slowDown();
			break;
		}
		case 1: {
			std::cout << "GO LEFT" << endl;
			player1.moveLeft();
			break;
		}
		case 2: {
			player1.moveRight();
			break;
		}
	default:

		break;
	}


	player1.moveRect();
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
	ground.renderSolidRect(my_renderer, 0, 0, 0, 250);
	net.renderSolidRect(my_renderer, 0, 0, 0, 250);
	
	
	player1.render(my_renderer);

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