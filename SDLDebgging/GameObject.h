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
	int check = 0;
	GameObject();
	GameObject(SDL_Rect rect, SDL_Texture* tex);

	void update();

	void render(SDL_Renderer* renderer);
	void renderSolidRect(SDL_Renderer* ren, int r, int g, int b, int a);
	void quit();

	SDL_Rect getRect();
};

