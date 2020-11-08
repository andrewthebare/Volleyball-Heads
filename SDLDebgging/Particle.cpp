#include "Particle.h"

Particle::Particle(SDL_Rect b, SDL_Texture* t) {
	body = b;
	tex = t;

	alive = true;
}


void Particle::update() {
	//update pos
	xPos += xVel;
	yPos += yVel;
	angle += angleVel;


	lifeTime--;
	if (lifeTime < 0) {
		alive = false;
	}
}

void Particle::render(SDL_Renderer *r) {
	if(alive)
		SDL_RenderCopyEx(r, tex, NULL, &body, angle, NULL, SDL_FLIP_NONE);
}