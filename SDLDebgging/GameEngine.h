#pragma once

#include <iostream>
#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

#include "Player.h"
#include "GameObject.h"


class GameEngine
{
private:
	const int SCREEN_WIDTH = 1500;
	const int SCREEN_HEIGHT = 480;
	const int FLOOR = 400;

	Player player1 = Player();
	Player player2 = Player();
	Player player3 = Player();
	Player player4 = Player();

	GameObject objects[10];
	int objectIndex = 0;
	void addObject(GameObject obj) {
		objects[objectIndex] = obj;
		objectIndex++;
	}

public:
	SDL_Window* my_window = NULL;
	SDL_Renderer* my_renderer = NULL;
	//SDL_Event input;

	GameEngine();

	void init();

	//to give the GameEngine an instance of each player
	void registerPlayers();

	void handleEvents();

	void updateMechanics();
	
	void render();

	void quit();
};

