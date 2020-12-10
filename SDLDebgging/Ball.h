#pragma once

#include <iostream>
#include <string>
#include <math.h>


#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

class Ball
{
private:
	SDL_Rect rect;
	SDL_Texture* texture;

	int maxSpeed = 20;
	int veloScale = 10;

	int gravTimer = 0;


public:
	double currentLateralVelocity;
	double currentVerticalVelocity = 0;

	Ball();
	Ball(SDL_Rect r, SDL_Texture* t);
	SDL_Rect getRect();

	void Bounce(int x, int y);
	std::pair<int, int> getCenter();
	void Update();

	void render(SDL_Renderer* r);

};

