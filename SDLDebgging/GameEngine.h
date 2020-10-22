#pragma once

#include <iostream>
#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

class GameEngine
{
private:
	const int SCREEN_WIDTH = 1500;
	const int SCREEN_HEIGHT = 480;

	Player player1;

public:
	enum moveState {left,right, up} moving=right;

	SDL_Window* my_window = NULL;
	SDL_Renderer* my_renderer = NULL;
	SDL_Event input;

	GameEngine();

	void init();

	void handleEvents();

	void updateMechanics();
	
	void render();

	void quit();
};

