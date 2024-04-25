#pragma once
#include <map>
#include <vector>

#include "colors.hpp"
#include "position.hpp"

class Block {
   public:
    Block();
    void Draw();
    int id;
    std::map<int, std::vector<Position>> cells;

   private:
    int cellSize;
    int rotstionState;
    std::vector<Color> colors;
};