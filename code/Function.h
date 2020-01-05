/*
Filename: Function.h

Purpose: Header file for all misc. functions that are required in Speedrun.cpp

Note: This file is NOT finished.

*/

#ifndef FUNCTION_H
#define FUNCTION_H

#include "game.cpp"

//This function is a temporary measure to ensure that the getline records the name properly
bool isName(string str);

//This function is a temporary measure to ensure that the getline records the millisecond properly
bool isMil(string str);

//Step 0, Step 1, Step 2
void initialize(vector <Game> game);

#endif // FUNCTION_H
