#include "Player.h"
#include "GameEngine.h"


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
	if (currentLateralVelocity > -5)
		currentLateralVelocity -= 1;
}
void Player::moveRight() {
	if(currentLateralVelocity<5)
		currentLateralVelocity += 1;

}
void Player::slowDown() {
	if (currentLateralVelocity > 0) {
		currentLateralVelocity -= 1;

		if (currentLateralVelocity < 0)
			currentLateralVelocity = 0;
	}
	else if (currentLateralVelocity < 0) {
		currentLateralVelocity += 1;

		if (currentLateralVelocity > 0)
			currentLateralVelocity = 0;

	}
}
double Player::getLateralVelocity() {
	return currentLateralVelocity;
}

/*Call once per frame, moves the rect according to the lateral velocity*/
void Player::moveRect() {
	rect.x += currentLateralVelocity;
	std::cout<<"V: " << currentLateralVelocity;

	if (jump) {
		currentVerticalVelocity = -15;
		jump = false;
	}

	rect.y += currentVerticalVelocity;

	if (rect.y < GameEngine::FLOOR) {
		currentVerticalVelocity += 1;
	}
	else {
		currentVerticalVelocity = 0;
		rect.y = GameEngine::FLOOR;
	}


}


SDL_Rect Player::getRect() {
	return rect;
}

void Player::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}