#include "GameEngine.h"
#include "Player.h"

GameEngine::GameEngine() {
	std::cout << "GameEngine Created";
	//where our global variables go
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

void GameEngine::registerPlayers(){
	SDL_Texture* wheelTexture = NULL;
	SDL_Surface* wheel = IMG_Load("./carwheel.png");

	wheelTexture = SDL_CreateTextureFromSurface(my_renderer, wheel);
	SDL_FreeSurface(wheel);

	
	SDL_Rect playerRect;
	playerRect.x = 30;
	playerRect.y = 30;
	playerRect.w = 50;
	playerRect.h = 50;
	player1 = Player(playerRect, wheelTexture);

	//player2 = p2;
	//player3 = p3;
	//player4 = p4;
}

void GameEngine::handleEvents() {
	SDL_Event game_event;
	SDL_PollEvent(&game_event);

	//const Uint8* keystate = SDL_GetKeyboardState(NULL);

	//if (keystate[SDLK_LEFT]) {
	//	player1.move = player1.left;
	//}
	//else if (keystate[SDLK_RIGHT]) {
	//	player1.move = player1.right;
	//}
	//else {
	//	player1.move=player1.nothing;
	//}


	switch (game_event.key.keysym.sym) {	//each player will have a personal move state
	case SDLK_RIGHT:
		player1.move = player1.right;
		break;
	case SDLK_LEFT:
		player1.move = player1.left;
		break;

	default:
		player1.move = player1.nothing;
		break;
	}

}

void GameEngine::updateMechanics() {
	//switch statement based on which moving enum is active
	//player
	std::cout << "Move Value: " << player1.move << endl;
	switch (player1.move)
	{
		case 0:{
			//std::cout << "I DO NOTHING";
		}
		case 1: {
			player1.moveLeft();
		}
	default:
		break;
	}
}

void GameEngine::render() {

	//maybe store all players in array and loop through
	//need a copy of the environment as well

		//SDL_RenderClear(my_renderer);
	SDL_SetRenderDrawColor(my_renderer, 255, 0, 190, 250);
	SDL_RenderClear(my_renderer);

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