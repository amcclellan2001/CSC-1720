/*
Alex McClellan
Dr. Titus
CSC 1720
1 May 2020
Program 5: Card Guessing Game
Note: The program seg faults when I try to return deck.top() or try to assign that value to another string
*/

#include<iostream>
#include<stack>
#include<string>
#include<stdlib.h> 

using namespace std;

void createDeck(stack <string> deck)
{
	//Creates Deck with strings
	for (int i; i < 4; i++)
	{		
		deck.push("2");
		deck.push("3");
		deck.push("4");
		deck.push("5");
		deck.push("6");
		deck.push("7");
		deck.push("8");
		deck.push("9");
		deck.push("10");
		deck.push("Jack");
		deck.push("Queen");
		deck.push("King");
		deck.push("Ace");
	}
}


void shuffleDeck(stack <string> deck)
{
	int n;
	string temp;

	//Shuffling the deck
	for (int i = 0; i < 5; i++)
	{
		n = rand() % 20 + 5;

		//Holds onto the top element and deck is switched around
		for (n; n > 0; n--)
		{
			temp = deck.top();
			deck.pop();
			deck.push(temp);
		}
	}
}

void drawValue(stack <string> deck, string userGuess)
{
	//Checks what is on deck.top() and displays draw to the user
	cout << "You have drawn a " << deck.top() << "."  << endl;
	
	//Compares to what the user guessed
	cout << "You guessed: " << userGuess << endl;

	if (deck.top() == userGuess)
		cout << "You guess was correct!" << endl;

	else
		cout << "Your guess was incorrect." << endl;
}

void drawSuit(stack <string> deck, string userString)
{
	int n;
	string suit;

	//Randomizes suit with rand()
	n = rand() % 52 + 1;

	if (n > 0 && n < 14)
		suit = "Hearts";

	else if (n > 13 && n < 27)
		suit = "Diamonds";
	
	else if (n > 26 && n < 40)
		suit = "Spades";

	else
		suit = "Clubs";	

	//Compares what the user has drawn to their guess
	cout << "You guessed: " << userString << endl;

	if (userString == suit)
	{
		cout << "Your guess was correct!" << endl;
		cout << "The suit was " << suit << "." << endl;
	}

	else
	{
		cout << "Your guess was incorrect." << endl;
		cout << "The suit was " << suit << "." << endl;
	}
}

int main()
{		
	//Variables and objects
	stack<string> deck;
	int userInput;
	string userGuess, userString;

	cout << "Welcome to the Card Guessing Game!" << endl;

	do
	{
		//Ask user what they would like to guess
		cout << "What would you like to play?" << endl;
		cout << "Enter 1 to guess the suit, enter 2 to guess the value, or enter 3 to guess the suit and value." << endl;
		
		cin >> userInput;	
		
		//Makes sure the user entered an appropriate value
		while (userInput > 3 || userInput < 1)
		{
			cout << "Please enter either 1 to guess the suit, 2 to guess the value, or 3 to guess the suit and value." << endl;
			cin >> userInput;
		}

		//Shuffles and makes the Deck
		createDeck(deck);
		shuffleDeck(deck);

		//If the user wants to guess the suit
		if (userInput == 1)
		{
			cout << "Please enter the suit. (Hearts, Diamonds, Spades, Clubs)" << endl;
			cin >> userString;

			drawSuit(deck, userString);
		}
		
		//If the user wants to guess the value
		else if (userInput == 2)
		{
			cout << "Please enter the value. (Face Cards: Jack, Queen, King, Ace)" << endl;
			cin >> userGuess;
			
			drawValue(deck, userGuess);
		}

		//If the user wants to guess both
		else if (userInput == 3)
		{
			cout << "Please enter the suit. (Hearts, Diamonds, Spades, Clubs)" << endl;
			cin >> userString;
		
			cout << "Please enter the value. (Face Cards: Jack, Queen, King, Ace)" << endl;
			cin >> userGuess;
		
			drawSuit(deck, userString);
			drawValue(deck, userGuess);
		}

		//Ask the user if they want to continue playing
		cout << "Would you like to play again?" << endl;
		cout << "Enter 1 to play again, enter any other key to exit." << endl;

		cin >> userInput;
	}
	while (userInput == 1);

	return 0;
}
