/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 5
*/

#include<iostream>

using namespace std;

class clockType
{
public:
	void setTime(int, int, int);
	void getTime(int&, int&, int&) const;
	void printTime() const;
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	bool equalTime(const clockType&) const;

private:
	int hr;
	int min;
	int sec;
};

int main()
{
	//Variables and Datatypes
	clockType clock1, clock2;
	int hours, minutes, seconds;

	//Setting up Clock 1 and 2
	clock1.setTime(7, 42, 15);
	clock2.setTime(3, 12, 47);
	
	cout << "Clock 1 has been set to: ";
	clock1.printTime();
	cout << endl;
	
	cout << "Clock 2 has been set to: ";
	clock2.printTime();
	cout << endl;
	
	//Incrementing by seconds
	clock1.incrementSeconds();
	clock2.incrementSeconds();

	cout << "Clock 1 has been incremented by a second, it is: ";
	clock1.printTime();
	cout << endl;
	
	cout << "Clock 2 has been incremented by a second, it is: ";
	clock2.printTime();
	cout << endl;

	//Incrementing by minutes
	clock1.incrementMinutes();
	clock2.incrementMinutes();
	
	cout << "Clock 1 has been incremented by a minute, it is: ";
	clock1.printTime();
	cout << endl;
	
	cout << "Clock 2 has been incremented by a minute, it is: ";
	clock2.printTime();
	cout << endl;

	//Incrementing by hours
	clock1.incrementHours();
	clock2.incrementHours();
	
	cout << "Clock 1 has been incremented by an hour, it is: ";
	clock1.printTime();
	cout << endl;

	cout << "Clock 2 has been incremented by an hour, it is: ";
	clock2.printTime();
	cout << endl;

	//Checking for equality and getTime
	if (clock1.equalTime(clock2))
	{
		cout << "Clock 1 and Clock 2 are the same." << endl;

		cout << "Clock 1: ";
		clock1.getTime(hours, minutes, seconds);
		cout << "Hours: " << hours << " Minutes: " << minutes << " Seconds: " << seconds << endl;

		cout << "Clock 2: ";
		clock2.getTime(hours, minutes, seconds);
		cout << "Hours: " << hours << " Minutes: " << minutes << " Seconds: " << seconds << endl;
	}
	else
	{
		cout << "Clock 1 and Clock 2 are different." << endl;
		
		cout << "Clock 1: ";
		clock1.getTime(hours, minutes, seconds);
		cout << "Hours: " << hours << " Minutes: " << minutes << " Seconds: " << seconds << endl;

		cout << "Clock 2: ";
		clock2.getTime(hours, minutes, seconds);
		cout << "Hours: " << hours << " Minutes: " << minutes << " Seconds: " << seconds << endl;
	}

	//Complete
	cout << "Testing complete." << endl;

}

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::printTime() const
{
	if (hr < 10)
		cout << "0";
	cout << hr << ":";

	if (min < 10)
		cout << "0";
	cout << min << ":";

	if (sec < 10)
		cout << "0";
	cout << sec;
}

void clockType::incrementHours()
{
	hr++;
	if (hr > 23)
		hr = 0;
}

void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
	{
		min = 0;
		incrementHours();
	}
}

void clockType::incrementSeconds()
{
	sec++;
	
	if (sec > 59)
	{
		sec = 0;
		incrementMinutes();
	}
}

bool clockType::equalTime(const clockType& otherClock) const
{
	return (hr == otherClock.hr
	&& min == otherClock.min
	&& sec == otherClock.sec);
}

void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;

	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;
	
	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}
