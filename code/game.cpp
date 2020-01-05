/*
Filename: game.cpp

Purpose: Implementation file for functions in game.h

----Notes----

- The file is able to run, but is NOT finished.

*/

#include "game.h"

#ifndef GAME_CPP
#define GAME_CPP

//This returns the name of a game
string Game::returnGameName()
{
	return gameName;
};

//This returns the number of runs stored for a game
int Game::returnRunCount ()
{
	return allRuns.size();
};

//This will clear the run with the specified number attached to it.
void Game::clearRun(int number)
{
	return;
};

//This will store a singular run.
void Game::storeRun(Run run)
{
	allRuns.push_back(run);
	return;
};

//This will store all runs.
//The current implementation is in Function.cpp, under Initialize.
void Game::storeAllRun()
{
	return;
};

//This will return the average time for the game.
Run Game::returnAverage()
{
	Run fake;
	return fake;
};

//This will return the best time for the game.
Run Game::returnBest()
{
	Run fake;
	return fake;
};

//This will return whether the game uses milliseconds (1) or seconds (0).
bool Game::returnRecordMil ()
{
	return recordMil;
};

// This will change the name of the game.
void Game::recordName(string name)
{
	gameName = name;
	return;
};

// This will determine if the game will record milliseconds (1) or not (0).
void Game::isRecordMil(bool ans)
{
	recordMil = ans;
	return;
};

// This will be used for recording, as the time checking function may only count the number of milliseconds
void Game::convertTime(double ms)
{
	return;
};

// This will clear all information. This is for the sole use of reading from the 
// NOTE: recordMil may be altered. The 
void Game::clearAll()
{
	gameName = "";
	while (allRuns.size() > 0)
	{
		allRuns.pop_back();
	}
	
	return;
}

#endif // GAME_CPP

/*

----Files that are directly dependent on this file----
- Function.h

----Files this file is dependent on----
- game.h

*/
