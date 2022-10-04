#include "raylib.h"

struct Ball
{
    float x, y;
    float speedX, speedY;
    float radius;
};

struct Paddle
{
    int height;
    int width;
    int posX;
    int posY;
};

int main()
{
    InitWindow(800, 600, "Ultimate Pong");
    SetWindowState(FLAG_VSYNC_HINT);

    //Create Ball
    Ball ball;

    //Create Paddles
    Paddle paddle1;
    Paddle paddle2;
    
    //Paddle1 Properties
    paddle1.height = 100;
    paddle1.width = 10; 
    paddle1.posX = 50;
    paddle1.posY = (GetScreenHeight() / 2) - (paddle1.height / 2);

    //Paddle2 Properties
    paddle2.height = 100;
    paddle2.width = 10; 
    paddle2.posX = GetScreenWidth() - 50;
    paddle2.posY = (GetScreenHeight() / 2) - (paddle2.height / 2);
    
    //Ball Properties
    ball.radius = 5;
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.speedX = 300;
    ball.speedY = 300;
    
    while (!WindowShouldClose())
    {
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        if (ball.y > GetScreenHeight())
        {
            ball.y = GetScreenHeight();
            ball.speedY *= -1;
        };

        if (ball.y < 0)
        {
            ball.y = 0;
            ball.speedY *= -1;
        };

        if (ball.x > GetScreenWidth())
        {
            ball.x = GetScreenWidth();
            ball.speedX *= -1;
        };

        if (ball.x < 0)
        {
            ball.x = 0;
            ball.speedX *= -1;
        };
        

        BeginDrawing();
            ClearBackground(BLACK);

            DrawCircle((int) ball.x, (int) ball.y, ball.radius, WHITE);
            DrawRectangle(paddle1.posX, paddle1.posY, paddle1.width, paddle1.height, WHITE);
            DrawRectangle(paddle2.posX, paddle2.posY, paddle2.width, paddle2.height, WHITE);

            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}