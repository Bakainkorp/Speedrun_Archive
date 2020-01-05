/*
Filename: menu.h

Purpose: Header file for enums of the menus and associated menuing functions

----Notes----

- The file is able to run, but is NOT finished.
- A good number of functions (primarily the ones involving string manipulation) in this file will be obsolete much later in the development cycle, when running the program no longer requires Terminal.

*/

#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

string stringInterpreter (string str);

/*
	"Welcome to your personal speedrun archive!"
	"What would you like to do?"
*/
/*
	1. [T]ime New Runs
	2. [V]iew Saved Data
	3. [E]dit Previous Runs
	4. E[X]it Program
*/
enum Menu1
{
	M1_TIME,
	M1_VIEW,
	M1_EDIT,
	M1_EXIT,
	M1_FAIL
};
Menu1 M1_Answer (string str);
bool M1_Question(bool repeat);


#endif // MENU_H

/*

----Files that are directly dependent on this file----
- menu.cpp

----Files this file is dependent on----

*/
