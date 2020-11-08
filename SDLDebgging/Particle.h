#pragma once

#include <iostream>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

class Particle
{
public:
	Particle();
	Particle(SDL_Rect b, SDL_Texture* t);
	Particle(SDL_Rect rec, int r, int g, int b);

	void update();
	void render(SDL_Renderer *r);

	int angle, angleVel, xVel, yVel = 0;
	double lifeTime;
	bool alive = false;
private:
	SDL_Rect body;
	SDL_Texture *tex;
	int red, green, blue;
};

