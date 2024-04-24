#include "raylib.h"

int main() {

    InitWindow(800, 800, "niger");
    SetTargetFPS(120);

    float xCordinate=400;
    float yCordinate=400;
    while (!WindowShouldClose()) {

        if(IsKeyDown(KEY_RIGHT)){
            xCordinate+=10;
        }
        if(IsKeyDown(KEY_LEFT)){
            xCordinate-=10;
        }
        if(IsKeyDown(KEY_UP)){
            yCordinate-=10;
        }
         if(IsKeyDown(KEY_DOWN)){
            yCordinate+=10;
        }
        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(xCordinate,yCordinate,20,BLACK);
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}