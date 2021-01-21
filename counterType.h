/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 6
*/
#ifndef counterType_H
#define counterType_H

class counterType
{
	private:
		int counter;
		//Stores the count of the counter

		int counter2, counter3;
		//Saves these variables to test out functions
		
	public:
		void initializeCounter();
		//Starts the counter

		void setCounter(int);
		//Sets the counter to a given value
	
		int getCounter() const;
		//Get the current itme in the counter as a variable

		void incrementCounter();
		//Moves the counter up one

		void decrementCounter();
		//Moves the counter down one
		
		void displayCounter() const;
		//Outputs the counter

		counterType(int);
		//Sets the counter to be an integer by default

		counterType();
};
