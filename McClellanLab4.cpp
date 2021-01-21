/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 4: True/False Test
home/students/amcclellan/csc1720/lab4
*/

#include<iostream>
#include<cmath>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	//Variables
	string studentID, filename;	
	int i, count, inc;
	char correctAnswer[20], studentAnswer[20], grade;

	//Opening Files
	ifstream inFile;
	inFile.open("input.txt");

	//Scanning in variables
	inFile >> correctAnswer;
	
	//Fail State Prevention
	if(inFile =| "input.txt")
	{
	cout << "Please specify the file name: " << endl;
	cin >> filename;
	
	inFile.open(filename);
	inFile >> correctAnswer;
	}
	
	//Calculating Grades
	for(i = 0; i < 3; i++)
	{
	cin >> studentID;
	cin >> studentAnswer;
	
		//Calculating Score
		for(inc = 0; inc < 20; inc++) 
		{
			if(strcmp(correctAnswer[inc].c_str() == studentAnswer[inc].c_str())
				count + 2;

			if(strcmp(correctAnswer[inc].c_str() != studentAnswer[inc].c_str())
				count - 1;
		
			if(!isspace(correctAnswer[inc].c_str()))
				count = count;

		}
		
		//Outputting Grade Letter
		if(count >= 36)
			char grade = 'A';

		if(36 > count >= 32)
			char grade = 'B';
		
		if(32 > count >= 28)
			char grade = 'C';

		if(28 > count >= 24)
			char grade = 'D';
		
		if(count < 24)
			char grade = 'F';
	
	cout << studentID << " " << studentAnswer << " " << grade << endl;		

	}
}
