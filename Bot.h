#pragma once
#ifndef BOT_H
#define BOT_H
#include <SDL.h>
#include <utility>
#include "Player.h"
class Bot
{
public:
	Bot();
	Bot(Player* player); 
	~Bot();

	void CheckForRadiusPos(std::pair<float, float> center);

private:
	Player* loc_player;
};
#endif

