/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 6: Counter Class

Note: I keep getting a compiler error because of an undefined reference, and I can't find anything online to help me out.
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include "counterType.h"

using namespace std;

void initializeCounter();
void setCounter();
int getCounter();
void incrementCounter();
void decrementCounter();
void displayCounter();

int main()
{
	//Class and Variables
	counterType counter;	

	//Initialize and Get functions
	counter.initializeCounter();
	
	cout << "Initalize and Get Functions:" << endl;
	cout << "Counter = " ;
	counter.getCounter();
	cout << endl;

	//Set Counter and Display functions
	counter.setCounter(5);
	
	cout << "Set and Display Functions:" << endl;
	counter.displayCounter();

	//Increment Counter function		
	counter.incrementCounter();
	
	cout << "Increment Function:" << endl;
	counter.displayCounter();

	//Decrement Counter function
	counter.decrementCounter();

	cout << "Decrement Function:" << endl;
	counter.displayCounter();

	//Setting the Counter Below Zero
	counter.setCounter(0);

	cout << "Counter Below Zero:" << endl;
	counter.displayCounter();

	//Decrementing Below Zero
	counter.initializeCounter();
	
	cout << "Counter Decrementing Below Zero:" << endl;
	counter.decrementCounter();
	counter.displayCounter();

	//Final Message
	cout << "Testing complete." << endl;
}
