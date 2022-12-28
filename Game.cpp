#include "Game.h"

Game::Game()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    running = true;
    Player1 = Player(renderer, 1);
    Player2 = Player(renderer, 2);
    bot = Bot(&Player2);
    ball = Ball(renderer, 320, 240, 7);
    Score1 = Score(renderer, 300, 40);
    Score2 = Score(renderer, 340, 40);
    GameLoop();
    
    
}

Game::~Game()
{
    running = false;
    delete& Player1;
    delete& Player2;
    delete& bot;
    delete& ball;
    delete& Score1;
    delete& Score2;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    
}

void Game::GameLoop()
{
    while (running)
    {
        lastFrame = SDL_GetTicks();
        static int lastTime;
        if (lastFrame >= (lastTime + 1000))
        {
            lastTime = lastFrame;
            frameCoount = 0;
            count++;
        }


        
        Render();
        Input();
        CheckForCollision();
        
        Update();
        CheckForGoal();

    }
}

void Game::Update()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    Player1.Update();
    Player2.Update();
    Score1.Update();
    Score2.Update();
    ball.Update();
    bot.CheckForRadiusPos(ball.GetCenter());
    
}

void Game::Input()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {

        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_w) Player1.Up();
            if (e.key.keysym.sym == SDLK_s) Player1.Down();

        }
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_UP) Player2.Up();
            if (e.key.keysym.sym == SDLK_DOWN) Player2.Down();
        }
    }
}

void Game::Render()
{
    
    frameCoount++;
    int frameFPS = SDL_GetTicks() * lastFrame;
    if (timerFPS < (1000 / 60))
    {
        SDL_Delay((1000 / 600) * timerFPS);
    }
    
    SDL_RenderPresent(renderer);
}

void Game::CheckForCollision()
{
    if (ball.GetLeftEdge() >= Player1.GetLeftEdge() &&
        ball.GetLeftEdge() <= Player1.GetRightEdge()
        )
    {
        if (ball.GetTopEdge() < Player1.GetBottomEdge() &&
            ball.GetBottomEdge() > Player1.GetTopEdge())
        {
            CollisionWithPaddle(Player1);

        }
    }
    else
        if (ball.GetRightEdge() <= Player2.GetRightEdge() &&
        ball.GetRightEdge() >= Player2.GetLeftEdge())
        {
            if (ball.GetTopEdge() < Player2.GetBottomEdge() &&
            ball.GetBottomEdge() > Player2.GetTopEdge())
            {
                CollisionWithPaddle(Player2);

            } 
        }
    if (ball.GetTopEdge() <= 0 || ball.GetBottomEdge() >=480)
    {
        CollisionWithWall();
    }
}
void Game::CheckForGoal()
{
    if (ball.GetLeftEdge() <= Player1.GetLeftEdge())
    {
        Goal(1);
    }
    else if (ball.GetRightEdge() >= Player2.GetRightEdge())
    {
        Goal(2);
    }
}

void Game::Goal(int scorer)
{
    switch (scorer)
    {
    case 1:
        Score1.IncreaseScoreNumber();
        break;
    case 2:
        Score2.IncreaseScoreNumber();
        break;
    }



    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    ball.DrawCircle(ball.GetCenter());
    ball.SetNewCentre({ 320,240 });
    
}

void Game::CollisionWithPaddle(Player paddle)
{
    float relativeIntersectY = (paddle.GetY() + (paddle.GetH() / 2))
        - ball.GetCenter().second;
    float normalizedRelativeIntersectionY = (relativeIntersectY / (paddle.GetH() / 2));
    float MaxAngle = 75 * 3.14159 / 180;
    float bounceAngle = normalizedRelativeIntersectionY * MaxAngle;
    float ballVx = 2 * cos(bounceAngle);
    float ballVy = 2 * - sin(bounceAngle);

    if (ball.GetSpeed().first < 0)
        ball.SetNewSpeed({ ballVx, ballVy });
    else
        ball.SetNewSpeed({ -ballVx, ballVy });
}

void Game::CollisionWithWall()
{
    std::pair<float, float> newspeed;
    newspeed.first = ball.GetSpeed().first;
    newspeed.second = -ball.GetSpeed().second;
    ball.SetNewSpeed(newspeed);
}
