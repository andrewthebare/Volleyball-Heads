#pragma once

#include <iostream>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>
#include <vector>

#include "Particle.h"

class ParticleEffect
{
public:
	ParticleEffect();
	ParticleEffect(int particleNum, int r, int g, int b, int a);

	void trigger(int x, int y);
	void update();
	void render(SDL_Renderer* r);

private:	
	double lifeTime;
	int particleNumber;
	bool alive;
	std::vector<Particle> parts;

};

