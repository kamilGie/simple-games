#include "tetrisGame.hpp"
#include <iostream>
#include "colors.hpp"

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    initialize();
    colors = getCellColors();
}

void Grid::initialize() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            grid[row][column] = 0;
        }
    }
}

void Grid::print() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() {

        for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            int cellValue = grid[row][column];
            DrawRectangle(column*cellSize+1,row*cellSize+1,cellSize-1,cellSize-1,colors[cellValue]);
        }
    }

}
