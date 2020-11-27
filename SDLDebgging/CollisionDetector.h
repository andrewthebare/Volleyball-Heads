#pragma once

#include <iostream>
#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

#include "Player.h"
#include "GameObject.h"

class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();

	double CalculateAngle(pair<int,int> centerA, pair<int, int> centerB);

	bool RectangleCollision(SDL_Rect rectA, SDL_Rect rectB);
	bool CircleCollission(SDL_Rect rectA, SDL_Rect rectB);
};

