/*
Filename: game.h

Purpose: Header file for all the structs, as well as the class Game.

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

// As of now, there is no function with iostream. Therefore, the vector "allRuns" has to be filled in main. That may or may not need to be changed later down the line.
class Game
{
	public:
		void storeAllRun();
		void returnAverage();
		void returnBest();

		//These are done.
		void storeRun(Run run);
		void isRecordMil(bool ans);
		bool returnRecordMil ();
		void recordName(string name);
		void clearAll();

	private:
		//This function will be used for the recording portion of the program, as the prototype will record the time in milliseconds.
		void convertTime(double ms);
		bool recordMil;
		vector<Run> allRuns;
		string gameName;
};

#endif // GAME_H
