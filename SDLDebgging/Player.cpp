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

	landing = ParticleEffect(10, 250, 240, 25, 250);
}

/*
	These are the movement functions, that add or subtract from current velocity to
	make my player move

	I'm experimenting with adding a timer function so that it takes a second or so to reach max speed
*/
void Player::moveLeft() {
	if (currentLateralVelocity > -1 * veloScale) {
		currentLateralVelocity -= 1;
		veloTimer = 0;
	}
	veloTimer++;

	currentAngle-=veloScale;
	if (currentAngle < 0)
		currentAngle = 359;
}
void Player::moveRight() {
	if (currentLateralVelocity < veloScale) {
		currentLateralVelocity += 1;
		veloTimer = 0;
	}
	veloTimer++;

	currentAngle+=veloScale;
	if (currentAngle > 359)
		currentAngle = 0;

}
void Player::slowDown() {
	veloTimer = 0;
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
	//std::cout<<"V: " << currentLateralVelocity;

	if (jump && rect.y == GameEngine::FLOOR) {
		currentVerticalVelocity = -20;
	}
	jump = false;

	rect.y += currentVerticalVelocity;

	if (rect.y < GameEngine::FLOOR) {
		gravityTimer++;

		if (currentVerticalVelocity < 20) {
			currentVerticalVelocity += 2;
			gravityTimer = 0;
		}

	}
	else {
		//just landed
		if(currentVerticalVelocity>0)
			landing.trigger(rect.x + 20, rect.y + 33);
		currentVerticalVelocity = 0;
		rect.y = GameEngine::FLOOR;
	}


}


SDL_Rect Player::getRect() {
	return rect;
}

void Player::render(SDL_Renderer* renderer) {
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, currentAngle, NULL, SDL_FLIP_NONE);
	
	landing.update();
	landing.render(renderer);
}