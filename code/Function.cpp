/*
Filename: Function.cpp

Purpose: Implementation file for all misc. functions that are required in Speedrun.cpp

Date last worked on (dd-mm-yy): 29-01-20

----Notes----

- The file is able to run. It is close to completion, but at this point, optimizations are still possible.
- All couts left in comments are used for checking if certain events are fulfilled. For example, see line 597. Eventually, these may be deleted.

----Notable Bugs / Optimizations----

- [UIOP] With, the current saved.txt file's configuration, a period and a space is needed at the end of the run for the year to be properly saved, and therefore be valid.
- [FGHJ] Dealing with game titles with numbers for the isName function 
- [SDFG] Potential optimization: allowing single/double digit millisecond or single digit second/minute such as three hours, two minutes, five seconds (3:2:5)
- [DFGH] Having a cancel function put in userCreatedRun and createGame, in case the user wants to back out of here 
- [GHJK] This function needs appropriate date structures (ie. 31 days, 12 months, etc.)
- [HJKL] This may need to be changed, if we allow a date such as April 6th 2000 (6-4-2000)
- [YUIO] Any function with this tag will likely be unncessary later in development, as an executable program will likely not use command line entry
- [ZXCV] This may need to be in a separate file, as it deviates from the "menu" format but is still a menu related item
- [XCVB] Edge case of a game title being a numerical value, such as abbreviating "77: And Two Stars Meet Again" as "77", while also having 77 games stored. With its current implementation, it would return the game titled "77", rather than the 77th game in data
- [CVBN] This will be in later optimizations, but there can be a new option for a user to give themselves tips (a vector of strings) that will pop up when the appropriate amount of time has passed
- [VBNM] Insertion sort will be fine for now, but when the number of runs starts exceeding double digits a different sorting method would be more suitable.

*/

#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include "Function.h"

//////////////////////////////////////////////---------Bool functions---------//////////////////////////////////////////////

// This checks if the user's input is valid in terms of the date
// [GHJK]
bool isDateValid(string str)
{
	int numCount = 0, flag = 0;

	//[HJKL]
	if (str.length() != 10)
	{
		cout << "The date is not valid due to an incorrect size" << endl << endl;
		cout << "Please retype the date." << endl;
		cout << "_______" << endl;
		return false;
	}

	for (int abc = 0; abc <= (str.length() - 1); abc++)
	{
		if (str [abc] == 45)
		{
			if ((flag == 1) || (flag == 0))
			{
				if (numCount == 2)
				{
					flag++;
					numCount = 0;
				}
				else
				{
					// [HJKL]
					cout << "The date is not valid due to invalid numerical values" << endl << endl;
					cout << "Please retype the date." << endl;
					cout << "_______" << endl;
					return false;
				}
			}
			else if (flag == 2)
			{
				if (numCount == 4)
				{
					flag++;
					numCount = 0;
				}
				else
				{
					// [HJKL]
					cout << "The date is not valid due to invalid numerical values" << endl << endl;
					cout << "Please retype the date." << endl;
					cout << "_______" << endl;
					return false;
				}
			}
		}
		else
		{
			if ((str [abc] >= 48) && (str [abc] <= 57))
			{
				numCount++;
			}
			else
			{
				cout << "The date is not valid due to non numerical values" << endl << endl;
				cout << "Please retype the date." << endl;
				cout << "_______" << endl;
				return false;
			}
		}
	}
	return true;
};

// This function is a temporary measure to ensure that the getline records the millisecond properly for Step 1
bool isMilStored(string str)
{
	// The last characters of a game title from the getline in Step1 should ALWAYS be ",1" or ",0"
	if (str [str.length() - 1] == 49)
	{
		return true;
	}
	else
	{
		return false;
	}
};

// This function is a measure to ensure that the getline records the name properly
bool isName(string str)
{
	//This checks if a alphabetic character is on the getline.
	//[FGHJ]
	if (((str [0] >= 97) && (str [0] <= 122)) || ((str [0] >= 65) && (str [0] <= 90)))
	{
		return true;
	}
	else
	{
		return false;
	}
};

// This function returns if the string given is a number
bool isNumber(string str)
{
	for (int qwe = 0; qwe < (str.length() - 1); qwe++)
	{
		if (!((str [qwe] >= 48) && (str [qwe] <= 57)))
		{
			return false;
		}
	}
	return true;
}

// This checks if the user's input is valid in terms of time
bool isTimeValid (string str, bool mil)
{
	int colonCount = 0, numCount = 0;
	bool initMil = mil;

	for (int j = (str.length() - 1); j >= 0; j--)
	{
		if (str [j] == 58)
		{
			colonCount++;

			//[SDFG]
			if ((numCount < 2) || (numCount > 3))
			{
				cout << "The run is not valid due to invalid numerical input." << endl;
				if (mil == true)
				{
					cout << "Follow the format of \"hhh:mm:ss:mmm\"." << endl << endl;
				}
				else
				{
					cout << "Follow the format of \"hhh:mm:ss\"." << endl << endl;
				}
				cout << "Please retype the time." << endl;
				cout << "_______" << endl;
				return false;
			}

			if ((numCount == 3) && (mil == true))
			{
				if (initMil == true)
				{
					if (colonCount != 1)
					{
						cout << "The run is not valid due to invalid numerical input." << endl;
						cout << "Follow the format of \"hhh:mm:ss:mmm\"." << endl << endl;
						cout << "Please retype the time." << endl;
						cout << "_______" << endl;
						return false;
					}
					else
					{
						initMil = false;
					}
				}
				else
				{
					cout << "The run is not valid due to invalid numerical input." << endl;
					cout << "Follow the format of \"hhh:mm:ss:mmm\"." << endl << endl;
					cout << "Please retype the time." << endl;
					cout << "_______" << endl;
					return false;
				}
			}

			numCount = 0;
		}
		else if ((str [j] >= 48) && (str [j] <= 57))
		{
			numCount++;
		}
		else
		{
			cout << "The run is not valid due to non numerical values or colons" << endl << endl;
			cout << "Please retype the time." << endl;
			cout << "_______" << endl;
			return false;
		}
	}

	if ((colonCount < 2) && (mil == true))
	{
		cout << "This run is not valid due to too little colons." << endl;
		cout << "If your is less than a minute long, use the format \"00:ss:mmm\"." << endl << endl;
		cout << "Please retype the time." << endl;
		cout << "_______" << endl;
		return false;
	}

	if ((colonCount < 1) && (mil == false))
	{
		cout << "This run is not valid due to too little colons." << endl;
		cout << "If your is less than a minute long, use the format \"00:00:ss\"." << endl << endl;
		cout << "Please retype the time." << endl;
		cout << "_______" << endl;
		return false;
	}

	return true;
};

// This determines the answer the user inputs in Step 13a, Step 28, Step 5, Step 25, Step 51
// [YUIO]
bool YN_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "Y")  || (str == "YES"))
	{
		return 1;
	}
	else if ((str == "2") || (str == "N") || (str == "NO"))
	{
		return 0;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;

		cout << "1. [Y]es" << endl;
		cout << "2. [N]o" << endl;

		getline (cin,str);
		cout << endl;
		return YN_Answer(str);
	}
};

//////////////////////////////////////////////---------Time functions---------//////////////////////////////////////////////

// This changes the time from milliseconds to a hours:minutes:seconds(:milliseconds) format
Time convertTime(long double totalMilliseconds, bool mil)
{
	Time dummy;
	dummy.hour = 0;
	dummy.minute = 0;
	dummy.second = 0;
	
	while (totalMilliseconds >= 1000)
	{
		dummy.second++;
		totalMilliseconds = totalMilliseconds - 1000;
	}
	while (dummy.second >= 60)
	{
		dummy.minute++;
		dummy.second = dummy.second - 60;
	}
	while (dummy.minute >= 60)
	{
		dummy.hour++;
		dummy.minute = dummy.minute - 60;
	}

	if (mil == 1)
	{
		dummy.millisecond = totalMilliseconds;
	}
	else
	{
		dummy.millisecond = 0;
	}

	return dummy;
};

// This converts the string given into a time, provided it passes isTimeValid
Time stringToTime (string str, bool mil)
{
	Time dummy;
	dummy.hour = 0;
	dummy.minute = 0;
	dummy.second = 0;
	dummy.millisecond = 0;
	
	int flag = 0;

	for (int k = 0; k <= (str.length() - 1); k++)
	{
		// Flag (0) records hours
		if (flag == 0)
		{
			if (str [k] == 58)
			{
				flag = 1;
			}
			else
			{
				dummy.hour = (dummy.hour * 10) + (str [k] - 48);
			}
		}
		else if (flag == 1)
		{
			if (str [k] == 58)
			{
				flag = 2;
			}
			else
			{
				dummy.minute = (dummy.minute * 10) + (str [k] - 48);
			}
		}
		else if (flag == 2)
		{
			if (str [k] == 58)
			{
				flag = 3;
			}
			else
			{
				dummy.second = (dummy.second * 10) + (str [k] - 48);
			}
		}
		else
		{
			dummy.millisecond = (dummy.millisecond * 10) + (str [k] - 48);
		}
	}

	return dummy;
};

//////////////////////////////////////////////---------Date functions---------//////////////////////////////////////////////

// This returns today's date
Date getToday()
{
	Date dummy;

    time_t t = time(0);
    tm* now = localtime(&t);

	dummy.year = now->tm_year + 1900;
	dummy.month = now->tm_mon + 1;
	dummy.day = now->tm_mday;

	return dummy;
};

// This converts the string given into a date, provided it passes isDateValid
Date stringToDate (string str)
{
	Date dummy;
	dummy.day = 0;
	dummy.month = 0;
	dummy.year = 0;
	
	int flag = 0;

	for (int bcd = 0; bcd <= (str.length() - 1); bcd++)
	{
		if (flag == 0)
		{
			if (str [bcd] == 45)
			{
				flag = 1;
			}
			else
			{
				dummy.day = (dummy.day * 10) + (str [bcd] - 48);
			}
		}
		else if (flag == 1)
		{
			if (str [bcd] == 45)
			{
				flag = 2;
			}
			else
			{
				dummy.month = (dummy.month * 10) + (str [bcd] - 48);
			}
		}
		else
		{
			dummy.year = (dummy.year * 10) + (str [bcd] - 48);
		}
	}
	return dummy;
};

//////////////////////////////////////////////---------Int functions---------//////////////////////////////////////////////

// This returns the game location in data
// Step 29, Step 6
int loadGame(string str, vector <Game> data)
{
	// loadGame will have two ways of selecting games: via exact name or numerical value
	Game dummy;
	int num = 0;

	// [XCVB]
	// This checks if the user types in a numerical value instead of the title of the game
	for (int sdf = 0; sdf <= (str.length() - 1); sdf++)
	{
		if ((str [sdf] >= 48) && (str [sdf] <= 57))
		{
			num = (num * 10) + (str [sdf] - 48);
		}
		else
		{
			num = INT_MIN;
		}
	}

	// This checks if the user types in a numerical value instead of the title of the game
	for (int asd = 0; asd <= (data.size() - 1); asd++)
	{
		dummy = data [asd];
		if (str == dummy.returnGameName())
		{
			return asd;
		}
		else if ((asd + 1) == num)
		{
			return asd;
		}
	}

	// If the function hits this point, the function will return INT_MIN to state a fail point
	return num;
};


// This converts a string into an int, provided it passes isNumber
int stringToInt(string str)
{
	int dummy = 0;
	for (int qwe = 0; qwe <= (str.length() - 1); qwe++)
	{
		dummy = (dummy * 10) + ((str [qwe]) - 48);
	}
	return dummy;
};

//////////////////////////////////////////////---------Run functions---------//////////////////////////////////////////////

// This function is the entirety
// Step 7
Run timer(bool mil, Game game)
{
	Run dummy;
	string str = "";

	cout << "Press enter when you're ready to go." << endl;
	cout << "_______" << endl;
	getline (cin, str);
    auto start = chrono::system_clock::now();
	cout << "Press enter when you have completed your game." << endl;
	cout << "Type \"restart\" if you would like to start over." << endl;
	// [CVBN]
	cout << "_______" << endl;
	getline (cin, str);
	// Step 9
    auto end = chrono::system_clock::now();

	// Step 8
	str = stringInterpreter (str);
	if ((str == "R") || (str == "RESTART"))
	{
		return timer(mil, game);
	}

	chrono::duration<long double> elapsed_milliseconds = (end-start) * 1000;

	dummy.runTime = convertTime(elapsed_milliseconds.count(), game.returnMil());

	cout << "Your time is " << dummy.runTime.hour << ":";
	if (dummy.runTime.minute < 10)
	{
		cout << "0";
	}
	cout << dummy.runTime.minute << ":";
	if (dummy.runTime.second < 10)
	{
		cout << "0";
	}
	cout << dummy.runTime.second;
	if (mil == 1)
	{
		cout << ":";
		if (dummy.runTime.millisecond < 100)
		{
			cout << "0";
		}
		if (dummy.runTime.millisecond < 10)
		{
			cout << "0";
		}
		cout << dummy.runTime.millisecond;
	}
	cout << endl;

	dummy.runDate = getToday();
	dummy.number = game.returnRunCount() + 1;

	return dummy;
};

//This creates a new run to be stored into game's vector
//[DFGH] Step 26
Run userCreateRun(bool mil, Game &game)
{
	Run dummy;
	string lineGet = "";
	cout << "Please type your speedrun in the format ";
	if (mil)
	{
		cout << "hh:mm:ss:mmm" << endl;
	}
	else
	{
		cout << "hh:mm:ss" << endl;
	}
	cout << "_______" << endl;

	getline (cin, lineGet);
	while (!isTimeValid(lineGet, mil))
	{
		getline (cin, lineGet);
	}
	dummy.runTime = stringToTime(lineGet,mil);

	cout << "Please type the date of your speedrun in the format dd-mm-yyyy" << endl;
	cout << "_______" << endl;

	getline (cin, lineGet);
	while (!isDateValid(lineGet))
	{
		getline (cin, lineGet);
	}
	dummy.runDate = stringToDate(lineGet);
	dummy.number = game.returnRunCount () + 1;
	
	return dummy;
};

//////////////////////////////////////////////---------Void functions---------//////////////////////////////////////////////
//Step 0
void initialize(vector <Game> &data)
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

	//Step 2
	if (saved.fail())
	{
//		cout << "\"Saved.txt\" file failed, creating new one..." << endl;
		ofstream NewFile;
		NewFile.open ("Saved.txt");
		NewFile.close();
		saved.close();
		saved.open ("Saved.txt");
	}

	//Step 1
	//Step 2 goes through this process as well, but since the file is empty, Step 2 skips this while function
	while (!saved.fail())
	{
		getline (saved, lineGet);
		if (runCheck == false)
		{
			if (isName (lineGet) == 1)
			{
				dummy.recordName(lineGet.substr(0, lineGet.length() - 2));
				dummy.isMil(isMilStored(lineGet));
				runCheck = true;
//				cout << "Game Title is " << lineGet.substr(0, lineGet.length() - 2) << endl;
			}
		}
		else
		{
			if (lineGet == "")
			{
				runCheck = false;
				data.push_back(dummy);
//				cout << "There are a total of " << dummy.returnRunCount() << " runs saved for the game " << dummy.returnGameName() << "." << endl;
//				cout << dummy.returnGameName() << " has mil set to " << dummy.returnMil() << endl;
				dummy.clearAll();
				dummyTime.millisecond = 0;
			}
			else
			{
				//The flags determine what portion of the run from getLine the program is reading.
				//[UIOP]	
				int flag = 0, dummyNumber = 0;
				for (int i = 0; i < (lineGet.length() - 1); i++)
				{
					//Flag 0 determines the run number
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
//							cerr << "Problem at flag 0" << endl;
							return;
						}
					}
					//Flag 1 determines the number of hours for the run
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
//							cerr << "Problem at flag 1" << endl;
							return;
						}
					}
					//Flag 2 determines the number of minutes for the run
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
//							cerr << "Problem at flag 2" << endl;
							return;
						}
					}
					//Flag 3 determines the number of seconds for the run
					//It will branch off to Flag -3 if milliseconds are involved.
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
//							cerr << "Problem at flag 3" << endl;
							return;
						}
					}
					//Flag -3 determines the number of milliseconds for the run
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
//							cerr << "Problem at flag -3" << endl;
							return;
						}
					}
					//Flag 4 determines the number of date in terms of days of the run
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
//							cerr << "Problem at flag 4" << endl;
							return;
						}
					}
					//Flag 5 determines the number of date in terms of months of the run
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
//							cerr << "Problem at flag 5" << endl;
							return;
						}
					}
					//Flag 6 determines the number of date in terms of years of the run
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
							dummy.storeRun(dummyRun);
						}
						else
						{
//							cerr << "Problem at flag 6" << endl;
							return;
						}
					}
					else
					{
//						cerr << "Flag overflow" << endl;
						return;
					}
				}
			}
		}
	}
	saved.close();
	return;
};

// This lists all games stored in data
void listGame(vector <Game> data)
{
	Game dummy;
	cout << "This is the list of all games you currently have." << endl;
	for (int dfg = 0; dfg <= (data.size() - 1); dfg++)
	{
		dummy = data [dfg];
		cout << (dfg + 1) << ". " << dummy.returnGameName() << endl;
	}
	cout << "_______" << endl << endl;	
	return;
};

//////////////////////////////////////////////---------String functions---------//////////////////////////////////////////////

// This function will take the user's input and change all lowercase alphabetic characters to uppercase for the ease of menuing
// [YUIO]
string stringInterpreter (string str)
{
	if (str == "")
	{
		return str;
	}
	for (int i = 0; i <= (str.length() - 1); i++)
	{
		if ((str [i] >= 97) && (str [i] <= 122))
		{
			str [i] = str [i] - 32;
		}
	}
	return str;
};

//////////////////////////////////////////////---------Game functions---------//////////////////////////////////////////////

//This creates a new game to be input into the vector of all games
//[DFGH] Step 5, Step 25
Game createGame()
{
	Game dummy;
	string lineGet = "", answer = "";
	cout << "What is the name of the game you are speedrunning?" << endl;
	cout << "_______" << endl;
	cout << endl;

	while (lineGet == "")
	{
		getline (cin, lineGet);
		cout << endl;
		if (lineGet == "")
		{
			cout << "Please enter a proper name." << endl;
		}
		else
		{
			cout << "Is " << lineGet << " correct?" << endl;

			cout << "1. [Y]es" << endl;
			cout << "2. [N]o" << endl;
			getline (cin, answer);
			cout << endl;
			if (YN_Answer (answer) == 0)
			{
				lineGet = "";
				cout << "What is the name of the game you are speedrunning?" << endl;
			}
		}
	}

	dummy.recordName(lineGet);

	lineGet = "";

	cout << "Does the game need to record milliseconds?" << endl;
	cout << "_______" << endl;

	getline (cin, lineGet);
	dummy.isMil(YN_Answer(lineGet));
	return dummy;
};

// This sorts the vector into chronological order via insertionSort
// [VBNM]
vector <int> chronologicalOrder(vector <int> number)
{
	int dummy;
	if ((number.size() == 0) || (number.size() == 1))
	{
		return number;
	}

	for (int zxc = 0; zxc <= (number.size() - 1); zxc++)
	{
		for (int asd = (zxc + 1); asd <= (number.size() - 1); asd++)
		{
			if (number [asd] < number [zxc])
			{
				dummy = number [asd];
				number [asd] = number [zxc];
				number [zxc] = dummy;
			}
			else if (number [asd] == number [zxc])
			{
				dummy = asd;
				while (asd < (number.size() - 1))
				{
					number [asd] = number[asd + 1];
					asd++;
				}
				number.pop_back();
				asd = dummy;
			}
		}
	}
	return number;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // FUNCTION_CPP

/*

----Files that are directly dependent on this file----
- menu.h

----Files this file is dependent on----
- game.cpp
- game.h
- Function.h

*/
