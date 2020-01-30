/*
Filename: menu.h

Purpose: Header file for enums of the menus and associated menuing functions

Date last worked on (dd-mm-yy): 29-01-20

----Notes----

- The file is able to run. It is close to completion, but at this point, optimizations are still possible.
- For now, there are several Menu[int] enums for ease of understanding, but consolidating them may be useful for space management
- The menu functions should be renamed such that they either reflect the numerical order given on the Step list or are the Step numbers

----Notable Bugs / Optimizations----

- Organization of the declared menu functions needs to be done. For now, this organization is functional, but is quite an eyesore.
- For ALL non Y/N questions, changing the functions from enum-based to integer-based would likely be more space-efficient

*/

#ifndef MENU_H
#define MENU_H

#include "Function.cpp"

using namespace std;

//Step 3
/*
	"Welcome to your personal speedrun archive!"
	"What would you like to do?"
*/
/*
	1. [T]ime New Runs
	2. [V]iew Saved Data
	3. [E]dit Previous Runs
	4. [L]eave Program
*/
enum Menu1
{
	M1_TIME,
	M1_VIEW,
	M1_EDIT,
	M1_EXIT,
	M1_FAIL
};
Menu1 M1_Answer (string str);
bool M1_Question(bool repeat, vector <Game> data);

//Step 23
		/*
			"Would you like to edit an existing game or create a new game?"
		*/
		/*
			1. [C]reate new game
			2. [E]dit existing game
			3. [G]o Back
		*/
		enum Menu2
		{
			M2_CREATE,
			M2_EDIT,
			M2_BACK,
			M2_FAIL
		};
		Menu2 M2_Answer (string str);
		void M2_Question(bool repeat, vector <Game> data);

//////////////////Step 24
				/*
					"Would you like to manually enter games or use the speedrun clock?"
				*/
				/*
					1. [M]anual entry
					2. [U]se the speedrun clock
					3. [G]o Back
				*/
				enum Menu3
				{
					M3_MANUAL,
					M3_USE,
					M3_BACK,
					M3_FAIL
				};
				Menu3 M3_Answer (string str);
				void M3_Question(bool repeat, vector <Game> data);

//////////////////////////Step 4
						/*
							"Would you like to create a new game or speedrun an existing one?"
						*/
						/*
							1. [C]reate new game
							2. [P]lay existing game
							3. [G]o Back
						*/
						enum Menu5
						{
							M5_CREATE,
							M5_PLAY,
							M5_BACK,
							M5_FAIL
						};
						Menu5 M5_Answer (string str);
						void M5_Question(bool repeat, vector <Game> data);

//////////////////////////////////Step 30
								/*
									"The game selected is \"[GAME TITLE HERE]\"."
									"Would you like add additional runs with a timer, add additional runs manually, edit existing runs, or delete?
								*/
								/*
									1. [T]ime new runs
									2. [M]anually add new runs
									3. [E]dit existing runs
									4. [D]elete existing runs or game
									5. [G]o back
								*/
								enum Menu8
								{	
									M8_TIME,
									M8_MANUAL,
									M8_EDIT,
									M8_DELETE,
									M8_BACK,
									M8_FAIL
								};
								Menu8 M8_Answer (string str);
								void M8_Question(bool repeat, vector <Game> data, int gameNum);

//Step 47
/*
	"Would you like to delete specific runs, or delete the entire game?
*/
/*
	1. [R]un
	2. [E]ntire game
	3. [G]o back
*/
enum Menu9
{	
	M9_RUN,
	M9_GAME,
	M9_BACK,
	M9_FAIL
};
Menu9 M9_Answer (string str);
void M9_Question(bool repeat, vector <Game> data, int gameNum);

//////////Step 54
		/*
			"Would you like to create new runs or pick a different game?
		*/
		/*
			1. [C]reate new runs
			2. [P]ick a different game
			3. [G]o back
		*/
		enum Menu13
		{	
			M13_CREATE,
			M13_PICK,
			M13_BACK,
			M13_FAIL
		};
		Menu13 M13_Answer (string str);
		void M13_Question(bool repeat, vector <Game> data, int gameNum);

//////////////////Step 17
				/*
					(information here)
				*/
				/*
					1. [S]elect a different Game
					2. [V]iew Specific Runs
					3. [G]o back
				*/
				enum Menu14
				{	
					M14_SELECT,
					M14_VIEW,
					M14_BACK,
					M14_FAIL
				};
				Menu14 M14_Answer (string str);
				void M14_Question(bool repeat, vector <Game> data, int gameNum);

//////////////////////////Step 31
						/*
							"Would you like to edit specific runs, or edit the entire game?
						*/
						/*
							1. [R]un
							2. [E]ntire game
							3. [G]o back
						*/
						enum Menu15
						{	
							M15_RUN,
							M15_GAME,
							M15_BACK,
							M15_FAIL
						};
						Menu15 M15_Answer (string str);
						void M15_Question(bool repeat, vector <Game> data, int gameNum);

//////////////////////////////////Step 32
								/*
									"What would you like to change?
								*/
								/*
									1. [M]lliseconds
									2. [N]ame
									3. [G]o back
								*/
								enum Menu16
								{	
									M16_MILLISECOND,
									M16_NAME,
									M16_BACK,
									M16_FAIL
								};
								Menu16 M16_Answer (string str);
								void M16_Question(bool repeat, vector <Game> data, int gameNum);

//Step 40
/*
	"What would you like to change for this run?
*/
/*
	1. [T]ime
	2. [D]ate
	3. [O]rder
	4. [G]o back
*/
enum Menu20
{	
	M20_TIME,
	M20_DATE,
	M20_ORDER,
	M20_BACK,
	M20_FAIL
};
Menu20 M20_Answer (string str);
void M20_Question(bool repeat, vector <Game> &data, int gameNum, int runNum);


//The following menus all use Yes or No answers
// And therefore uses YN_Answer
//Step 13a
/*
	"You don't have any games!"
	"Would you like to add a new game?"
*/
/*
	1. [Y]es
	2. [N]o
*/
void M4_Question(bool repeat, vector <Game> data);
//Step 28
/*
	"Would you like to add another run?"
*/
/*
	1. [Y]es
	2. [N]o
*/
bool M6_Question(bool repeat, vector <Game> data);
//Step 51
/*
"Would you like to continue editing?"
*/
/*
	1. [Y]es
	2. [N]o
*/
void M7_Question(bool repeat, vector <Game> data);
//Step 49
/*
"ARE YOU SURE YOU WOULD LIKE TO DELETE [Runs]/[GAME]?"
*/
/*
	1. [Y]es
	2. [N]o
*/
void M10_Question(bool repeat, vector <Game> data, vector <int> item);
//Step 10
/*
"Would you like to save this run?"
*/
/*
	1. [Y]es
	2. [N]o
*/
bool M11_Question(bool repeat, vector <Game> data);
//Step 12
/*
"Would you like to time another run?"
*/
/*
	1. [Y]es
	2. [N]o
*/
bool M12_Question(bool repeat, vector <Game> data);
//Step 12
/*
"Is [GAME NAME] correct?"
*/
/*
	1. [Y]es
	2. [N]o
*/
bool M17_Question(bool repeat, vector <Game> data, string str);
//Step 36
/*
"Would you like to start/stop recording milliseconds for [GAME NAME]"
*/
/*
	1. [Y]es
	2. [N]o
*/
bool M18_Question(bool repeat, vector <Game> data, int gameNum);
//Step 38
/*
"ARE YOU SURE you would like to start/stop recording milliseconds for [GAME NAME]"
*/
/*
	1. [Y]es
	2. [N]o
*/
bool M19_Question(bool repeat, vector <Game> data, int gameNum);



#endif // MENU_H

/*

----Files that are directly dependent on this file----
- menu.cpp

----Files this file is dependent on----
- game.cpp
- game.h
- Function.h
- Function.cpp

*/
