#pragma once
#include <SDL_ttf.h>
#include <string.h>

#include "GameObject.h"
class TextObject:GameObject{
private:
    TTF_Font* Sans;
    SDL_Color White;
    SDL_Surface* surfaceMessage;
    SDL_Texture* Message;
public:
    TextObject();
    TextObject(SDL_Rect rect);
    void render(SDL_Renderer* ren, int r, int g, int b, std::string message);
};

