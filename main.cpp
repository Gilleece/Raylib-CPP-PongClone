#include "raylib.h"
//25:27
int main()
{
    InitWindow(800, 600, "Ultimate Pong");
    SetWindowState(FLAG_VSYNC_HINT);
    
    //Object Sizes
    int paddleHeight = 100;
    int paddleWidth = 10;
    float ballSize = 5;
    
    //Object Positions
    float ballX = GetScreenWidth() / 2.0f;
    float ballY = GetScreenHeight() / 2.0f;

    //Ball Speed
    float ballSpeedX = 300;
    float ballSpeedY = 300;
    
    while (!WindowShouldClose())
    {
        ballX += ballSpeedX * GetFrameTime();
        ballY += ballSpeedY * GetFrameTime();

        BeginDrawing();
            ClearBackground(BLACK);

            DrawCircle((int) ballX, (int) ballY, ballSize, WHITE);
            DrawRectangle(50, (GetScreenHeight() / 2) - (paddleHeight / 2), paddleWidth, paddleHeight, WHITE);
            DrawRectangle(GetScreenWidth() - 50, (GetScreenHeight() / 2) - (paddleHeight / 2), paddleWidth, paddleHeight, WHITE);

            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}