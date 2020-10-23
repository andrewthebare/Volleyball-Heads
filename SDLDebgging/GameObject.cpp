#include "GameObject.h"

GameObject::GameObject() {
	
}
GameObject::GameObject(SDL_Rect &rect, SDL_Texture* tex) {
	body = rect;
	texture = tex;
	check = 1;
}


void GameObject::update() {

}

void GameObject::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &body);
	std::cout <<"Check: " << check;
}

void GameObject::quit() {

}