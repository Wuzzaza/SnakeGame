#ifndef SNAKE_H
#define SNAKE_H
#include <QList>
#include "apple.h"

enum Directions {LEFT, TOP, RIGHT, DOWN};

class Snake
{
public:
    struct Cell{
        int x, y;

        Cell(int x, int y){
            this->x = x;
            this->y = y;
        }
    };


public:
    Snake();

    QList <Cell> cellList;
    Directions direction;

    void move();
    void checkBorders();
    bool eat(Apple*);
    bool checkCollisions();

    Cell nextCell();

};

#endif // SNAKE_H
