#include "raylib.h"

struct Ball
{
    float x, y;
    float speedX, speedY;
    float radius;

    void Draw()
    {
        DrawCircle((int) x, (int) y, radius, WHITE);
    };
};

struct Paddle
{
    float height;
    float width;
    float posX;
    float posY;
    int speed;
    
    Rectangle GetRect()
    {
        return Rectangle {posX - width / 2, posY - height / 2, width, height};
    };

    void Draw()
    {
        DrawRectangleRec(GetRect(), WHITE);
    };
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
    paddle1.posY = GetScreenHeight() / 2;
    paddle1.speed = 500;

    //Paddle2 Properties
    paddle2.height = 100;
    paddle2.width = 10; 
    paddle2.posX = GetScreenWidth() - 50;
    paddle2.posY = GetScreenHeight() / 2;
    paddle2.speed = 500;
    
    //Ball Properties
    int ballSpeed = 300;
    ball.radius = 5;
    ball.x = GetScreenWidth() / 2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.speedX = ballSpeed;
    ball.speedY = ballSpeed;

    const char* winnerText = nullptr;
    const char* replayText = nullptr;
    
    while (!WindowShouldClose())
    {
        ball.x += ball.speedX * GetFrameTime();
        ball.y += ball.speedY * GetFrameTime();

        //Ball Wall Collision
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

        //Ball Paddle Collision
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{paddle1.GetRect()}))
        {
            if (ball.speedX < 0)
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - paddle1.posY) / (paddle1.height / 2) * ball.speedX;
            };
        };

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{paddle2.GetRect()}))
        {
            if (ball.speedX > 0)
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - paddle2.posY) / (paddle2.height / 2) * -ball.speedX;
            };
        };
        
        //Paddle Controls
        if (IsKeyDown(KEY_W) && paddle1.posY > paddle1.height / 2)
        {
            paddle1.posY -= paddle1.speed * GetFrameTime();
        };
        if (IsKeyDown(KEY_S) && paddle1.posY < GetScreenHeight() - (paddle1.height / 2))
        {
            paddle1.posY += paddle1.speed * GetFrameTime();
        };
        if (IsKeyDown(KEY_UP) && paddle2.posY > paddle2.height / 2)
        {
            paddle2.posY -= paddle2.speed * GetFrameTime();
        };
        if (IsKeyDown(KEY_DOWN) && paddle2.posY < GetScreenHeight() - (paddle2.height / 2))
        {
            paddle2.posY += paddle2.speed * GetFrameTime();
        };

        if (ball.x < 0 + ball.radius)
        {
            winnerText = "Player 2 wins!";
            replayText = "Press Spacebar to Play Again";
        };

        if (ball.x > GetScreenWidth() - ball.radius)
        {
            winnerText = "Player 1 Wins!";
            replayText = "Press Spacebar to Play Again";
        };

        if (winnerText && IsKeyPressed(KEY_SPACE))
        {
            ball.x = GetScreenWidth() / 2;
            ball.y = GetScreenHeight() / 2;
            ball.speedX = ballSpeed;
            ball.speedY = ballSpeed;
            winnerText = nullptr;
        };
        

        BeginDrawing();
            ClearBackground(BLACK);

            ball.Draw();
            paddle1.Draw();
            paddle2.Draw();

            if (winnerText)
            {
                ball.speedX = 0;
                ball.speedY = 0;
                int textWidth = MeasureText(winnerText, 60);
                int replayTextWidth = MeasureText(replayText, 30);
                DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, GOLD);
                DrawText(replayText, GetScreenWidth() / 2 - replayTextWidth / 2, GetScreenHeight() / 2 + 60, 30, RED);
            };            

            DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}