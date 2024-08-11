#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "functions.hpp"
#include "variables.hpp"

using namespace std;


int main()
{
    cout << "Snake";
    string playerName;
    cout << "enter your name: ";
    cin >> playerName;
    int dfc = SetDifficulty();

    GameInit();
    while (!Global::isGameOver)
    {
        GameRender(playerName);
        UserInput();
        UpdateGame();
        //Creates delay for the choosen difficulty
        Sleep(dfc);
    }
}
