/*
Filename: Speedrun.cpp

Purpose: Main file

Date last worked on (dd-mm-yy): 29-01-20

----How To Run----

To run the file, first clone the directory into your local machine. 
Go to the directory via Terminal or a similar command line interface.
Type "g++ Speednrun.cpp -std=c++11".
After it compiles, type "./a.out" to run the program.

----Notes----

- The file is able to run, but is NOT finished. This file will likely be replaced with a more appropriate one, including its file name.

*/

#include "menu.cpp"

using namespace std;

int main() 
{
	vector<Game> data;
	initialize(data);
	bool exit = false;

	while (exit == false)
	{
		exit = M1_Question(0, data);
	}

	//Step 53
	return 0;
}

/*

----Files that are directly dependent on this file----

----Files this file is dependent on----
- game.cpp
- game.h
- Function.h
- Function.cpp
- Menu.h
- Menu.cpp

*/
