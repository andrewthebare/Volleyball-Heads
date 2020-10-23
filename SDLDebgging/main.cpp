// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>

#include <SDL.h> 
#undef main
#include <SDL_image.h> 
#include <SDL_timer.h>

#include "GameEngine.h"
#include "Player.h"
//#include "GameEngine.cpp"
//#include "Player.cpp"
//#include "GameObject.cpp"

int main() 
{ 
	GameEngine GE = GameEngine();

	GE.init();


  GE.registerPlayers();



  while(true){


	  GE.handleEvents();

	  GE.updateMechanics();

	  GE.render();

  }

  GE.quit();
  
  return 0; 
}
