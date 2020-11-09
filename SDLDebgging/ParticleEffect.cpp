#include "ParticleEffect.h"

ParticleEffect::ParticleEffect() {
	std::cout << "Default Constructor for Effect\n";
}
ParticleEffect::ParticleEffect(int particleNum, int r, int g, int b, int a) {	
	lifeTime = -1;
	//parts(particleNum);
	particleNumber = particleNum;
	alive = false;
}

void ParticleEffect::trigger(int x, int y) {

	//so we don't wreck our system, it can only be active one at a time
	if (!alive) {
		alive = true;
		lifeTime = 50;

		//fill the particle array
		for (int i = 0; i < particleNumber; i++) {	//TODO Randomness
			SDL_Rect r;
			r.x = x;
			r.y = y;
			r.w = 50;
			r.h = 50;

			parts.push_back(Particle(r, 0, 250, 0));

			parts.at(i).angle = 0;
			parts.at(i).angleVel = 0;
			parts.at(i).xVel = 1;
			parts.at(i).yVel = 0;
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