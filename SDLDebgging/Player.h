#pragma once
#include <iostream>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

using namespace std;

class Player
{
private:
	//int positionX;
	//int positionY;

	SDL_Rect rect;


public:
	enum moveState {left, right, up};

	double currentLateralVelocity;
	Player(SDL_Rect r);

	void moveLeft();
	void moveRight();

	void moveRect();

	SDL_Rect getRect();


	double getLateralVelocity();

	void render(SDL_Renderer* renderer, SDL_Texture* tex);
};

