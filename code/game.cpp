/*
Filename: game.cpp

Purpose: Implementation file for functions in game.h

Note: This file is NOT finished.

*/

#include "game.h"

#ifndef GAME_CPP
#define GAME_CPP

//This will record the date of a run for a game.
void Game::recordRunDate(int d, int m, int y)
{
	return;
};

//This will record the time for a run of a game.
//If recordMil is 0, then ms will not be used in the function.
void Game::recordRunTime(int h, int m, int s, int ms)
{
	return;
};

//This will store a singular run.
void Game::storeRun()
{
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
};

#endif // GAME_CPP
