#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "SDL.h"
#include "SDL_rect.h"
class Player
{
public:
	Player();
	Player(SDL_Renderer* renderer, int number);
	Player(Player& p1);
	
	void setDest(int x);
	int GetX() const { return player_rect.x; }
	int GetY() const { return player_rect.y; }
	int GetW() const { return player_rect.w; }
	int GetH() const { return player_rect.h; }
	int GetLeftEdge();
	int GetRightEdge();
	int GetTopEdge();
	int GetBottomEdge();
	SDL_Rect getDest() const { return player_rect; }

	void Update();
	void Up();
	void Down();

protected:
	SDL_Renderer* m_renderer;
	SDL_Rect player_rect;
	int n_player;
	



};
#endif // !PLAYER_H

