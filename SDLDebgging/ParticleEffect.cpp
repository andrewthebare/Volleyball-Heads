#include <stdlib.h>
#include "ParticleEffect.h"

ParticleEffect::ParticleEffect() {
	std::cout << "Default Constructor for Effect\n";
}
ParticleEffect::ParticleEffect(int particleNum, int r, int g, int b, int a) {	
	red = r;
	green = g;
	blue = b;
	
	lifeTime = -1;
	//parts(particleNum);
	particleNumber = particleNum;
	alive = false;
}

void ParticleEffect::trigger(int x, int y) {

	//so we don't wreck our system, it can only be active one at a time
	if (!alive) {
		alive = true;
		lifeTime = 15;

		//fill the particle array
		for (int i = 0; i < particleNumber; i++) {	//TODO Randomness
			SDL_Rect r;
			r.x = x;
			r.y = y;
			r.w = rand()%9;
			r.h = rand()%9;

			parts.push_back(Particle(r, red, green, blue));

			parts.at(i).angle = rand()%360;
			parts.at(i).angleVel = rand() % 3;
			parts.at(i).xVel = rand() % 3;
			parts.at(i).yVel = -1* rand() % 5;
		}

	}

}

void ParticleEffect::update() {
	if (alive) {
		for (int i = 0; i < parts.size(); i++) {

			std::cout << parts.at(i).lifeTime << "| ParticleLife\n";

			parts.at(i).update();
		}
		lifeTime--;	
		if (lifeTime < 0) {
			alive = false;
			//deconstruct
			/*for (int i = 0; i < parts.size(); i++) {
				}
			*/
			parts.clear();
		}
	}
}
	


void ParticleEffect::render(SDL_Renderer* r) {
	if (alive) {
		for (int i = 0; i < parts.size(); i++) {
			parts.at(i).render(r);
		}	

	}
}