#include "GameObject.h"

GameObject::GameObject() {
	
}
GameObject::GameObject(SDL_Rect rect, SDL_Texture* tex) {
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
void GameObject::renderSolidRect(SDL_Renderer* ren, int r,int g,int b,int a) {
	SDL_SetRenderDrawColor(ren, r, g, b, a);
	SDL_RenderFillRect(ren, &body);
}
void GameObject::quit() {

}

SDL_Rect GameObject::getRect() {
	return body;
}