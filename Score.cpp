#include "Score.h"
Score::Score()
{
}
Score::~Score()
{
}

Score::Score(SDL_Renderer* renderer,
	int x_inpt,
	int y_inpt)
	: m_renderer(renderer),
	x_pos(x_inpt),
	y_pos(y_inpt)
{

	TTF_Init();
	font = TTF_OpenFont(font_path.c_str(), font_size);
	CreateTexture();
	Set_Rect();
	Display();
}

void Score::Display() 
{
	SDL_RenderCopy(m_renderer, text_texture, nullptr, &text_rect);
}

void Score::Set_Rect()
{
	text_rect.x = x_pos;
	text_rect.y = y_pos;
}
void Score::Update()
{
	CreateTexture();
	Display();
}
void Score::IncreaseScoreNumber()
{
	score_text = std::to_string(++score_number);
}

void Score::CreateTexture()
{
	loadFont();
	SDL_QueryTexture(text_texture, nullptr, nullptr, &text_rect.w, &text_rect.h);
}
SDL_Texture* Score::loadFont()
{
	
	text_surface = TTF_RenderText_Solid(font, score_text.c_str(), color);
	text_texture = SDL_CreateTextureFromSurface(m_renderer, text_surface);
	SDL_FreeSurface(text_surface);
	return text_texture; 
}
