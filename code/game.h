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
	int Day;
	int Month;
	int Year;
};

struct Time
{
	int Hour;
	int Minute;
	int Second;
	int Millisecond;
};

struct Run
{
	Date runDate;
	Time runTime;
	int number;
};

class Game
{
	public:
		void recordRunDate(int d, int m, int y);
		void recordRunTime(int h, int m, int s, int ms);
		void storeRun();
		void storeAllRun();
		void returnAverage();
		void returnBest();

		//These are done.
		void isRecordMil(bool ans);
		bool returnRecordMil ();
		void recordName(string name);

	private:
		void convertTime();
		bool recordMil;
		vector<Run> allRuns;
		string gameName;
};

#endif // GAME_H
