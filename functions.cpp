#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "functions.hpp"
#include "variables.hpp"

void GameInit() 
{ 
    Global::isGameOver = false; 
    Global::sDir = Global::STOP; 
    Global::snakeCordX = Global::width / 2; 
    Global::snakeCordY = Global::height / 2; 
    Global::fruitCordX = rand() % Global::width; 
    Global::fruitCordY = rand() % Global::height; 
    Global::playerScore = 0; 
}