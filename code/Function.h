/*
Filename: Function.h

Purpose: Header file for all misc. functions that are required in Speedrun.cpp

Date last worked on (dd-mm-yy): 06-01-20

----Notes----

- The file is able to run, but is NOT finished.
- A good number of functions (primarily the ones involving string manipulation) in this file will be obsolete much later in the development cycle, when running the program no longer requires Terminal. A good example is stringInterpreter

*/

#ifndef FUNCTION_H
#define FUNCTION_H

#include "game.cpp"

bool isName(string str);
bool isMil(string str);

//Step 0, Step 1, Step 2
void initialize(vector <Game> &data);

//Step 22, Step 13
bool isVectorEmpty (vector <Game> data);

//Step 13a, Step 5, Step 25
bool YN_Answer (string str);

string stringInterpreter (string str);

//Step 5, Step 25
Game createGame ();

//Step 26
void userCreateRun();

bool isRunValid(string str, bool mil);
bool isDateValid(string str);
Time stringToTime(string str, bool mil);
Date stringToDate(string str);

int loadGame(string str, vector <Game> data);

void listGame(vector <Game> data);

#endif // FUNCTION_H

/*

----Files that are directly dependent on this file----
- Function.cpp

----Files this file is dependent on----
- game.cpp
- game.h

*/
