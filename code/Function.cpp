/*
Filename: Function.cpp

Purpose: Implementation file for all misc. functions that are required in Speedrun.cpp

Note: This file is NOT finished.

*/

#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include "Function.h"

bool isName(string str)
{
	if (((str [0] >= 97) && (str [0] <= 122)) || ((str [0] >= 65) && (str [0] <= 90)))
	{
		return true;
	}
	else
	{
		return false;
	}
};

bool isMil(string str)
{
	if (str [str.length() - 1] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
};

//Step 0: The program stats
void initialize(vector <Game> game)
{
	// For getline
	string lineGet = "";
	// Dummy game to be pushed into the vector
	Game dummy;
	//Dummy run to be pushed into Game
	Run dummyRun;
	//Dummy date to be pushed into Game
	Date dummyDate;
	//Dummy time to be pushed into Game
	Time dummyTime;

	ifstream saved;
	bool runCheck = false;

	//The .txt file will likely be changed if encrypting is necessary
	saved.open("Saved.txt");

	//Step 2: There is no "Saved.txt" file, and a new one will be created.
	if (saved.fail())
	{
		cout << "\"Saved.txt\" file failed, creating new one..." << endl;
		ofstream NewFile;
		NewFile.open ("Saved.txt");
		NewFile.close();
		saved.close();
		saved.open ("Saved.txt");
	}

	//Step 1: There is a "Saved.txt" file, and it will be put into a vector of Games.
	while (!saved.fail())
	{
		getline (saved, lineGet);
		if (runCheck == false)
		{
			if (isName (lineGet) == 1)
			{
				dummy.recordName(lineGet);
				dummy.isRecordMil(isMil(lineGet));
				runCheck = true;
				cout << "Game Title is " << lineGet.substr(0, lineGet.length() - 2) << endl;
			}
		}
		else
		{
			if (lineGet == "")
			{
				runCheck = false;
				dummy.clearAll();
				cout << "Switch" << endl;
				dummyTime.millisecond = 0;
			}
			else
			{
				int flag = 0, dummyNumber = 0;
				for (int i = 0; i < (lineGet.length() - 1); i++)
				{
					if (flag == 0)
					{
						if ((lineGet [i] >= 48) && (lineGet [i] <= 57))
						{
							dummyNumber = (dummyNumber * 10) + (lineGet [i] - 48);
						}
						else if (lineGet [i] == 44)
						{
							flag = 1;
							dummyRun.number = dummyNumber;
							dummyNumber = 0;
						}
						else
						{
							cerr << "Problem at flag 0" << endl;
							return;
						}
					}
					else if (flag == 1)
					{
						if ((lineGet [i] >= 48) && (lineGet [i] <= 57))
						{
							dummyNumber = (dummyNumber * 10) + (lineGet [i] - 48);
						}
						else if (lineGet [i] == 58)
						{
							flag = 2;
							dummyTime.hour = dummyNumber;
							dummyNumber = 0;
						}
						else
						{
							cerr << "Problem at flag 1" << endl;
							return;
						}
					}
					else if (flag == 2)
					{
						if ((lineGet [i] >= 48) && (lineGet [i] <= 57))
						{
							dummyNumber = (dummyNumber * 10) + (lineGet [i] - 48);
						}
						else if (lineGet [i] == 58)
						{
							flag = 3;
							dummyTime.minute = dummyNumber;
							dummyNumber = 0;
						}
						else
						{
							cerr << "Problem at flag 2" << endl;
							return;
						}
					}
					else if (flag == 3)
					{
						if ((lineGet [i] >= 48) && (lineGet [i] <= 57))
						{
							dummyNumber = (dummyNumber * 10) + (lineGet [i] - 48);
						}
						else if (lineGet [i] == 44)
						{
							flag = 4;
							dummyTime.second = dummyNumber;
							dummyNumber = 0;
							dummyRun.runTime = dummyTime;
						}
						else if (lineGet [i] == 58)
						{
							flag = -3;
							dummyTime.second = dummyNumber;
							dummyNumber = 0;
						}
						else
						{
							cerr << "Problem at flag 3" << endl;
							return;
						}
					}
					else if (flag == -3)
					{
						if ((lineGet [i] >= 48) && (lineGet [i] <= 57))
						{
							dummyNumber = (dummyNumber * 10) + (lineGet [i] - 48);
						}
						else if (lineGet [i] == 44)
						{
							flag = 4;
							dummyTime.millisecond = dummyNumber;
							dummyNumber = 0;
							dummyRun.runTime = dummyTime;
						}
						else
						{
							cerr << "Problem at flag -3" << endl;
							return;
						}
					}
					else if (flag == 4)
					{
						if ((lineGet [i] >= 48) && (lineGet [i] <= 57))
						{
							dummyNumber = (dummyNumber * 10) + (lineGet [i] - 48);
						}
						else if (lineGet [i] == 47)
						{
							flag = 5;
							dummyDate.day = dummyNumber;
							dummyNumber = 0;
						}
						else
						{
							cerr << "Problem at flag 4" << endl;
							return;
						}
					}
					else if (flag == 5)
					{
						if ((lineGet [i] >= 48) && (lineGet [i] <= 57))
						{
							dummyNumber = (dummyNumber * 10) + (lineGet [i] - 48);
						}
						else if (lineGet [i] == 47)
						{
							flag = 6;
							dummyDate.month = dummyNumber;
							dummyNumber = 0;
						}
						else
						{
							cerr << "Problem at flag 5" << endl;
							return;
						}
					}
					else if (flag == 6)
					{
						if ((lineGet [i] >= 48) && (lineGet [i] <= 57))
						{
							dummyNumber = (dummyNumber * 10) + (lineGet [i] - 48);
						}
						else if (lineGet [i] == 46)
						{
							flag = 7;
							dummyDate.year = dummyNumber;
							dummyNumber = 0;
							dummyRun.runDate = dummyDate;
							game.push_back(dummy);

							cout << "Run #: " << dummyRun.number << " - ";
							if (dummyRun.runTime.hour < 10)
							{
								cout << "0";
							}
							cout << dummyRun.runTime.hour << ":"; 
							if (dummyRun.runTime.minute < 10)
							{
								cout << "0";
							}
							cout << dummyRun.runTime.minute << ":";
							if (dummyRun.runTime.second < 10)
							{
								cout << "0";
							}
							cout << dummyRun.runTime.second << ":";
							if (dummyRun.runTime.millisecond < 100)
							{
								cout << "0";
							}
							if (dummyRun.runTime.millisecond < 10)
							{
								cout << "0";
							}
							cout << dummyRun.runTime.millisecond << " on ";
							if (dummyRun.runDate.day < 10)
							{
								cout << "0";
							}
							cout << dummyRun.runDate.day << "/";
							if (dummyRun.runDate.month < 10)
							{
								cout << "0";
							}
							cout << dummyRun.runDate.month << "/" << dummyRun.runDate.year << endl;
						}
						else
						{
							cerr << "Problem at flag 6" << endl;
							return;
						}
					}
					else
					{
						cerr << "Flag overflow" << endl;
						return;
					}
				}
			}
		}
	}

	saved.close();
	return;
};

#endif // FUNCTION_CPP
