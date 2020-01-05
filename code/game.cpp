/*
Filename: game.cpp

Purpose: Implementation file for functions in game.h

Note: This file is NOT finished.

*/

#include "game.h"

#ifndef GAME_CPP
#define GAME_CPP


//This will store a singular run.
void Game::storeRun(Run run)
{
	allRuns.push_back(run);
	return;
};

//This will store all runs.
//This function will likely need to use an iostream before continuing.
void Game::storeAllRun()
{
	return;
};

//This will return the average time for the game.
void Game::returnAverage()
{
	return;
};

//This will return the best time for the game.
void Game::returnBest()
{
	return;
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

void Game::convertTime(double ms)
{
	return;
};

// This will clear all information. This is for the sole use of reading from the 
// NOTE: recordMil will NOT be altered.
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
