/*
Filename: game.h

Purpose: Header file for the class Game, and all structs involved with it

Date last worked on (dd-mm-yy): 06-01-20

----Notes----

- The file is able to run, but is NOT finished.

----Notable Bugs / Optimizations----

- game::storeAllRun() may not be used for this file.

*/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

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
	int number;
};

//See game.cpp for descriptions of functions
class Game
{
	public:
		void storeAllRun();
		void clearRun(int number);

		//These functions may be pushed into private, depending on the implementation for Step 16
		Run returnAverage();
		Run returnBest();

		//These are done.
		bool isEmpty();
		int returnRunCount ();
		void storeRun(Run run);
		void isRecordMil(bool ans);
		bool returnRecordMil ();
		void recordName(string name);
		void clearAll();
		string returnGameName();

	private:
		//This function will be used for the recording portion of the program, as the prototype will record the time in milliseconds.
		void convertTime(double ms);
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
