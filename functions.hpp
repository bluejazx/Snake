#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;


//Function for intializing the game variables
void GameInit();

//Function for creating the game board & rendering
void GameRender(string playerName);

//Function for updating the game state
void UpdateGame();

//Function for setting the gmaes difficulty
int SetDifficulty();

//Function for taking user input, and input handiling
void UserInput();