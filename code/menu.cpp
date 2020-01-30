/*
Filename: menu.cpp

Purpose: Implementation file for the menu and menuing functions

Date last worked on (dd-mm-yy): 29-01-20

----Notes----

- The file is able to run, but is NOT finished.

----Notable Bugs / Optimizations----

- The menu functions may need to be separated, for ease of understanding. As of now, this file will end up as the longest file of the code.


*/

#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"

//This determines the answer the user inputs in Step 3
Menu1 M1_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "T")  || (str == "TIME") || (str == "TIME NEW RUNS"))
	{
		return M1_TIME;
	}
	else if ((str == "2") || (str == "V")  || (str == "VIEW") || (str == "VIEW SAVED DATA"))
	{
		return M1_VIEW;
	}
	else if ((str == "3") || (str == "E") || (str == "EDIT") || (str == "EDIT PREVIOUS RUNS"))
	{
		return M1_EDIT;
	}
	else if ((str == "4") || (str == "L") || (str == "LEAVE") || (str == "LEAVE PROGRAM"))
	{
		return M1_EXIT;
	}
	else
	{
		return M1_FAIL;
	}
};
// This function is the main menu.
// Step 3
bool M1_Question(bool repeat, vector <Game> data)
{
	string M1_input = "";
	Menu1 M1 = M1_FAIL;
	if (repeat == false)
	{
		cout << "_______" << endl;
		cout << "Welcome to your personal speedrun archive!" << endl;
		cout << "What would you like to do?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [T]ime New Runs" << endl;
	cout << "2. [V]iew Saved Data" << endl;
	cout << "3. [E]dit Previous Runs" << endl;
	cout << "4. [L]eave Program" << endl << endl;

	getline (cin,M1_input);
	cout << "_______" << endl;
	M1 = M1_Answer (M1_input);

	//These are the options for the main menu.
	if (M1 == M1_TIME)
	{
		M5_Question(0, data);
		return 1;
	}
	else if (M1 == M1_VIEW)
	{
		//Step 13
		if (data.size() > 0)
		{
			listGame(data);
			cout << "Which game data would you like to view?" << endl;
			cout << "Either type the name (case sensitive) or the number next to the game's name." << endl;
			cout << "_______" << endl;
			int gameNum = INT_MIN;
			while (gameNum == INT_MIN)
			{
				getline (cin, M1_input);
				gameNum = loadGame(M1_input, data);
				if (gameNum == INT_MIN)
				{
					cout << "Invalid input" << endl;
					cout << "Please either type the name (case sensitive) or the number next to the game's name." << endl;
				}
				listGame(data);
			}

			Game dummy = data [gameNum];
			if (dummy.returnRunCount() > 0)
			{
				M14_Question(0, data, gameNum);
			}
			else
			{
				M13_Question(0, data, gameNum);
			}
			return 1;
		}
		else
		{
			cout << "You don't have any games!" << endl;
			M4_Question(0, data);
			return 1;
		}
	}
	else if (M1 == M1_EDIT)
	{
		//Step 22
		if (data.size() == 0)
		{
			cout << "You don't have any games!" << endl;
			M3_Question (0, data);
			return 1;
		}
		else
		{
			M2_Question (0, data);
		}
		return 1;
	}
	else if (M1 == M1_EXIT)
	{

		cout << "Goodbye!" << endl;
		cout << "_______" << endl;
		//Step 52 should go here, but is not finished
		return 1;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M1_Question(1, data);
		return 1;
	}
	return 1;
};

//This determines the answer the user inputs in Step 23
Menu2 M2_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "C")  || (str == "CREATE") || (str == "CREATE NEW GAME"))
	{
		return M2_CREATE;
	}
	else if ((str == "2") || (str == "E") || (str == "EDIT") || (str == "EDIT EXISTING GAME"))
	{
		return M2_EDIT;
	}
	else if ((str == "3") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M2_BACK;
	}
	else
	{
		return M2_FAIL;
	}
};
// This is the beginning of the Edit path from Step 3 (if you have saved data in saved.txt)
// Step 23
void M2_Question(bool repeat, vector <Game> data)
{
	string M2_input = "";
	Menu2 M2 = M2_FAIL;
	if (repeat == false)
	{
		cout << "You have games available!" << endl;
		cout << "Would you like to edit an existing game or create a new game?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [C]reate new game" << endl;
	cout << "2. [E]dit existing game" << endl;
	cout << "3. [G]o Back" << endl;

	getline (cin,M2_input);
	cout << endl;
	M2 = M2_Answer (M2_input);

	//These are the options for menu 2.
	if (M2 == M2_CREATE)
	{
		M3_Question(0, data);
		return;
	}
	else if (M2 == M2_EDIT)
	{
		//Step 29
		listGame(data);
		cout << "Which game would you like to edit?" << endl;
		cout << "Either type the name (case sensitive) or the number next to the game's name." << endl;
		cout << "_______" << endl;
		int gameNum = INT_MIN;
		while (gameNum == INT_MIN)
		{
			getline (cin, M2_input);
			gameNum = loadGame(M2_input, data);
			if (gameNum == INT_MIN)
			{
				cout << "Invalid input" << endl;
				cout << "Please either type the name (case sensitive) or the number next to the game's name." << endl;
			}
			listGame(data);
		}

		M8_Question(0, data, gameNum);
		
		return;
	}
	else if (M2 == M2_BACK)
	{
		M1_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M2_Question(1, data);
		return;
	}
	return;
};

//This determines the answer the user inputs in Step 24
Menu3 M3_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "M")  || (str == "MANUAL") || (str == "MANUAL ENTRY"))
	{
		return M3_MANUAL;
	}
	else if ((str == "2") || (str == "U") || (str == "USE") || (str == "USE THE SPEEDRUN CLOCK"))
	{
		return M3_USE;
	}
	else if ((str == "3") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M3_BACK;
	}
	else
	{
		return M3_FAIL;
	}
};
// This is the beginning of the Edit path from Step 3 (if you do NOT have saved data in saved.txt)
// Step 24
void M3_Question(bool repeat, vector <Game> data)
{
	string M3_input = "";
	Menu3 M3 = M3_FAIL;

	if (repeat == false)
	{
		cout << "Would you like to manually enter the speedruns or use the speedrun clock?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [M]anual entry" << endl;
	cout << "2. [U]se the speedrun clock" << endl;
	cout << "3. [G]o Back" << endl;

	getline (cin,M3_input);
	cout << endl;
	M3 = M3_Answer (M3_input);

	//These are the options for the menu 3.
	if (M3 == M3_MANUAL)
	{
		Game dummy = createGame();
		bool exit = false;
		while (exit == false)
		{
			Run dummyRun;
			//Step 26, Step 27
			dummyRun = userCreateRun(dummy.returnMil(), dummy);
			exit = !(M6_Question (0, data));
		}
		cout << "Returning to main menu..." << endl << endl;
		cout << "_______" << endl;

		M1_Question(0, data);
		return;
	}
	else if (M3 == M3_USE)
	{
		Game dummy = createGame();
		bool exit = false;
		while (exit == false)
		{
			//Step 7
			Run dummyRun = timer (dummy.returnMil(), dummy);
			if (M11_Question(0, data))
			{
				dummy.storeRun(dummyRun);
				cout << "Run saved!" << endl;
			}
			else
			{
				cout << "Run not saved!" << endl;
			}

			exit = !M12_Question(0, data);
			if (exit == true)
			{
				cout << "Returning to main menu..." << endl << endl;
				cout << "_______" << endl;
			}
		}

		data.push_back(dummy);
		M1_Question(0, data);
		return;
	}
	else if (M3 == M3_BACK)
	{
		M1_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M3_Question(1, data);
		return;
	}
	return;
};

// This is the beginning of the View path from Step 3 (if you do NOT have saved data in saved.txt)
// Step 13a
void M4_Question(bool repeat, vector <Game> data)
{
	string M4_input = "";
	bool M4 = 0;

	if (repeat == false)
	{
		cout << 	"Would you like to add a new game?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M4_input);
	cout << endl;
	M4 = YN_Answer (M4_input);

	//These are the options for the menu 3. 
	if (M4 == 1)
	{
		M3_Question (0, data);
		return;
	}
	else
	{
		M1_Question(0, data);
		return;
	}
	return;
};

//This determines the answer the user inputs in Step 4
Menu5 M5_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "C")  || (str == "CREATE") || (str == "CREATE NEW GAME"))
	{
		return M5_CREATE;
	}
	else if ((str == "2") || (str == "P") || (str == "PLAY") || (str == "PLAY EXISTING GAME"))
	{
		return M5_PLAY;
	}
	else if ((str == "3") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M5_BACK;
	}
	else
	{
		return M5_FAIL;
	}
};
// This is the beginning of the Record path from Step 3
// Step 4
void M5_Question(bool repeat, vector <Game> data)
{
	if (data.size() == 0)
	{
		cout << "You do not have an existing game!" << endl;
		cout << "Creating one... " << endl;
		Game dummy = createGame();
		return;
	}
	string M5_input = "";
	Menu5 M5 = M5_FAIL;
	Run dummyRun;

	if (repeat == false)
	{
		cout << "Would you like to create a new game or speedrun an existing one?" << endl;
		cout << "_______" << endl;
	}

	cout << 	"1. [C]reate new game" << endl;
	cout << "2. [P]lay existing game" << endl;
	cout << "3. [G]o Back" << endl;

	getline (cin,M5_input);
	cout << endl;
	M5 = M5_Answer (M5_input);

	// These are the options for the menu 3.
	// Create and Play has been started, but has not been finished
	if (M5 == M5_CREATE)
	{
		//Step 5
		Game dummy = createGame();

		bool exit = false;
		while (exit == false)
		{
			//Step 7
			dummyRun = timer (dummy.returnMil(), dummy);

			//Step 10
			if (M11_Question(0, data))
			{
				//Step 11
				dummy.storeRun(dummyRun);
				cout << "Run saved!" << endl;
			}
			else
			{
				cout << "Run not saved!" << endl;
			}

			//Step 12
			exit = !M12_Question(0, data);
			if (exit == true)
			{
				cout << "Returning to main menu..." << endl << endl;
				cout << "_______" << endl;
			}
		}

		data.push_back(dummy);
		M1_Question(0, data);
		return;
	}
	else if (M5 == M5_PLAY)
	{
		//Step 6
		listGame(data);
		cout << "Which game data would you like to speedrun?" << endl;
		cout << "Either type the name (case sensitive) or the number next to the game's name." << endl;
		cout << "_______" << endl;
		int gameNum = INT_MIN;
		while (gameNum == INT_MIN)
		{
			getline (cin, M5_input);
			gameNum = loadGame(M5_input, data);
			if (gameNum == INT_MIN)
			{
				cout << "Invalid input" << endl;
				cout << "Please either type the name (case sensitive) or the number next to the game's name." << endl;
				listGame(data);
			}
		}
		Game dummy = data [gameNum];

		bool exit = false;
		while (exit == false)
		{
			//Step 7
			dummyRun = timer (dummy.returnMil(), dummy);
			//Step 10
			if (M11_Question(0, data))
			{
				//Step 11
				dummy.storeRun(dummyRun);
				cout << "Run saved!" << endl;
			}
			else
			{
				cout << "Run not saved!" << endl;
			}

			//Step 12
			exit = !M12_Question(0, data);
			if (exit == true)
			{
				cout << "Returning to main menu..." << endl << endl;
				cout << "_______" << endl;
			}
		}

		data [gameNum] = dummy;
		M1_Question(0, data);
		return;
	}
	else if (M5 == M5_BACK)
	{
		M1_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M5_Question(1, data);
		return;
	}
	return;
};

// This is the prompt after one run has been added into a game via manual entry
//Step 28
bool M6_Question(bool repeat, vector <Game> data)
{
	string M6_input = "";
	bool M6 = 0;

	if (repeat == false)
	{
		cout << 	"Would you like to add another run?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M6_input);
	cout << endl;
	M6 = YN_Answer (M6_input);
	return M6;
};

// This is the last prompt before returning either to the beginning of Edit or the main menu
// Step 51
void M7_Question(bool repeat, vector <Game> data)
{
	string M7_input = "";
	bool M7 = 0;

	if (repeat == false)
	{
		cout << 	"Would you like to continue editing?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M7_input);
	cout << endl;
	M7 = YN_Answer (M7_input);

	//These are the options for the menu 51. 
	if (M7 == 1)
	{
		//Step 22
		if (data.size() == 0)
		{
			cout << "You don't have any games!" << endl;
			M3_Question (0, data);
			return;
		}
		else
		{
			M2_Question (0, data);
		}
		return;
	}
	else
	{
		M1_Question(0, data);
		return;
	}
	return;
};

//This determines the answer the user inputs in Step 30
Menu8 M8_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "T")  || (str == "TIME") || (str == "TIME NEW RUNS"))
	{
		return M8_TIME;
	}
	else if ((str == "2") || (str == "M") || (str == "MANUAL") || (str == "MANUALLY ADD NEW RUNS"))
	{
		return M8_MANUAL;
	}
	else if ((str == "3") || (str == "E")  || (str == "EDIT") || (str == "EDIT EXISTING RUNS OR GAME INFORMATION"))
	{
		return M8_EDIT;
	}
	else if ((str == "4") || (str == "D") || (str == "DELETE") || (str == "DELETE EXISTING RUNS OR GAME"))
	{
		return M8_DELETE;
	}
	else if ((str == "5") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M8_BACK;
	}
	else
	{
		return M8_FAIL;
	}
};
// This is the branching point for the given game to either create new runs, edit existing runs, or delete runs/itself
// Step 30
void M8_Question(bool repeat, vector <Game> data, int gameNum)
{
	string M8_input = "";
	Menu8 M8 = M8_FAIL;
	Game dummy = data [gameNum];

	if (repeat == false)
	{
		cout << "The selected game is \"" << dummy.returnGameName() << "\"." << endl;
		cout << "Would you like add additional runs with a timer, add additional runs manually, edit existing runs, or delete?" << endl;
		cout << "_______" << endl << endl;
	}

	cout << "1. [T]ime new runs" << endl;
	cout << "2. [M]anually add new runs" << endl;
	cout << "3. [E]dit existing runs or game information" << endl;
	cout << "4. [D]elete existing runs or game" << endl;
	cout << "5. [G]o back" << endl;

	getline (cin,M8_input);
	cout << endl;
	M8 = M8_Answer (M8_input);

	//These are the options for the menu 8.
	//
	if (M8 == M8_TIME)
	{
		cout << "Recording new runs via timer." << endl;
		bool exit = false;
		while (exit == false)
		{
			//Step 7
			Run dummyRun = timer (dummy.returnMil(), dummy);
			if (M11_Question(0, data))
			{
				dummy.storeRun(dummyRun);
				data [gameNum] = dummy;
				cout << "Run saved!" << endl;
			}
			else
			{
				cout << "Run not saved!" << endl;
			}

			exit = !M12_Question(0, data);
			if (exit == true)
			{
				M7_Question (0, data);
			}
		}
		return;
	}
	else if (M8 == M8_MANUAL)
	{
		bool exit = false;
		while (exit == false)
		{
			Run dummyRun;
			//Step 26, Step 27
			dummyRun = userCreateRun(dummy.returnMil(), dummy);
			exit = !(M6_Question (0, data));
		}
		//Step 28
		data [gameNum] = dummy;
		M7_Question (0, data);
		return;
	}
	else if (M8 == M8_EDIT)
	{
		M15_Question (0, data, gameNum);
		return;
	}
	else if (M8 == M8_DELETE)
	{
		M9_Question (0, data, gameNum);
		return;
	}
	else if (M8 == M8_BACK)
	{
		M2_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M8_Question(1, data, gameNum);
		return;
	}
	return;
};

//This determines the answer the user inputs in Step 47
Menu9 M9_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "R")  || (str == "RUN"))
	{
		return M9_RUN;
	}
	else if ((str == "2") || (str == "E") || (str == "ENTIRE") || (str == "GAME") || (str == "ENTIRE GAME"))
	{
		return M9_GAME;
	}
	else if ((str == "3") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M9_BACK;
	}
	else
	{
		return M9_FAIL;
	}
};
// This is the beginning of the Deletion path from Step 30
// Step 47
void M9_Question(bool repeat, vector <Game> data, int gameNum)
{
	string M9_input = "";
	Menu9 M9 = M9_FAIL;
	Game dummy = data [gameNum];

	//This vector stores which runs will be deleted.
	//item [0] will always be gameNum.
	//If item only has gameNum, the program will delete the entirety of the game
	vector <int> item;
	item.push_back(gameNum);

	if (repeat == false)
	{
		cout << "Would you like to delete specific runs, or delete the entirety of \"" << dummy.returnGameName() << "\"?" << endl;
		cout << "_______" << endl;
	}

	cout << 	"1. [R]un" << endl;
	cout << "2. [E]ntire Game" << endl;
	cout << "3. [G]o Back" << endl;

	getline (cin,M9_input);
	cout << endl;
	M9 = M9_Answer (M9_input);

	// These are the options for the menu 9.
	// Run is not yet finished.
	if (M9 == M9_RUN)
	{

		return;
	}
	else if (M9 == M9_GAME)
	{
		M10_Question(0, data, item);
		return;
	}
	else if (M9 == M9_BACK)
	{
		M2_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M9_Question(1, data, gameNum);
		return;
	}
	return;
};

// This is the confirmation of deletion from Step 47
// Step 49
void M10_Question(bool repeat, vector <Game> data, vector <int> item)
{
	string M10_input = "";
	bool M10 = 0;
	Game dummy = data [item [0]];

	if (repeat == false)
	{
		if (item.size() == 1)
		{
			cout << 	"ARE YOU SURE YOU WOULD LIKE TO DELETE \"" << dummy.returnGameName() << "\"?" << endl;
		}
		else
		{
			//This section is currently not finished
			cout << "ARE YOU SURE YOU WOULD LIKE TO DELETE \"" << endl;
		}
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M10_input);
	cout << endl;
	M10 = YN_Answer (M10_input);

	//These are the options for the menu 10
	//Step 50
	if (M10 == 1)
	{
		if (item.size() == 1)
		{
			if (item [0] > 1)
			{
				for (int fgh = (item [0]); fgh <= (data.size() - 2); fgh++)
				{
					data [fgh] = data [fgh + 1];
				}
			}
			data.pop_back();
			cout << "\""<< dummy.returnGameName() << "\" has been successfully deleted." << endl;
		}
		else
		{
			//This section is currently not finished
			cout << "ARE YOU SURE YOU WOULD LIKE TO DELETE \"" << endl;
		}
		M7_Question(0, data);
		return;
	}
	else
	{
		M7_Question(0, data);
		return;
	}
	return;
};

// This is the confirmation of saving a recorded run
// Step 11
bool M11_Question(bool repeat, vector <Game> data)
{
	string M11_input = "";
	bool M11 = 0;

	if (repeat == false)
	{
		cout << 	"Would you like to save this run?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M11_input);
	cout << endl;
	M11 = YN_Answer (M11_input);

	return M11;
};

// This is to see if the user wishes to record an additional run
// Step 12
bool M12_Question(bool repeat, vector <Game> data)
{
	string M12_input = "";
	bool M12 = 0;

	if (repeat == false)
	{
		cout << 	"Would you like to continue speedrunning?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M12_input);
	cout << endl;
	M12 = YN_Answer (M12_input);

	return M12;
};

//This determines the answer the user inputs in Step 54
Menu13 M13_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "C")  || (str == "CREATE") || (str == "CREATE NEW RUNS"))
	{
		return M13_CREATE;
	}
	else if ((str == "2") || (str == "P") || (str == "PICK") || (str == "PICK A DIFFERENT GAME"))
	{
		return M13_PICK;
	}
	else if ((str == "3") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M13_BACK;
	}
	else
	{
		return M13_FAIL;
	}
};
// This is the record path, if the user wishes to view a game without any runs.
// Step 54
void M13_Question(bool repeat, vector <Game> data, int gameNum)
{
	string M13_input = "";
	Menu13 M13 = M13_FAIL;
	Game dummy = data [gameNum];

	if (repeat == false)
	{
		cout << dummy.returnGameName() << " has no recorded runs!" << endl;
		cout << "Would you like to create new runs or pick a different game to view?" << endl;
		cout << "_______" << endl;
	}

	cout << 	"1. [C]reate new runs" << endl;
	cout << "2. [P]ick a different game" << endl;
	cout << "3. [G]o Back" << endl;

	getline (cin,M13_input);
	cout << endl;
	M13 = M13_Answer (M13_input);

	if (M13 == M13_CREATE)
	{
		M8_Question (0, data, gameNum);
		return;
	}
	else if (M13 == M13_PICK)
	{
		
		return;
	}
	else if (M13 == M13_BACK)
	{
		M1_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M13_Question(1, data, gameNum);
		return;
	}
	return;
};

//This determines the answer the user inputs in Step 17
Menu14 M14_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "S")  || (str == "SELECT") || (str == "SELECT A DIFFERENT GAME"))
	{
		return M14_SELECT;
	}
	else if ((str == "2") || (str == "V") || (str == "VIEW") || (str == "VIEW SPECIFIC RUNS"))
	{
		return M14_VIEW;
	}
	else if ((str == "3") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M14_BACK;
	}
	else
	{
		return M14_FAIL;
	}
};
// This is the view path, showcasing all information
// Step 17
void M14_Question(bool repeat, vector <Game> data, int gameNum)
{
	string M14_input = "";
	Menu14 M14 = M14_FAIL;
	Game dummy = data [gameNum];

	if (repeat == false)
	{
		if (dummy.returnRunCount() > 0)
		{
			dummy.listAllRuns();
		}
		else
		{
			M13_Question(0, data, gameNum);
			return;
		}
		cout << "_______" << endl;
	}

	cout << "1. [S]elect a different Game" << endl;
	cout << "2. [V]iew Specific Runs" << endl;
	cout << "3. [G]o back" << endl;

	getline (cin,M14_input);
	cout << endl;
	M14 = M14_Answer (M14_input);

	if (M14 == M14_SELECT)
	{
		listGame(data);
		cout << "Which game data would you like to view?" << endl;
		cout << "Either type the name (case sensitive) or the number next to the game's name." << endl;
		cout << "_______" << endl;
		int gameNum = INT_MIN;
		while (gameNum == INT_MIN)
		{
			getline (cin, M14_input);
			gameNum = loadGame(M14_input, data);
			if (gameNum == INT_MIN)
			{
				cout << "Invalid input" << endl;
				cout << "Please either type the name (case sensitive) or the number next to the game's name." << endl;
			}
			listGame(data);
		}

		M14_Question (0,data,gameNum);
		return;
	}
	else if (M14 == M14_VIEW)
	{
		return;
	}
	else if (M14 == M14_BACK)
	{
		M1_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M14_Question(1, data, gameNum);
		return;
	}
	return;
};

//This determines the answer the user inputs in Step 31
Menu15 M15_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "R")  || (str == "RUN"))
	{
		return M15_RUN;
	}
	else if ((str == "2") || (str == "E") || (str == "ENTIRE") || (str == "GAME") || (str == "ENTIRE GAME"))
	{
		return M15_GAME;
	}
	else if ((str == "3") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M15_BACK;
	}
	else
	{
		return M15_FAIL;
	}
};
// This is the beginning of the Deletion path from Step 30
// Step 31
void M15_Question(bool repeat, vector <Game> data, int gameNum)
{
	string M15_input = "";
	Menu15 M15 = M15_FAIL;
	Game dummy = data [gameNum];

	//This vector stores which runs will be editted.
	//item [0] will always be gameNum.
	//If item only has gameNum, the program will edit the entirety of the game
	vector <int> item;
	item.push_back(gameNum);

	if (repeat == false)
	{
		cout << "Would you like to edit specific runs, or edit the entirety of  \"" << dummy.returnGameName() << "\"?" << endl;
		cout << "_______" << endl;
	}

	cout << 	"1. [R]un" << endl;
	cout << "2. [E]ntire Game" << endl;
	cout << "3. [G]o Back" << endl;

	getline (cin,M15_input);
	cout << endl;
	M15 = M15_Answer (M15_input);

	// These are the options for the menu 15.
	// Run is not yet finished.
	if (M15 == M15_RUN)
	{
		dummy.listAllRuns();
		cout << endl <<  "_______" << endl;
		cout << "Which run would you like to edit?" << endl;
		
		getline (cin, M15_input);
		while (!isNumber(M15_input))
		{
			cout << "Please enter a valid number." << endl;
			getline (cin, M15_input);
		}

		while ((stringToInt(M15_input) - 1) > dummy.returnRunCount())
		{
			while (!isNumber(M15_input))
			{
				cout << "Please enter a valid number." << endl;
				getline (cin, M15_input);
			}
			cout << "Please enter a valid number." << endl;
			getline (cin, M15_input);
		}
		
		M20_Question (0, data, gameNum, (stringToInt(M15_input)));

		return;
	}
	else if (M15 == M15_GAME)
	{
		M16_Question(0, data, gameNum);
		return;
	}
	else if (M15 == M15_BACK)
	{
		M2_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M15_Question(1, data, gameNum);
		return;
	}
	return;
};

//This determines the answer the user inputs in Step 32
Menu16 M16_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "M")  || (str == "MILLISECONDS"))
	{
		return M16_MILLISECOND;
	}
	else if ((str == "2") || (str == "N") || (str == "NAME"))
	{
		return M16_NAME;
	}
	else if ((str == "3") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M16_BACK;
	}
	else
	{
		return M16_FAIL;
	}
};
// This is the beginning of the Deletion path from Step 30
// Step 32
void M16_Question(bool repeat, vector <Game> data, int gameNum)
{
	string M16_input = "";
	Menu16 M16 = M16_FAIL;
	Game dummy = data [gameNum];

	//This vector stores which runs will be editted.
	//item [0] will always be gameNum.
	//If item only has gameNum, the program will edit the entirety of the game
	vector <int> item;
	item.push_back(gameNum);

	if (repeat == false)
	{
		cout << "What would you like to change?" << endl;
		cout << "_______" << endl;
	}

	cout << 	"1. [M]illiseconds" << endl;
	cout << "2. [N]ame" << endl;
	cout << "3. [G]o Back" << endl;

	getline (cin,M16_input);
	cout << endl;
	M16 = M16_Answer (M16_input);

	// These are the options for the menu 16.
	if (M16 == M16_MILLISECOND)
	{
		if (M18_Question(0, data, gameNum) == 1)
		{
			if (M19_Question(0, data, gameNum) == 1)
			{
				if (dummy.returnMil() == 1)
				{
					cout << "Milliseconds are no longer being stored." << endl;
					dummy.isMil(0);
					data [gameNum] = dummy;
				}
				else
				{
					cout << "Milliseconds will start being stored." << endl;
					dummy.isMil(1);
					data [gameNum] = dummy;
				}
			}
		}
		M7_Question(0, data);
		return;
	}
	else if (M16 == M16_NAME)
	{
		cout << "What would you like to rename \"" << dummy.returnGameName() << "\"?" << endl;
		cout << "_______" << endl;

		getline (cin, M16_input);
		cout << endl;
		if (M17_Question(0, data, M16_input) == false)
		{
			dummy.recordName(M16_input);
			data [gameNum] = dummy;
		}
		M7_Question(0, data);
		return;
	}
	else if (M16 == M16_BACK)
	{
		M2_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M16_Question(1, data, gameNum);
		return;
	}
	return;
};

// This is to see if the user wishes to change the name of the game
// Step 33
bool M17_Question(bool repeat, vector <Game> data, string str)
{
	string M17_input = "";
	bool M17 = 0;

	if (repeat == false)
	{
		cout << 	"Is the name \"" << str << "\" correct?" << endl;
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M17_input);
	cout << endl;
	M17 = YN_Answer (M17_input);

	return M17;
};

// This is to see if the user wishes to change if milliseconds are recorded or not
// Step 36
bool M18_Question(bool repeat, vector <Game> data, int gameNum)
{
	string M18_input = "";
	bool M18 = 0;
	Game dummy = data [gameNum];

	if (repeat == false)
	{
		if (dummy.returnMil() == 1)
		{
			cout << 	"Would you like to stop recording milliseconds for \"" << dummy.returnGameName() << "\"?" << endl;
		}
		else
		{
			cout << 	"Would you like to start recording milliseconds for \"" << dummy.returnGameName() << "\"?" << endl;
		}
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M18_input);
	cout << endl;
	M18 = YN_Answer (M18_input);

	return M18;
};

// This is to see if the user wishes to change the name of the game
// Step 38
bool M19_Question(bool repeat, vector <Game> data, int gameNum)
{
	string M19_input = "";
	bool M19= 0;
	Game dummy = data [gameNum];

	if (repeat == false)
	{
		if (dummy.returnMil() == 1)
		{
			cout << "WARNING!" << endl;
			cout << "_______" << endl;
			cout << "If you stop recording milliseconds, all previous runs of \"" << dummy.returnGameName() << "\" will no longer have milliseconds." << endl;
			cout << 	"Are you sure you would like to stop recording milliseconds for \"" << dummy.returnGameName() << "\"?" << endl;
		}
		else
		{
			cout << "WARNING!" << endl;
			cout << "_______" << endl;
			cout << "If you stop recording milliseconds, all previous runs of \"" << dummy.returnGameName() << "\" will not have milliseconds stored." << endl;
			cout << 	"Are you sure you would like to start recording milliseconds for \"" << dummy.returnGameName() << "\"?" << endl;
		}
		cout << "_______" << endl;
	}

	cout << "1. [Y]es" << endl;
	cout << "2. [N]o" << endl;

	getline (cin,M19_input);
	cout << endl;
	M19 = YN_Answer (M19_input);

	return M19;
};

//This determines the answer the user inputs in Step 40
Menu20 M20_Answer (string str)
{
	str = stringInterpreter (str);
	if ((str == "1") || (str == "T")  || (str == "TIME"))
	{
		return M20_TIME;
	}
	else if ((str == "2") || (str == "D") || (str == "DATE"))
	{
		return M20_DATE;
	}
	else if ((str == "3") || (str == "O") || (str == "ORDER"))
	{
		return M20_ORDER;
	}
	else if ((str == "4") || (str == "G") || (str == "GO") || (str == "GO BACK"))
	{
		return M20_BACK;
	}
	else
	{
		return M20_FAIL;
	}
};
// This is the beginning of the Deletion path from Step 30
// Step 40
void M20_Question(bool repeat, vector <Game> &data, int gameNum, int runNum)
{
	string M20_input = "";
	Menu20 M20 = M20_FAIL;
	Game dummy = data [gameNum];
	Run dummyRun = dummy.returnRun(runNum);

	if (repeat == false)
	{
		cout << "What would you like to change?" << endl;
		cout << "_______" << endl;
	}

	cout << 	"1. [T]ime" << endl;
	cout << "2. [D]ate" << endl;
	cout << "3. [O]rder" << endl;
	cout << "4. [G]o Back" << endl;

	getline (cin,M20_input);
	cout << endl;
	M20 = M20_Answer (M20_input);

	// These are the options for the menu 16.
	if (M20 == M20_TIME)
	{
		Time dummyTime;

		cout << "Please type your speedrun in the format ";
		if (dummy.returnMil())
		{
			cout << "hh:mm:ss:mmm" << endl;
		}
		else
		{
			cout << "hh:mm:ss" << endl;
		}
		cout << "_______" << endl;

		getline (cin,M20_input);
		while (!isTimeValid(M20_input, dummy.returnMil()))
		{
			getline (cin, M20_input);
		}

		dummyTime = stringToTime (M20_input, dummy.returnMil());

		cout << "Is ";
		dummy.printTime(dummyTime);
		cout << " correct?" << endl;
		cout << "_______" << endl;

		cout << "1. [Y]es" << endl;
		cout << "2. [N]o" << endl;
		cout << endl;

		getline (cin, M20_input);

		if (YN_Answer(M20_input))
		{
			dummyRun.runTime = dummyTime;
			dummy.replaceRun(runNum, dummyRun);
			data [gameNum] = dummy;
		}
		cout << endl;
		
		M7_Question (0, data);
		return;
	}
	else if (M20 == M20_DATE)
	{
		Date dummyDate;

		cout << "Please type the date of your speedrun in the format dd-mm-yyyy" << endl;
		cout << "_______" << endl;

		getline (cin,M20_input);
		while (!isDateValid(M20_input))
		{
			getline (cin, M20_input);
		}

		dummyDate = stringToDate (M20_input);
		dummyRun.runDate = dummyDate;

		cout << "Is ";
		dummy.printDate(dummyDate);
		cout << " correct?" << endl;
		cout << "_______" << endl;

		cout << "1. [Y]es" << endl;
		cout << "2. [N]o" << endl;
		cout << endl;

		getline (cin, M20_input);

		if (YN_Answer(M20_input))
		{
//			dummyRun.runTime = dummyTime;
			dummy.replaceRun(runNum, dummyRun);
			data [gameNum] = dummy;
		}
		cout << endl;
		
		M7_Question (0, data);
		return;
	}
	else if (M20 == M20_ORDER)
	{
		return;
	}
	else if (M20 == M20_BACK)
	{
		M2_Question(0, data);
		return;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry." << endl;
		cout << endl;
		M20_Question(1, data, gameNum, runNum);
		return;
	}
	return;
};


#endif // MENU_CPP

/*

----Files that are directly dependent on this file----
- Speedrun.cpp

----Files this file is dependent on----
- menu.h
- game.cpp
- game.h
- Function.h
- Function.cpp

*/
