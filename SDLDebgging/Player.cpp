#include "Player.h"


/*Constructor*/
Player::Player() {
	currentLateralVelocity = 0;
}

Player::Player(SDL_Rect r, SDL_Texture* tex) {
	rect = r;

	texture = tex;
	currentLateralVelocity = 0;
}

void Player::moveLeft() {
	if (currentLateralVelocity > -1)
		currentLateralVelocity += -.01;

	moveRect();
}
void Player::moveRight() {
	if(currentLateralVelocity<1)
		currentLateralVelocity += .01;

	moveRect();
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

void Player::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}