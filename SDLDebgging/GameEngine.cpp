#include "GameEngine.h"
#include "Player.h"

GameEngine::GameEngine(void) {
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

void GameEngine::handleEvents() {
	SDL_Event game_event;
	SDL_PollEvent(&game_event);

	switch (game_event.key.keysym.sym) {	//each player will have a personal move state
	case SDLK_RIGHT:
		moving = right;
		break;
	case SDLK_LEFT:
		moving = left;
		break;
	}

}

void GameEngine::updateMechanics() {
	//switch statement based on which moving enum is active
}

void GameEngine::render() {

}

void GameEngine::quit() {
	SDL_DestroyRenderer(my_renderer);
	SDL_DestroyWindow(my_window);

	IMG_Quit();
	SDL_Quit();

}