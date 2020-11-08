#pragma once

#include <iostream>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

class Particle
{
public:
	Particle(SDL_Rect b, SDL_Texture* t);

	void update();
	void render(SDL_Renderer *r);

	int xPos, yPos, angle, angleVel, xVel, yVel = 0;
	double lifeTime;
	bool alive = false;
private:
	SDL_Rect body;
	SDL_Texture *tex;
};

