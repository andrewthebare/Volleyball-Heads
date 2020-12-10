#pragma once

#include <iostream>
#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>
#include <SDL_ttf.h>

#include "Player.h"
#include "GameObject.h"
#include"CollisionDetector.h"
#include "ParticleEffect.h"
#include "Ball.h"
#include "Bot.h"
#include "TextObject.h"


class GameEngine
{
private:

	//NEED A BALL
	Ball ball;
	CollisionDetector col;

	Player player1 = Player();
	Bot player2 = Bot();

	//Player player3 = Player();
	//Player player4 = Player();

	GameObject objects[10];
	int objectIndex = 0;
	void addObject(GameObject obj) {
		objects[objectIndex] = obj;
		objectIndex++;
	}

	GameObject background;
	GameObject ground;
	GameObject net;
	GameObject pauseMenu;
	int pauseTimer = 0;

	GameObject Trampoline;
	GameObject TrampolineRight;

	SDL_Rect leftBound;
	SDL_Rect rightBound;
	SDL_Rect top;

	ParticleEffect grass;
	ParticleEffect black;

	SDL_Rect leftSide, RightSide;

	int score1, score2 = 0;
	int maxScore = 10;
	TextObject leftText;
	TextObject rightText;

public:
	bool gameGo = true;
	int winnerFound = false;

	bool startScreen, pause = false;
	bool pointScored = false;
	int pointTimer = 0;

	static const int SCREEN_WIDTH = 1100;
	static const int SCREEN_HEIGHT = 600;

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

	//screens
	void startScreenFunc();
	void winnerScreen();
};

