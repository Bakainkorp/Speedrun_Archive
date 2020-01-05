/*
Filename: Function.h

Purpose: Header file for all misc. functions that are required in Speedrun.cpp

----Notes----

- The file is able to run, but is NOT finished.

*/

#ifndef FUNCTION_H
#define FUNCTION_H

#include "game.cpp"

bool isName(string str);
bool isMil(string str);

//Step 0, Step 1, Step 2
void initialize(vector <Game> game);

#endif // FUNCTION_H

/*

----Files that are directly dependent on this file----
- Function.cpp

----Files this file is dependent on----
- game.cpp
- game.h

*/
