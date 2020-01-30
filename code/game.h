/*
Filename: game.h

Purpose: Header file for the class Game, and all structs involved with it

Date last worked on (dd-mm-yy): 29-01-20

----Notes----

- The file is able to run. It is close to completion, but at this point, optimizations are still possible.

----Notable Bugs / Optimizations----

- [QWER] Some of these may need to be shoved into the private section of the class Game
- [WERT] These may need to be in the Function.cpp, as it is not dependent on the class itself
- [ERTY] This information may need to be removed, as having the run number has no purpose that its count in allRuns cannot fulfill

*/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Time
{
	int hour;
	int minute;
	int second;
	int millisecond;
};

//A run consists of a time (hhh:mm:ss:mmm or hhh:mm:ss), a date (dd/mm/yyyy), and a count (used for chronology).
struct Run
{
	Date runDate;
	Time runTime;
	//[ERTY]
	int number;
};

//See game.cpp for descriptions of functions
class Game
{
	public:

		// These are done.
		// [QWER]
		void clearAll();
		void clearRun(vector <int> number);
		void isMil(bool ans);
		void listAllRuns();
		void printDate(Date dummy); //[WERT]
		void printRun(Run dummy);   //[WERT]
		void printTime(Time dummy);	//[WERT]
		void recordName(string name);
		void replaceRun (int runNum, Run dummy);
		void storeRun(Run run);

		Run returnBest();
		Run returnRun(int runNum);

		bool isEmpty();
		bool returnMil ();

		Time returnAverage();

		int returnRunCount();

		string returnGameName();

	private:
		bool recordMil;
		vector<Run> allRuns;
		string gameName;
};

#endif // GAME_H

/*

----Files that are directly dependent on this file----
- game.cpp

----Files this file is dependent on----

*/
