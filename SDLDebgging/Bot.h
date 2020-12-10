#pragma once
#include "Player.h"
#include "Ball.h"
//#include "GameEngine.h"
class Bot :
    public Player
{
private:
    //SDL_Rect rect;
    //SDL_Texture* texture;

    int startX = 800;

    int halfway = 200;

    //int currentAngle = 359;

public:
    Bot();
    Bot(SDL_Rect r, SDL_Texture* tex, int start);
    enum state { idle, defending, reset } botState = idle;

    void updateState(Ball b, int halfway);
    void updateBotMovement(Ball b);

    void render(SDL_Renderer* renderer);

};

