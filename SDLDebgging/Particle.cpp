#include "Particle.h"

Particle::Particle() {
	std::cout << "EMPTY PARTICLE";
}
Particle::Particle(SDL_Rect b, SDL_Texture* t) {
	body = b;
	tex = t;

	alive = true;
}
Particle::Particle(SDL_Rect rec, int r, int g, int b) {
	body = rec;
	red = r;
	green = g;
	blue = b;

	alive = true;
	lifeTime = 50000;
}


void Particle::update() {
	if (alive) {
		//update pos
		body.x += xVel;
		body.y += yVel;
		angle += angleVel;


		lifeTime--;
		if (lifeTime < 0) {
			alive = false;
		}
	}
	std::cout << "Lifetime: " << lifeTime;
}

void Particle::render(SDL_Renderer *r) {
	if (alive) {
		SDL_RenderCopyEx(r, tex, NULL, &body, angle, NULL, SDL_FLIP_NONE);
		std::cout << "DRAWING";
	}
}