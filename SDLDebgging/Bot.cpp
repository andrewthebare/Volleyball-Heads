#include "Bot.h"

Bot::Bot() {
	currentLateralVelocity = 0;
}

Bot::Bot(SDL_Rect r, SDL_Texture* tex, int start){
	

	rect = r;
	texture = tex;
	startX = start;

	veloScale = 5*botDifficulty;
	acceleration = 1+.5*botDifficulty;
}

void Bot::updateState(Ball b, int halfway) {
	this->halfway = halfway;
	if (b.getRect().x < halfway) {	//if the ball is on the other half
		if (startX + veloScale >= rect.x && startX - veloScale < rect.x) {
			botState = idle;
		}
		else {
			botState = reset;
		}
	}
	
	if (b.getRect().x >halfway /*|| b.currentLateralVelocity > 0*/) {	//could be made else if
		botState = defending;
		//std::cout << "I gotta defend\n";
	}
}

void Bot::updateBotMovement(Ball b) {
	switch (botState)
	{
	case idle:
		//std::cout << "I'm home\n";
		currentLateralVelocity = 0;
		break;

	case reset:
		if (rect.x > startX) {
			//std::cout << "I want to move left\n";
			moveLeft();
		}
		else {
			moveRight();
		}
		break;

		//if (startX+veloScale >= rect.x && startX-veloScale<rect.x)
		//	currentLateralVelocity = 0;

	case defending:
		//go to the ball
		//std::cout << "\nrect.x: " << rect.x << " | ball center: " << b.getCenter().first;
		if (rect.x > b.getCenter().first) {
			moveLeft();
		}
		else {
			//cout << "Wait go back!\n";
			moveRight();
		}

		//trigger the jump
		if (rect.x > b.getCenter().first && rect.x < b.getRect().x + b.getRect().w) {
			currentLateralVelocity = 0;
			if(rect.y - 50 > b.getRect().y + b.getRect().h)
				jump = true;
		}
		else if (b.getCenter().first + veloScale >= rect.x && b.getCenter().first - veloScale < rect.x) {
			currentLateralVelocity = 0;
		}



		break;

	default:
		break;
	}

	//if he hits the wall
	if (rect.x <= halfway +10) {
		currentLateralVelocity *= -1;
		rect.x = halfway+veloScale;
	}

	//keep him the ball's width away from the back wall
	if (rect.x > (halfway * 2) - 40) {
		rect.x = (halfway * 2) - 40;
	}
}

int Bot::botDifficulty = 1;

void Bot::increaseDifficulty() {
	botDifficulty++;
}


void Bot::render(SDL_Renderer* renderer) {
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, currentAngle, NULL, SDL_FLIP_NONE);
}
