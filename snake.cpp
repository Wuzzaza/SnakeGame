#include "snake.h"

Snake::Snake()
{
    direction = LEFT;
    for (int i =0; i < 4; i++){
        cellList.append(Cell(8 + i, 10));

    }

}

void Snake::move()
{
    cellList.prepend(nextCell());
    cellList.removeLast();
    checkBorders();
}

void Snake::checkBorders()
{
    for(int i = 0; i < cellList.size(); i++){
        if (cellList[i].x < 0) cellList[i].x = 19;
        if (cellList[i].y < 0) cellList[i].y = 19;
        if (cellList[i].x > 19) cellList[i].x = 0;
        if (cellList[i].y > 19) cellList[i].y = 0;
    }
}

bool Snake::eat(Apple * apple)
{
    if (nextCell().x == apple->x && nextCell().y == apple->y){
        cellList.prepend(nextCell());
        checkBorders();
        return true;
    }
    return false;

}

bool Snake::checkCollisions()
{
    for(int i = 0; i < cellList.size(); i++){
        if (nextCell().x == cellList[i].x
         && nextCell().y == cellList[i].y) return true;
    }
    return false;
}

Snake::Cell Snake::nextCell()
{
    switch (direction) {
    case LEFT:
         return Cell(cellList.first().x - 1, cellList.first().y);

    case TOP:
         return Cell(cellList.first().x, cellList.first().y - 1);

    case RIGHT:
         return Cell(cellList.first().x + 1, cellList.first().y);


    case DOWN:
         return Cell(cellList.first().x, cellList.first().y + 1);

    }
}
