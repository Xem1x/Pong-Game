#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(SDL_Renderer* renderer,
    int centreX,
    int centreY,
    int radius)
    : m_renderer(renderer),
    centre(centreX,centreY),
    m_radius(radius)
{
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    DrawCircle(centre);
    current_speed = { -3,1 };
}

void Ball::Fill(std::pair<float, float> point_2)
{ 
    if (point_2.first >= centre.first && point_2.second >= centre.second)
    {
        for (int x = centre.first; x <= point_2.first; x++)
        {
            for (int y = centre.second; y <= point_2.second; y++)
            {
                SDL_RenderDrawPoint(m_renderer, x, y);
            }
        }
    }
    else if(point_2.first >= centre.first && point_2.second <= centre.second)
    {
        for (int x = centre.first; x <= point_2.first; x++)
        {
            for (int y = centre.second; y >= point_2.second; y--)
            {
                SDL_RenderDrawPoint(m_renderer, x, y);
            }
        }
    }
    else if (point_2.first <= centre.first && point_2.second >= centre.second)
    {
        for (int x = centre.first; x >= point_2.first; x--)
        {
            for (int y = centre.second; y <= point_2.second; y++)
            {
                SDL_RenderDrawPoint(m_renderer, x, y);
            }
        }
    }
    else if (point_2.first <= centre.first && point_2.second <= centre.second)
    {
        for (int x = centre.first; x >= point_2.first; x--)
        {
            for (int y = centre.second; y >= point_2.second; y--)
            {
                SDL_RenderDrawPoint(m_renderer, x, y);
            }
        }
    }


}

void Ball::Update()
{
    Move(current_speed);
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    DrawCircle(centre);
}

void Ball::DrawCircle(std::pair<float, float> centre)
{
    int centreX = centre.first;
    int centreY = centre.second;
    const int diameter = (m_radius * 2);

    int x = (m_radius - 1);
    int y = 0;
    int dx = 1;
    int dy = 1;
    int error = (dx - diameter);

    while (x >= y)
    {
        
        Fill(std::pair<float, float> {centreX + x, centreY - y});

        Fill(std::pair<float, float> {centreX + x, centreY + y});

        Fill(std::pair<float, float> {centreX - x, centreY - y});

        Fill(std::pair<float, float> {centreX - x, centreY + y});

        Fill(std::pair<float, float> {centreX + y, centreY - x});

        Fill(std::pair<float, float> {centreX + y, centreY + x});

        Fill(std::pair<float, float> {centreX - y, centreY - x});

        Fill(std::pair<float, float> {centreX - y, centreY + x});


        if (error <= 0)
        {
            ++y;
            error += dy;
            dy += 2;
        }

        if (error > 0)
        {
            --x;
            dx += 2;
            error += (dx - diameter);
        }

    }
}

void Ball::Move(std::pair<float, float> speed)
{   
    centre.first += speed.first;
    centre.second += speed.second;
}

void Ball::SetNewSpeed(std::pair<float, float> speed)
{
    current_speed.first = speed.first;
    current_speed.second = speed.second;
}

void Ball::SetNewCentre(std::pair<float, float> new_centre)
{
    centre = new_centre;
}

std::pair<float, float> Ball::GetSpeed()
{
    return current_speed;
}


std::pair<float, float> Ball::GetCenter()
{
    return centre;
}

int Ball::GetLeftEdge()
{
    return centre.first-m_radius;
}

int Ball::GetRightEdge()
{
    return centre.first + m_radius;
}

int Ball::GetTopEdge()
{
    return centre.second - m_radius;
}

int Ball::GetBottomEdge()
{
    return centre.second + m_radius;
}
