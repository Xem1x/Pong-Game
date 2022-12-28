#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <string>
#include "Player.h"
#include "Ball.h"
#include "Score.h"
#include "Bot.h"
#include <cmath>
using namespace std;


class Game
{
public:
	Game();
	~Game();

	void GameLoop();
	void Update();
	void Input();
	void Render();
	void CheckForCollision();
	void CheckForGoal();
	void Goal(int scorer);
	void CollisionWithPaddle(Player paddle);
	void CollisionWithWall();

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL; 
	const int WIDTH = 640;
	const int HEIGHT = 480;
	bool running;
	int count;
	int frameCoount, timerFPS, lastFrame;
	Player Player1;
	Player Player2;
	Ball ball;
	Bot bot;
	Score Score1;
	Score Score2;
};
#endif // !GAME_H

