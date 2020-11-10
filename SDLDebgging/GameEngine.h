#pragma once

#include <iostream>
#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

#include "Player.h"
#include "GameObject.h"
#include"CollisionDetector.h"
#include "ParticleEffect.h"


class GameEngine
{
private:
	static const int SCREEN_WIDTH = 1500;
	static const int SCREEN_HEIGHT = 600;


	CollisionDetector col;

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

	GameObject background;
	GameObject ground;
	GameObject net;

	ParticleEffect grass;
	ParticleEffect black;

public:
	static const int FLOOR = SCREEN_HEIGHT-60-40;
	static const int FRAMEDURATION = 1000 / 30;	//fps
	int fpsCounter = 0;

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

