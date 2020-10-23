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
	SDL_Texture* texture;


public:
	enum moveState {nothing, left, right, up} move=nothing;

	double currentLateralVelocity;
	Player();

	//Texture needs to be preloadded
	Player(SDL_Rect r, SDL_Texture* tex);

	void moveLeft();
	void moveRight();
	void slowDown();

	void moveRect();

	SDL_Rect getRect();


	double getLateralVelocity();

	void render(SDL_Renderer* renderer);
};

