// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>

#include <SDL.h> 
#undef main
#include <SDL_image.h> 
#include <SDL_timer.h>

#include "GameEngine.h"
#include "Player.h"

//Screen dimension
const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 480;

SDL_Window* my_window = NULL;
SDL_Renderer* my_renderer = NULL;
SDL_Event input;

void my_SDL_init(){

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
	std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  my_window = SDL_CreateWindow("my_game", 
				   SDL_WINDOWPOS_CENTERED, 
				   SDL_WINDOWPOS_CENTERED, 
				   SCREEN_WIDTH,
				   SCREEN_HEIGHT, 0);
  my_renderer = SDL_CreateRenderer(my_window,-1,0);

}

void moveRect(SDL_Rect &r, int x, int y) {
	r.x += x;
	r.y += y;
}

int main() 
{ 
	GameEngine GE;

	GE.init();

  //my_SDL_init();

  SDL_Texture* carTexture = NULL;
  SDL_Surface* car = IMG_Load("./car.png");

  carTexture = SDL_CreateTextureFromSurface(GE.my_renderer, car);
  SDL_FreeSurface(car);

  SDL_Texture* wheelTexture = NULL;
  SDL_Surface* wheel = IMG_Load("./carwheel.png");

  wheelTexture = SDL_CreateTextureFromSurface(GE.my_renderer, wheel);
  SDL_FreeSurface(wheel);


  SDL_Rect rect;
  rect.x = 1500;
  rect.y = 280;
  rect.w = 370;
  rect.h = 120;

  SDL_Rect solidSquare;
  solidSquare.x = 0;
  solidSquare.y = 420;
  solidSquare.w = SCREEN_WIDTH;
  solidSquare.h = 60;

  SDL_Rect wheelFront;
  wheelFront.x = 1550;
  wheelFront.y = 340;
  wheelFront.w = 60;
  wheelFront.h = 60;

  SDL_Rect wheelBack;
  wheelBack.x = 1760;
  wheelBack.y = 340;
  wheelBack.w = 60;
  wheelBack.h = 60;

  int wheelAngle = 359;

  //Stuff
  SDL_Rect playerRect;
  playerRect.x = 30;
  playerRect.y = 30;
  playerRect.w = 50;
  playerRect.h = 50;
  Player x = Player(playerRect, wheelTexture);

  GE.registerPlayers();

  while(true){


	  GE.handleEvents();

	  GE.updateMechanics();

	
	  GE.render();


  }

  GE.quit();
  
  return 0; 
}
