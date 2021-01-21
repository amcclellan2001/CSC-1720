/*
Alex McClellan
Dr. Titus
CSC 1720
Program 1: Basketball Team Manager



Notes: I have been having issues passing my struct for the variables into my function, and I have also had a lot of undeclared identifier errors.
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

struct playerData //Holds the variables for the players' information
{
	string playerName, playerPosition;
	int minutesPlayed, fouls;
	float fieldGoalPercentage, threePointPercentage, freeThrowPercentage;
};

void printMenu() //Prints the main menu
{
	cout << "Display one player: 1" << endl;
	cout << "Display all players: 2" << endl;
	cout << "Update the player stats: 3" << endl;
	cout << "Sort the list by minutes played: 4" << endl;
	cout << "Save the data to a file: 5" << endl;
	cout << "Quit Program: 6" << endl;
}

void userSelection(int userInput) //Allows the user to select what option they want in the menu
{
	cin >> userInput;
	
	if (userInput == 1)
		displaySinglePlayer(playerSelect, userInput);
	
	if (userInput == 2)
		displayAllPlayers(playerSelect, userInput);
	
	if (userInput == 3)
		syncUserData();
	
	if (userInput == 4)
		sortByMinutes(userInput);

	if (userInput == 5)
		saveData(userInput, playerData);

	if (userInput == 6)
		quitProgram(userInput);
	
	else
	{
		cout << "That is not a valid key. Please input a correct key." << endl;
		userSelection(userInput);
	}
}
	
void syncUserData(struct playerData) //Reads in the latest data given in the input file
{
	int i;
	playerData player[9];	
	
	for (i = 0; i < 9; i++)
	{
		cin >> player[i].playerName;
		cin >> player[i].playerPosition;
		cin >> player[i].minutesPlayed;
		cin >> player[i].fieldGoalPercentage;
		cin >> player[i].threePointPercentage;
		cin >> player[i].freeThrowPercentage;
		cin >> player[i].fouls;
	}
}

void printTitles() //Prints the top of the graph
{
	cout << "Name     Position     Minutes Played     Field Goal Percentage     3-Point Percentage     Free Throw Percentage     Fouls" << endl;
}

void getPlayerData(int playerSelect, struct playerData, playerData player[9]) //Prints the stats given to a player
{
	cout << player[playerSelect].playerName << "     "; 
	cout << player[playerSelect].playerPosition << "     "; 
	cout << player[playerSelect].minutesPlayed << "     ";
	cout << player[playerSelect].fieldGoalPercentage << "     ";
	cout << player[playerSelect].threePointPercentage << "     ";
	cout << player[playerSelect].freeThrowPercentage << "     ";
	cout << player[playerSelect].fouls << endl;
}	
	
void displaySinglePlayer(int playerSelect, int userInput) //Prints the stats of one player, then puts the user back at the menu
{
	cout << "What player would you like to view, in order of player from 1-10?" << endl;
	cin >> playerSelect;

	syncUserData(playerData);
	printTitles();
	getPlayerData(playerSelect, playerData);

	printMenu();
	userSelection(userInput);
}

void displayAllPlayers(int playerSelect, int userInput) //Prints the stats of all players, then puts the user back at the menu
{
	syncUserData(playerData);
	printTitles();
	
	for (playerSelect = 0; playerSelect < 9; playerSelect++)
		getPlayerData(playerSelect);

	printMenu();
	userSelection(userInput);
}

void sortByMinutes(playerSelect) //Sorts the graph by the amount of minutes played per player
{
	int i;

	syncUserData(playerData);
	printTitles();

	for (playerSelect = 0; playerSelect < 9; playerSelect++)
	{
		if (player[i].minutesPlayed > player[i+1].minutesPlayed)
			getPlayerData(playerSelect, playerData);

		else
		{
			playerSelect++;
			
			getPlayerData(playerSelect, playerData);
		
			playerSelect--;
		}
	}
}

void quitProgram(int userInput) //Asks the user if they want to save and quit the program
{
	int userInput;
	
	cout << "Would you like to quit the program and save the data? Yes = 1, No = 2" << endl;	
	cin >> userInput;

	if (userInput == 1)
	{
		saveData(userInput)
		break;
	}
	
	else
	{
		printMenu();
		syncUserData(playerData);
		userSelection(userInput);
	}	


void saveData(int userInput, struct playerData) //Saves the program, can or cannot close the program depending upon user selection
{	
	int i;

	outFile.open("McClellanBB.txt");
	
	for (i = 0; i < 9; i++)
	{
	outFile << player[i].playerName << " ";
	outFile << player[i].playerPosition << " ";
	outFile << player[i].minutesPlayed << " ";
	outFile << player[i].fieldGoalPercentage << " ";
	outFile << player[i].threePointPercentage << " ";
	outFile << player[i].freeThrowPercentage << " ";
	outFile << player[i].fouls << endl;
	}

	outFile.close("McClellanBB.txt");

	if (userInput =| 1)
	{
	printMenu();
	syncUserData(playerData);
	userSelection(userInput);
	}
	
	else
		continue;
}	

int main()
{
	//Variables
	char players[20][10];
	int userInput;	
	playerData player;	

	//Opening Files
	ifstream inFile;
	ofstream outFile;

	inFile.open("BBData.txt");
	outFile.open("McClellanBB.txt");

	//Menu Intro and printing it out
	cout << "Welcome to the McClean Basketball Team Manager 2020." << endl << "Please type in the key designated to access each option."
	printMenu();
	syncUserData();
	userSelection(userInput);
	
	//Closing files
	inFile.close("BBData.txt");
	outFile.close("McClellanBB.txt");
}

