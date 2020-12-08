#include "Ball.h"

Ball::Ball() {

}

Ball::Ball(SDL_Rect r, SDL_Texture* t) {
	rect = r;
	texture = t;

	currentLateralVelocity = -12;
}

SDL_Rect Ball::getRect() {
	return rect;
}

void Ball::Bounce(int x, int y) {

}

void Ball::Update() {
	//move laterally
	rect.x += currentLateralVelocity;

	rect.y += currentVerticalVelocity;

	//gravity
	if (currentVerticalVelocity < 10 && gravTimer>0) {
		currentVerticalVelocity += 1;
		gravTimer = 0;
	}
	gravTimer++;
}




void Ball::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}