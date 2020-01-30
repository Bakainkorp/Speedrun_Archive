/*
Filename: game.cpp

Purpose: Implementation file for functions in game.h

Date last worked on (dd-mm-yy): 29-01-20

----Notes----

- The file is able to run. It is close to completion, but at this point, optimizations are still possible.

----Notable Bugs / Optimizations----

- [WERT] These may need to be in the Function.cpp, as it is not dependent on the class itself
- [RTYU] smallUnit should be able to handle exceedingly large numbers, but a system may need to be in place just in case this value exceeds its max
- [TYUI] This function saves space, but is quite wasteful in terms of time, especially for a large quanitity of runs using milliseconds. This can be optimized to be faster.

*/

#include "game.h"

#ifndef GAME_CPP
#define GAME_CPP

//////////////////////////////////////////////---------Void functions---------//////////////////////////////////////////////

// This will clear all information. This is for clearing information from reading from Saved.txt, as well as deleting Nodes
void Game::clearAll()
{
	gameName = "";
	while (allRuns.size() > 0)
	{
		allRuns.pop_back();
	}
	recordMil = new bool;
	
	return;
};

//This will clear the run(s) with the specified number(s) attached to it.
void Game::clearRun(vector <int> toDelete)
{
	int count = 0;
	Run dummy;

	while (count != (toDelete.size() - 1))
	{
		for (int xcv = toDelete [count]; xcv < (allRuns.size() - 1); xcv++)
		{
			allRuns [xcv] = allRuns [xcv + 1];
		}
		for (int cvb = 0; cvb < (allRuns.size() - 1); cvb++)
		{
			dummy = allRuns [cvb];
			if (dummy.number >= toDelete [count])
			{
				dummy.number--;
			}
		}
		count++;
		allRuns.pop_back();
	}	

	return;
};

// This will determine if the game will record milliseconds (1) or not (0).
void Game::isMil(bool ans)
{
	recordMil = ans;
	return;
};

// This will list out all runs, in chronological order within the vector
void Game::listAllRuns()
{
	if (allRuns.size() == 0)
	{
		cout << "You don't have any runs for " << gameName << "!" << endl;
		return;
	}

	Run dummy;

	cout << "---- These are all your stored runs for " << gameName << "----" << endl;
	for (int jkl = 0; jkl <= (allRuns.size() - 1); jkl++)
	{
		cout << "Run " << (jkl + 1) << " - ";
		printRun(allRuns [jkl]);
	}

	cout << "_______" << endl;

	cout << "Best run - ";
	printRun (returnBest());

	cout << "Average time - ";
	printTime (returnAverage());
	cout << endl;
	return;
};

// This will print out the date for a run
// [WERT]
void Game::printDate(Date dummy)
{
	if (dummy.day < 10)
	{
		cout << "0";
	}
	cout << dummy.day << "-";
	if (dummy.month < 10)
	{
		cout << "0";
	}
	cout << dummy.month << "-" << dummy.year;
	return;
};

// This will print the enitre run's information
// [WERT]
void Game::printRun(Run dummy)
{
	printTime(dummy.runTime);

	cout << " on ";

	printDate (dummy.runDate);
	cout << endl;
	return;
};

// This will print the time of what is given
// [WERT]
void Game::printTime (Time dummy)
{
	cout << dummy.hour << ":";
	if (dummy.minute < 10)
	{
		cout << "0";
	}
	cout << dummy.minute << ":";
	if (dummy.second < 10)
	{
		cout << "0";
	}
	cout << dummy.second;
	if (recordMil == 1)
	{
		cout << ":";
		if (dummy.millisecond < 100)
		{
			cout << "0";
		}
		if (dummy.millisecond < 10)
		{
			cout << "0";
		}
		cout << dummy.millisecond;
	}
	return;
};

// This will change the name of the game.
void Game::recordName(string name)
{
	gameName = name;
	return;
};

//This will replace an existing run.
void Game::replaceRun(int runNum, Run dummy)
{
	allRuns [runNum] = dummy;
	return;
};

//This will store a singular run.
void Game::storeRun(Run run)
{
	allRuns.push_back(run);
	return;
};

//////////////////////////////////////////////---------Run functions---------//////////////////////////////////////////////

//This will return the best time for the game.
Run Game::returnBest()
{
	Run best = allRuns [0];

	if (allRuns.size() == 1)
	{
		return best;
	}

	Run compare;

	Time bestTime = best.runTime;
	Time compareTime;

	for (int hjk = 1; hjk <= (allRuns.size() - 1); hjk++)
	{
		compare = allRuns [hjk];
		compareTime = compare.runTime;
		if (bestTime.hour > compareTime.hour)
		{
			best = compare;
			bestTime = compareTime;
		}
		else if (bestTime.hour == compareTime.hour)
		{
			if (bestTime.minute > compareTime.minute)
			{
				best = compare;
				bestTime = compareTime;
			}
			else if (bestTime.minute == compareTime.minute)
			{
				if (bestTime.second > compareTime.second)
				{
					best = compare;
					bestTime = compareTime;
				}
				else if (bestTime.second == compareTime.second)
				{
					if (recordMil == 1)
					{
						if (bestTime.millisecond > compareTime.millisecond)
						{
							best = compare;
							bestTime = compareTime;
						}
					}
				}
			}
		}
	}

	return best;
};

// This will return the run designated by the number given.
Run Game::returnRun(int runNum)
{
	return allRuns [runNum];
};

//////////////////////////////////////////////---------Bool functions---------//////////////////////////////////////////////

//This returns if the game has any runs stored
bool Game::isEmpty()
{
	return (allRuns.size() == 0);
};

//This will return whether the game uses milliseconds (1) or seconds (0).
bool Game::returnMil ()
{
	return recordMil;
};

//////////////////////////////////////////////---------Time functions---------//////////////////////////////////////////////

//This will return the average time for the game.
Time Game::returnAverage()
{
	// [RTYU]
	long double smallUnit = 0;
	Run dummyRun;
	for (int ghj = 0; ghj <= (returnRunCount() - 1); ghj++)
	{
		dummyRun = allRuns [ghj];
		if (recordMil == 1)
		{
			smallUnit = smallUnit + dummyRun.runTime.millisecond;
			smallUnit = smallUnit + (dummyRun.runTime.second * 1000);
			smallUnit = smallUnit + (dummyRun.runTime.minute * 60000);
			smallUnit = smallUnit + (dummyRun.runTime.hour * 3600000);
		}
		else
		{
			smallUnit = smallUnit + dummyRun.runTime.second;
			smallUnit = smallUnit + (dummyRun.runTime.minute * 60);
			smallUnit = smallUnit + (dummyRun.runTime.hour * 3600);
		}
	}

	// Units may be lost here, but ultimately won't matter
	smallUnit = (smallUnit / (returnRunCount()));

	Time average;
	average.hour = 0;
	average.minute = 0;
	average.second = 0;

	// [TYUI]
	if (recordMil == 1)
	{
		while (smallUnit >= 1000)
		{
			average.second++;
			smallUnit = smallUnit - 1000;
		}
		while (average.second >= 60)
		{
			average.minute++;
			average.second = average.second - 60;
		}
		while (average.minute >= 60)
		{
			average.hour++;
			average.minute = average.minute - 60;
		}
		average.millisecond = smallUnit;
	}
	else
	{
		while (smallUnit >= 60)
		{
			average.minute++;
			smallUnit = smallUnit - 60;
		}
		while (average.minute >= 60)
		{
			average.hour++;
			average.minute = average.minute - 60;
		}
		average.second = smallUnit;
		average.millisecond = 0;
	}
	
	return average;
};

//////////////////////////////////////////////---------Int functions---------//////////////////////////////////////////////

//This returns the number of runs stored for a game
int Game::returnRunCount ()
{
	return allRuns.size();
};

//////////////////////////////////////////////---------String functions---------//////////////////////////////////////////////

//This returns the name of a game
string Game::returnGameName()
{
	return gameName;
};

#endif // GAME_CPP

/*

----Files that are directly dependent on this file----
- Function.h

----Files this file is dependent on----
- game.h

*/
