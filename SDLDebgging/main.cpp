
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

  int lastTime = 0;

  while(GE.gameGo){


	//fps stuff -- I could put this all into the GE classmbut I'm kinda busy
	GE.fpsCounter++;
	int startTime = SDL_GetTicks();
	if (!GE.winnerFound) {

		if (!GE.startScreen) {

			GE.handleEvents();

			GE.updateMechanics();

			GE.render();
		}
		else {
			GE.startScreenFunc();
		}

	}
	else {
		GE.winnerScreen();

	}
	if (startTime >= lastTime + 1000) {
		lastTime = startTime;
		GE.fpsCounter = 0;
	}

	int frameDuration = SDL_GetTicks() - startTime;

	if (frameDuration < GameEngine::FRAMEDURATION) {
		SDL_Delay(GameEngine::FRAMEDURATION - frameDuration);
	}
	  
  }

  GE.quit();
  
  return 0; 
}
