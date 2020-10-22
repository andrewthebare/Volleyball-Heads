#include "Player.h"


/*Constructor*/
Player::Player(SDL_Rect r) {
	rect = r;

	currentLateralVelocity = 0;
}

void Player::moveLeft() {
	if (currentLateralVelocity > -1)
		currentLateralVelocity += -.01;
}
void Player::moveRight() {
	if(currentLateralVelocity<1)
		currentLateralVelocity += .01;
}
double Player::getLateralVelocity() {
	return currentLateralVelocity;
}

/*Call once per frame, moves the rect according to the lateral velocity*/
void Player::moveRect() {
	rect.x += currentLateralVelocity;
}


SDL_Rect Player::getRect() {
	return rect;
}

void Player::render(SDL_Renderer* renderer, SDL_Texture* tex) {
	SDL_RenderCopy(renderer, tex, NULL, &rect);
}