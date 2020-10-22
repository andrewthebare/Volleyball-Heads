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
  Player x = Player(playerRect);


  while(true){

	  //handle player movement
	  //if (true) {	//keys
		 // x.moveRight();
		 // cout << "X: " << x.getRect().x;
	  //}


	  //SDL_Event game_event;
	  //SDL_PollEvent(&game_event);

	  //switch (game_event.key.keysym.sym) {
	  //case SDLK_RIGHT:
		 // x.moveRight();
		 // break;
	  //case SDLK_LEFT:
		 // x.moveLeft();
		 // break;
	  //}

	  GE.handleEvents();
	  //do the move
	  cout << x.currentLateralVelocity << endl;
	  x.moveRect();

	
	  //move the car
	  moveRect(rect, -1, 0);
	  moveRect(wheelFront, -1, 0);
	  moveRect(wheelBack, -1, 0);

	  if (rect.x + rect.w < 0) {
		  rect.x = 1500;
		  wheelFront.x = 1550;
		  wheelBack.x = 1760;
	  }


	//SDL_RenderClear(my_renderer);
	SDL_SetRenderDrawColor(my_renderer, 255, 0, 190, 250);
	SDL_RenderClear(my_renderer);


	SDL_SetRenderDrawColor(my_renderer, 100, 250, 190, 250);
	SDL_RenderFillRect(my_renderer, &solidSquare);
	
	SDL_RenderCopy(my_renderer, carTexture, NULL, &rect);

	//increase the angle
	wheelAngle--;
	if (wheelAngle <= 0) {
		wheelAngle = 360;
	}
	SDL_RenderCopyEx(my_renderer, wheelTexture, NULL, &wheelFront, wheelAngle, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(my_renderer, wheelTexture, NULL, &wheelBack, wheelAngle, NULL, SDL_FLIP_NONE);

	//test draw
	SDL_SetRenderDrawColor(my_renderer, 0, 0, 0, 250);
	SDL_RenderFillRect(my_renderer, &playerRect);
	x.render(my_renderer, wheelTexture);


	//SDL_RenderCopy(my_renderer, wheelTexture, NULL, &wheelFront);
	//SDL_RenderCopy(my_renderer, wheelTexture, NULL, &wheelBack);
	SDL_RenderPresent(my_renderer);

  }

  //SDL_DestroyRenderer(my_renderer);
  //SDL_DestroyWindow(my_window);

  //IMG_Quit();
  //SDL_Quit();

  GE.quit();
  
  return 0; 
}

void handleEvents() {
}
