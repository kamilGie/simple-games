#include <iostream>
#include <raylib.h>
#include "tetrisGame.hpp"
#include "blocks.cpp"

using namespace std;

int main () {

    Color darkBlue= {44,44,127,255};

    InitWindow(300, 600, "program");
    SetTargetFPS(120);

    Grid grid=Grid();
    grid.print();

    LBlock block =LBlock();

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();
}