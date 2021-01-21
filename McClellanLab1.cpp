/*
Name: Alex McClellan
Prof: Dr. Titus
Class: CSC 1720
Lab 1
*/

#include<iostream>

using namespace std;

int main()
{
	float hourlyrate, taxrate = 14, temp, incomebefore, incomeafter, clothes = 10, supplies = 1, bonds = 25;
	int hours;

	cout << "Hello World!" << endl;
	
	//Scanning in variables
	cout << "What is your payrate per hour?" << endl;
	cin >> hourlyrate;
	
	cout << "How many hours a week do you work?" << endl;
	cin >> hours;
	
	//Income Calculation
	incomebefore = hourlyrate * hours;
	temp = incomebefore * (taxrate / 100);
	incomeafter = incomebefore - temp;
	
	cout << "Your income before taxes is: " << incomebefore << endl;
	cout << "Your income after taxes is: " << incomeafter << endl;

	//Clothes
	temp = incomeafter * (clothes / 100);
	incomeafter = incomeafter - temp;
	 
	cout << "After charging 10 percent for clothes: " << incomeafter << endl;
	
	//School Supplies
	temp = incomeafter * (supplies / 100);
	incomeafter = incomeafter - temp;

	cout << "After charging 1 percent for school supplies: " << incomeafter << endl;

	//Savings Bonds
	temp = incomeafter * (bonds / 100);
	incomeafter = incomeafter - temp;

	cout << "After charging 25 percent for savings bonds: " << incomeafter << endl;

	//Parents' Bonds
	incomeafter = (incomeafter / 1) * 0.50;

	cout << "How much the parents spent on savings bonds: " << incomeafter << endl;

	return 0;

}
