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
        for(int j = 0; j <= Global::width; j++)
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

void UpdateGame()
{
    //Movess the snakes body guided the head along x,y axis
    int prevX = Global::snakeTailX[0];
    int prevY = Global::snakeTailY[0];
    int prev2X, prev2Y;
    Global::snakeTailX[0] = Global::snakeCordX;
    Global::snakeTailY[0] = Global::snakeCordY;

    for (int i = 1; i < Global::snakeTailLen; i++)
    {
        prev2X = Global::snakeTailX[i];
        prev2Y = Global::snakeTailY[i];
        Global::snakeTailX[i] = prevX;
        Global::snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    //Changes player direction based on inputs
    switch(Global::sDir)
    {
        case Global::LEFT:
        {
            Global::snakeCordX--;
            break;
        }
        case Global::RIGHT:
        {
            Global::snakeCordX++;
            break;
        }
        case Global::UP:
        {
            Global::snakeCordY--;
            break;
        }
        case Global::DOWN:
        {
            Global::snakeCordY++;
            break;
        }
    }

    //Checks for snake collision with the wall (|)
    if (Global::snakeCordX >= Global::width || Global::snakeCordX < 0 || Global::snakeCordY > Global::height || Global::snakeCordY < 0)
    {
        Global::isGameOver = true;
    }

    //Checks for collision with the tail (o)
    for (int i = 0; i < Global::snakeTailLen; i++)
    {
        if (Global::snakeTailX[i] == Global::snakeCordX && Global::snakeTailY[i] == Global::snakeCordY)
        {
            Global::isGameOver = true;
        }
    }

    //Checks for snake's collision with the food (#)
    if (Global::snakeCordX == Global::fruitCordX && Global::snakeCordY == Global::fruitCordY)
    {
        Global::playerScore += 10;
        Global::fruitCordX = rand() % Global::width;
        Global::fruitCordY = rand() % Global::height;
        Global::snakeTailLen++;
    }
}

int SetDifficulty()
{
    int dfc, choice; 
    cout << "\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: hard "
            "\nNOTE: if not chosen or pressed any other "
            "key, the difficulty will be automatically set "
            "to medium\nChoose difficulty level: "; 
    cin >> choice;
    switch(choice)
    {
        case 1:
        {    
            dfc = 50;
            break;
        }
        case 2:
        {    
            dfc = 100;
            break;
        }
        case 3:
        {    
            dfc = 100;
            break;
        }
        default:
        {
            dfc = 100;
        }
    }
    return dfc;
}

void UserInput()
{
    //Checks if key has been pressed or not
    if(_kbhit())
    {
        //Gets the key that has been press
        switch(_getch())
        {
            case 'a':
            {
                Global::sDir = Global::LEFT;
                break;
            }
            case 'd':
            {
                Global::sDir = Global::RIGHT;
                break;
            }
             case 'w':
            {
                Global::sDir = Global::UP;
                break;
            }
             case 's':
            {
                Global::sDir = Global::DOWN;
                break;
            }
             case 'x':
            {
                Global::isGameOver = true;
                break;
            }
        }
    }
}