#pragma once
#include <iostream>
#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>


class GameObject
{
private:
	SDL_Rect body;
	SDL_Texture* texture;

public:
	GameObject(SDL_Rect rect, SDL_Texture* tex);

	void update();

	void render(SDL_Renderer* renderer);

	void quit();

};
