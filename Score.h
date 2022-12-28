#ifndef SCORE_H
#define SCORE_H
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_error.h>
class Score
{
public:
	Score();
	~Score();
	Score(SDL_Renderer* renderer, int x_inpt, int y_inpt);
	void Display();
	void Set_Rect();
	void Update();
	void IncreaseScoreNumber();
	void CreateTexture();
		
	SDL_Texture* loadFont();
private:
	TTF_Font* font;
	SDL_Texture* text_texture = nullptr;
	SDL_Rect text_rect;
	SDL_Renderer* m_renderer;
	SDL_Color color= { 255,255,255,255 };
	SDL_Surface* text_surface;

	std::string score_text = "0";
	std::string font_path = "resources/arial.ttf";
	int score_number = 0;
	int font_size = 30;
	int x_pos;
	int y_pos;
};
#endif //!SCORE_H

