#ifndef BALL_H
#define BALL_H
#include "SDL.h" 
#include <utility>

class Ball
{
public:
    Ball();
    Ball(SDL_Renderer* renderer, int centreX, int centreY, int radius);
	void Fill(std::pair<float, float> point_2);
	void Update();
	void DrawCircle(std::pair<float, float> centre);
	void Move(std::pair<float, float> speed);

	void SetNewSpeed(std::pair<float, float> speed);
	void SetNewCentre(std::pair<float, float> new_centre);
	std::pair<float, float> GetSpeed();
	std::pair<float, float> GetCenter();
	int GetLeftEdge();
	int GetRightEdge();
	int GetTopEdge();
	int GetBottomEdge();	
private:
	std::pair<float, float> centre;
	int m_radius;
	SDL_Renderer* m_renderer;
	SDL_Rect offset;
	std::pair<float, float> current_speed;
};
#endif // !BALL_H

