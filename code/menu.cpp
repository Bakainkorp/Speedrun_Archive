/*
Filename: menu.cpp

Purpose: Implementation file for the menu and menuing functions

----Notes----

- The file is able to run, but is NOT finished.
- All couts left in comments are used for checking if certain events are fulfilled. For example, see line 65.

----Notable Bugs----

*/

#ifndef MENU_CPP
#define MENU_CPP

#include "menu.h"

// This function will take the user's input and change all lowercase alphabetic characters to uppercase
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
	else if ((str == "4") || (str == "X") || (str == "EXIT") || (str == "EXIT PROGRAM"))
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
bool M1_Question(bool repeat)
{
	string M1_input = "";
	Menu1 M1 = M1_FAIL;
	if (repeat == false)
	{
		cout << "Welcome to your personal speedrun archive!" << endl;
		cout << "What would you like to do?" << endl;
		cout << "_______" << endl;
	}

	cout << "1.  [T]ime New Runs" << endl;
	cout << "2.  [V]iew Saved Data" << endl;
	cout << "3.  [E]dit Previous Runs" << endl;
	cout << "4. E[X]it Program" << endl << endl;

	getline (cin,M1_input);
	cout << endl;
	M1 = M1_Answer (M1_input);

	//These are the options for the main menu. These are currently not finished.
	if (M1 == M1_TIME)
	{
		return 0;
	}
	else if (M1 == M1_VIEW)
	{
		return 0;
	}
	else if (M1 == M1_EDIT)
	{
		return 0;
	}
	else if (M1 == M1_EXIT)
	{
		return 1;
	}
	else
	{
		cout << "Entry unrecognized. Retype your entry" << endl;
		cout << endl;
		M1_Question(1);
		return 1;
	}
	return 1;
};

#endif // MENU_CPP

/*

----Files that are directly dependent on this file----
- Speedrun.cpp

----Files this file is dependent on----
- menu.h

*/
