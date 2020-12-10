#include "TextObject.h"

TextObject::TextObject() {

}

TextObject::TextObject(SDL_Rect rect) {
	body = rect;
	Sans = TTF_OpenFont("./Aaargh.ttf", 40);

	if (!Sans)
		std::cout << "FONT NO WORKO\n";

	SDL_Color White = { 255, 255, 255 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "ROFL Volley Heads", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
}

void TextObject::render(SDL_Renderer* ren, int r, int g, int b, std::string message){
	
	surfaceMessage = TTF_RenderText_Solid(Sans, message.c_str(), White);
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);

	int w, h;

	SDL_QueryTexture(Message, NULL, NULL, &w, &h);
	body.w = w;
	body.h = h;

	renderSolidRect(ren, r, g, b, 255);
	SDL_RenderCopy(ren, Message, NULL, &body);

}



