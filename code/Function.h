/*
Filename: Function.h

Purpose: Header file for all misc. functions that are required in Speedrun.cpp

Date last worked on (dd-mm-yy): 29-01-20

----Notes----

- The file is able to run. It is close to completion, but at this point, optimizations are still possible.

----Notable Bugs / Optimizations----

- [YUIO] Any function with this tag will likely be unncessary later in development, as an executable program will likely not use command line entry

*/

#ifndef FUNCTION_H
#define FUNCTION_H

#include "game.cpp"

bool isDateValid(string str);
bool isMilStored(string str);
bool isName(string str);
bool isNumber(string str);
bool isTimeValid(string str, bool mil);
bool YN_Answer (string str);									// [YUIO] Step 13a, Step 5, Step 25

Time convertTime(long double totalMilliseconds, bool mil);
Time stringToTime(string str, bool mil);

Date getToday();
Date stringToDate(string str);

int loadGame(string str, vector <Game> data);				// Step 29, Step 6
int stringToInt (string str);

Run timer(bool mil, Game game);								// Step 7, Step 8
Run userCreateRun(bool mil, Game &game);						// Step 26

void initialize(vector <Game> &data);						// Step 0, Step 1, Step 2
void listGame(vector <Game> data);

string stringInterpreter (string str);						// [YUIO]

Game createGame ();											//Step 5, Step 25

vector <int> chronologicalOrder (vector <int> number);


#endif // FUNCTION_H

/*

----Files that are directly dependent on this file----
- Function.cpp

----Files this file is dependent on----
- game.cpp
- game.h

*/
