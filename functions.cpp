#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "functions.hpp"
#include "variables.hpp"

using namespace std;


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

void GameRender(string playerName)
{
    //Clears the console
    system("cls");

    //Creates the top walls with '-'
    for(int i = 0; i < Global::width + 2; i++)
    {
        cout << "-";
    }
    cout << endl;

    //Creates walls, snakehead, and food
    for(int i = 0; i < Global::height; i++)
    {
        for(int j = 0; j<= Global::width; j++)
        {
            //Creates the side walls 
            if(j == 0 || j == Global::width)
            {
                cout << "|";
            }
            //Creates snakes head with 'O'
            if (i == Global::snakeCordY && Global::snakeCordX)
            {
                cout << "O";
            }
            //Creates the snakes food with '#'
            else if (i == Global::fruitCordY && j == Global::fruitCordX)
            {
                cout << "#";
            }
            //Cretaes snake's head with 'O'
            else
            {
                bool prTail = false;
                for(int k = 0; k < Global::snakeTailLen; k++)
                {
                    if(Global::snakeTailX[k] == j && Global::snakeTailY[k] == i)
                    {
                        cout << "o";
                        prTail = true;
                    }
                }
                if(!prTail)
                {
                    cout << " "; 
                }
            }
            
        }
        cout << endl;
    }

    //Creates bottom walls with '-'
    for(int i = 0; i < Global::width + 2; i++)
    {
        cout << "-";
    }
    cout << endl;
     
    //Displays players score 

    cout << playerName << "'s Score: " << Global::playerScore << endl;
}