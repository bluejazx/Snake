#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "variables.hpp"

int Global::width = 80;
int Global::height = 20;

int Global::snakeCordX; 
int Global::snakeCordY;

int Global::fruitCordX; 
int Global::fruitCordY;

int Global::playerScore;

std::vector<int> Global::snakeTailCords{ 100, 100 };

int Global::snakeTailLen;

bool Global::isGameOver;

Global::snakesDirection Global::sDir;