#include "Ball.h"
#include "GameEngine.h"

Ball::Ball() {

}

Ball::Ball(SDL_Rect r, SDL_Texture* t) {
	rect = r;
	texture = t;

	currentLateralVelocity = -12;
	veloScale = 20;
}

SDL_Rect Ball::getRect() {
	return rect;
}

void Ball::Bounce(int x, int y) {
	//std::cout << "Bounce vals\n"<< x<<"|" << y<<std::endl;
	//std::cout << "\nCurrentX|Y\n" << currentLateralVelocity << "|" << currentVerticalVelocity << std::endl;
	std::cout << "Vals:" << x << " | " << y<<endl;

	currentLateralVelocity = x/1.25;
	currentVerticalVelocity = y/2;

	std::cout << "Velo:" << currentLateralVelocity << " | " << currentVerticalVelocity << endl;

	if (abs( currentLateralVelocity) > maxSpeed) {
		if (currentLateralVelocity > 0)
			currentLateralVelocity = maxSpeed;
		else
			currentLateralVelocity = maxSpeed * -1;
	}
	if (abs(currentVerticalVelocity) > maxSpeed) {
		if (currentVerticalVelocity > 0)
			currentVerticalVelocity = maxSpeed;
		else
			currentVerticalVelocity = maxSpeed * -1;
	}
}

void Ball::setX(int x) {
	rect.x = x;
}

pair<int, int> Ball::getCenter() {
	int x = (rect.x + rect.w / 2);
	int y = (rect.y + rect.h / 2);

	return pair<int, int>(x, y);
}

void Ball::Update() {
	//move laterally
	rect.x += currentLateralVelocity;

	//if we hit the end
	if (rect.x<0 || rect.x + rect.w>GameEngine::SCREEN_WIDTH) {
		currentLateralVelocity *= -1;
		if (rect.x > 10)
			rect.x = GameEngine::SCREEN_WIDTH - rect.w;
		else
			rect.x = 0;
	}

	rect.y += currentVerticalVelocity;

	//gravity
	if (currentVerticalVelocity < 25 && gravTimer>1) {
		currentVerticalVelocity += 1;
		gravTimer = 0;
	}
	gravTimer++;
}




void Ball::render(SDL_Renderer* renderer) {
	//could add a rotation that switches based on the direction the ball hits
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}