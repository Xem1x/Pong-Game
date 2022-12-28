#include "Bot.h"

Bot::Bot()
{
}

Bot::~Bot()
{
}

Bot::Bot(Player* player) : loc_player(player)
{
	
}

void Bot::CheckForRadiusPos(std::pair<float, float> center)
{
	if (center.second < (loc_player->GetY() + loc_player->GetH() / 2))
	{
		loc_player->Up();
	}
	else if(center.second > (loc_player->GetY() + loc_player->GetH() / 2))
	{
		loc_player->Down();
	}
}

