#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

//wraps all global variable in a struct to be used throught entire program
struct Global
{
    //Controls the height and width of the boundaries
    static int width;
    static int height;

    //Coordinates of the snake head x and y axis
    static int snakeCordX; 
    static int snakeCordY;

    //Food coordinates
    static int fruitCordX; 
    static int fruitCordY;

    //Tracks the playes score
    static int playerScore;

    //Tracks the cordinates of the snakes tail
    static std::vector<int> snakeTailCords;

    //Tracks the snakes tail legnth
    static int snakeTailLen;

    //Stores the snake's direction while moving
    enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

    //Stores snake's directrion
    static snakesDirection sDir;

    //checks wether or not the game is over
    static bool isGameOver;
};
