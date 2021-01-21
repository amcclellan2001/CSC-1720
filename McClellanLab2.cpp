/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 2
*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	//Variable declaration
	string firstName, lastName, department;
	float salary, bonus, taxes, paycheck, dist, traveltime, speed, coffeesold, costpercup, salesamount, temp, finalpaycheck;

	ifstream inFile;
	ofstream outFile;

	//Opening files
	inFile.open("inData.txt");
	outFile.open("outData.txt");

	//Name
	inFile >> firstName;
	outFile << "Name: " << firstName;

	inFile >> lastName;
	outFile << " " << lastName << " ";
	
	//Department
	inFile >> department;
	outFile << "Department: " << department << endl;

	//Salary, Bonus, and Taxes
	inFile >> salary;
	outFile << "Monthly Gross Salary: $" << salary << ", ";

	inFile >> bonus;
	outFile << "Monthly Bonus: " << bonus << "%, ";
	
	inFile >> taxes;
	outFile << "Taxes: " << taxes << "%" << endl;

	temp = bonus * 100;
	paycheck = salary * temp;
	finalpaycheck = paycheck * taxes; 
	outFile << fixed << setprecision(2) << "Paycheck: $" << finalpaycheck << endl;
	
	//Distance, Travel Time, and Speed
	inFile >> dist;
	outFile << "Distance Traveled: " << dist << ", ";

	inFile >> traveltime;
	outFile << "Traveling Time: " << traveltime << " hours" << endl;

	speed = dist / traveltime;
	outFile << "Average Speed: " << speed << " miles per hour" << endl;

	//Coffee Cups, Cost, and Sales
	inFile >> coffeesold;
	outFile << "Number of Coffee Cups Sold: " << coffeesold << ", ";

	inFile >> costpercup;
	outFile << "Cost: $" << costpercup << " per cup" << endl;

	salesamount = coffeesold * costpercup;
	outFile << "Sales Amount = $" << salesamount << endl;
	 	
	//Closing Files
	inFile.close();
	outFile.close();
	
}
	

