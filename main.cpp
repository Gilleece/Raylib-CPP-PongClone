#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Ultimate Pong");
    SetWindowState(FLAG_VSYNC_HINT);
    
    //Object Sizes
    int paddleHeight = 100;
    int paddleWidth = 10;
    int ballSize = 10;
    
    //Object Positions
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);

            DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, ballSize, WHITE);
            DrawRectangle(50, (GetScreenHeight() / 2) - (paddleHeight / 2), paddleWidth, paddleHeight, WHITE);
            DrawRectangle(GetScreenWidth() - 50, (GetScreenHeight() / 2) - (paddleHeight / 2), paddleWidth, paddleHeight, WHITE);

            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}