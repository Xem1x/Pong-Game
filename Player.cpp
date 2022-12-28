#include "Player.h"

Player::Player()
{

}
Player::Player(SDL_Renderer* renderer, int number) : m_renderer(renderer), n_player(number)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	player_rect.w = 10;
	player_rect.h = 40;
	if(number == 1)
		player_rect.x = 50;
	else
		player_rect.x = 590;
	player_rect.y = 220;
	SDL_RenderFillRect(m_renderer, &player_rect);
}

Player::Player(Player& p1)
{
	player_rect = p1.player_rect;
	n_player = p1.n_player;
}

void Player::setDest(int y) {
	player_rect.y += y;
}


int Player::GetLeftEdge()
{
	return player_rect.x;
}
int Player::GetRightEdge()
{
	return player_rect.x + player_rect.w;
}
int Player::GetTopEdge()
{
	return player_rect.y;
}
int Player::GetBottomEdge()
{
	return player_rect.y + player_rect.h;
}


void Player::Update()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(m_renderer, &player_rect);
}
void Player::Up()
{
	if (player_rect.y >= 10)
		setDest(-10);
}

void Player::Down()
{
	if (player_rect.y+ player_rect.h <= 470)
		setDest(10);
}
