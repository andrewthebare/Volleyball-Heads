#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//A circle stucture
struct Circle
{
	int x, y;
	int r;
};

class CircleRect
{
public:
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 1;

	//Initializes the variables
	CircleRect(int x, int y);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot and checks collision
	void move(SDL_Rect& square, Circle& circle);

	//Shows the dot on the screen
	void render();

	//Gets collision circle
	Circle& getCollider();

private:
	//The X and Y offsets of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelX, mVelY;

	//Dot's collision circle
	Circle mCollider;

	//Moves the collision circle relative to the dot's offset
	void shiftColliders();
};

