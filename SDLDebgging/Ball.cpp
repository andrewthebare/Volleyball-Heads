#include "Ball.h"
#include "GameEngine.h"

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
	std::cout << "Bounce vals\n"<< x<<"|" << y<<std::endl;
	std::cout << "\nCurrentX|Y\n" << currentLateralVelocity << "|" << currentVerticalVelocity << std::endl;

	currentLateralVelocity += x;
	currentVerticalVelocity += y;

	
}

void Ball::Update() {
	//move laterally
	rect.x += currentLateralVelocity;

	//if we hit the end
	if (rect.x<0 || rect.x + rect.w>GameEngine::SCREEN_WIDTH) {
		currentLateralVelocity *= -.7;
	}

	rect.y += currentVerticalVelocity;

	//gravity
	if (currentVerticalVelocity < 25 && gravTimer>0) {
		currentVerticalVelocity += 1;
		gravTimer = 0;
	}
	gravTimer++;
}




void Ball::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}