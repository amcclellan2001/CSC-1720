/*
Alex McClellan
Dr. Titus
CSC-1720
Recursion Function Program
*/

#include<iostream>

using namespace std;

int Repower(int j, int k)
{
	int answer;
	
	//Display the current values of j and k
	cout << "The current values of J and K: ";
	cout << "J = " << j << ", K = " << k << endl;

	//Calculating the formula
	if (k < 0)
		answer = 1 / (j ^k);

	else
		answer = j * (j ^k);

	//Base condition
	if (k < -15)
	{
		cout << "K is out of range, ending loop." << endl;
		cout << "---------------------------------------------" << endl << endl;
	}

	//Loop continue
	else
	{
		cout << "Calculating " << j << " to the power of " << k << endl;
		cout << "The answer is " << answer << "." << endl << endl;

		k--;
		Repower(j, k);
	}
}


int main()
{
	int j, k, userInput = 1;

	//Looping program until user wants to exit
	do	
	{
		//Taking values for j and k
		cout << "What is the initial value of j?" << endl;		
		cin >> j;
	
		cout << "What is the initial value of k?" << endl;
		cin >> k;
		cout << endl;

		//Testing for j and k to be in range
		while (j < 1)
		{
			cerr << "J must be positive. (Greater than zero)" << endl;
			cerr << "Please enter a new value." << endl;
		
			cin >> j;
		}
	
		while (j > 50)
		{
			cerr << "J is too high of a number and will generate overflow errors." << endl;
			cerr << "Please enter a number between 1 and 50." << endl;
	
			cin >> j;
		}
	
		while (k > 15)
		{
			cerr << "K is too high of a number and will generate overflow errors." << endl;
			cerr << "Please enter a number between 15 to -15." << endl;
	
			cin >> k;
		}

		//Calculating formula		
		Repower(j, k);

		cout << "Would you like to continue or end the program?" << endl;
		cout << "Please enter 1 to continue, or 0 to quit." << endl;
	
		cin >> userInput;
	}

	while (userInput == 1);

	cout << "Quitting program." << endl;
	
	return 0;
}
