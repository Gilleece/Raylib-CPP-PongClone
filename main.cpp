#include "raylib.h"

struct Ball
{
    float x, y;
    float speedX, speedY;
    float radius;
};

int main()
{
    InitWindow(800, 600, "Ultimate Pong");
    SetWindowState(FLAG_VSYNC_HINT);

    //Create Ball
    Ball ball;
    
    //Object Sizes
    int paddleHeight = 100;
    int paddleWidth = 10;    
    
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
            DrawRectangle(50, (GetScreenHeight() / 2) - (paddleHeight / 2), paddleWidth, paddleHeight, WHITE);
            DrawRectangle(GetScreenWidth() - 50, (GetScreenHeight() / 2) - (paddleHeight / 2), paddleWidth, paddleHeight, WHITE);

            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}