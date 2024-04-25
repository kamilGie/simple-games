#include "raylib.h"

Color green = Color{38, 185, 154, 255};
Color darkGreen = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color yellow = Color{243, 213, 91, 255};

int pleyer_score = 0;
int cpu_score = 0;

class Ball {
   public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw() {
        DrawCircle(x, y, radius, yellow);
    }

    void Update() {
        x += speed_x;
        y += speed_y;

        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            speed_y *= -1;
        }

        if (x + radius >= GetScreenWidth()) {
            cpu_score++;
            resetBall();
        }

        if (x - radius <= 0) {
            pleyer_score++;
            resetBall();
        }
    }

    void resetBall() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];
    }
};

class Paddle {
   public:
    float x, y;
    float width, height;
    int speed;

    void Draw() {
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
    }

    void Update() {
        if (IsKeyDown(KEY_UP) && y > 0) {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN) && y + height < GetScreenHeight()) {
            y = y + speed;
        }
    }
};

class CpuPaddle : public Paddle {
   public:
    void Update(int ball_y) {
        if (y + height / 2 > ball_y && y > 0) {
            y -= speed;
        }
        if (y + height / 2 <= ball_y && y + height < GetScreenHeight()) {
            y += speed;
        }
    }
};

Ball ball;
Paddle pleyer;
CpuPaddle cpu;

int main() {
    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "niger");
    SetTargetFPS(120);

    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 8;
    ball.speed_y = 8;

    pleyer.width = 25;
    pleyer.height = 120;
    pleyer.x = screen_width - pleyer.width - 10;
    pleyer.y = screen_height / 2 - pleyer.height / 2;
    pleyer.speed = 6;

    cpu.width = 25;
    cpu.height = 120;
    cpu.x = 10;
    cpu.y = screen_height / 2 - pleyer.height / 2;
    cpu.speed = 6;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ball.Update();
        pleyer.Update();
        cpu.Update(ball.y);

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{pleyer.x, pleyer.y, pleyer.width, pleyer.height})) {
            ball.speed_x *= -1;
        }

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})) {
            ball.speed_x *= -1;
        }

        ClearBackground(darkGreen);
        DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, green);
        DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        ball.Draw();
        pleyer.Draw();
        cpu.Draw();

        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", pleyer_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}