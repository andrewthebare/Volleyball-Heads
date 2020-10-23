#include "GameObject.h"


GameObject::GameObject(SDL_Rect rect, SDL_Texture* tex) {
	body = rect;
	texture = tex;
}

void GameObject::update() {

}

void GameObject::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &body);
}

void GameObject::quit() {

}