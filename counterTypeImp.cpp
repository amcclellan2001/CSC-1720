#include<iostream>
#include<iomanip>
#include "counterType.h"

using namespace std;

void counterType::initializeCounter() //Starts the counter at zero
{
	counter = 0;
}

void counterType::setCounter(int = 0) //Sets the counter to a given value, checks if programmer wants to use user input for the value, default to off
{
	bool userInput = false;	

	if (userInput == true)
	{
	cout << "What would you like to set the counter to?" << endl;
	cin >> counter;
	}
	
	if (counter < 0)
		counter = 0;
}

int counterType::getCounter() const //Get the current time in the counter as another variable
{
	cout << counter;
}

void counterType::incrementCounter() //Moves the counter up one
{
	counter++;
}

void counterType::decrementCounter() //Moves the counter down one, checks if number is below zero
{
	counter--;
	
	if (counter < 0)
		counter = 0;
}		

void counterType::displayCounter() const //Outputs the counter
{
	cout << "Counter = " << counter << endl; 
}

counterType::counterType(int) //Sets the counter to be an integer by default
{
	if (counter < 0)
		counter = 0;
	counter = counter3;
}

counterType::counterType()
{
	counter = counter3;
}
