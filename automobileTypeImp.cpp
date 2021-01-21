/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 7: automobileType Implementation File
*/
#include<iostream>
#include<string>
#include "hybridAutoType.h"

using namespace std;

automobileType::automobileType()
{	
	miles = 0;
	fuel = 0;
	efficiency = 0;
}
automobileType::automobileType(float milesLeft, float fuelLeft, float overallEfficiency)
{
	miles = milesLeft;
	fuel = fuelLeft;
	efficiency = overallEfficiency;
}
	
void automobileType::setProperties(float milesLeft, float fuelLeft, float overallEfficiency) //Sets the properties to the values given by miles, fuel, and efficiency
{
	setMileage(milesLeft);
	setFuelLevel(fuelLeft);
	setEfficiency(overallEfficiency);
	
	if (errorCheck =! 0)
	{
		cerr << "Errors present with parameters." << endl;
		cerr << "Current amount of errors: " << errorCheck << endl;
		cerr << "Replaced errors with default parameters." << endl;

		errorCheck = 0;
	}
}

void automobileType::setProperties(float milesLeft, float fuelLeft, float overallEfficiency, float maxFuelLevel) //Sets the properties if the max fuel level is provided in the constructor
{
	//Sets the maximum fuel level if provided
	setMaxFuelLevel(maxFuelLevel);
	setProperties(miles, fuel, efficiency);		
}

void automobileType::setProperties() //Sets the parameters to their default values if nothing is provided
{
	//Sets the members to the default values
	miles = DEFAULT_MILEAGE;
	fuel = DEFAULT_FUEL_LEVEL;
	efficiency = DEFAULT_EFFICIENCY;
	maxFuel = DEFAULT_MAX_FUEL_LEVEL;
}		

void automobileType::setMileage(float milesLeft)
{
	//Checks if odometer is being rolled back
	if (milesLeft < miles)
	{
		cerr << "You cannot lower the odometer." << endl;
		cerr << "Current odometer reading: " << miles << endl;
		cerr << "Proposed odometer reading: " << milesLeft << endl;
		cerr << "Using default value: " << DEFAULT_MILEAGE << endl;	
	
		miles = DEFAULT_MILEAGE;
		errorCheck++;
	}
	
	if (errorCheck == 0)
		miles = milesLeft;
}

void automobileType::setEfficiency(float overallEfficiency)
{
	//Checks if efficiency is being changed
	if (overallEfficiency < 1)
	{
		cerr << "You cannot have an efficiency level below 1." << endl;
		cerr << "Current efficiency level: " << efficiency << endl;
		cerr << "Proposed efficiency level: " << overallEfficiency << endl;
		cerr << "Using default value: " << DEFAULT_EFFICIENCY << endl;
		
		efficiency = DEFAULT_EFFICIENCY;
		errorCheck++;
	}
	
	if (errorCheck == 0)
		efficiency = overallEfficiency;
}

void automobileType::setFuelLevel(float fuelLeft)
{
	//Checks if the maximum fuel levels are less than one
	if (fuelLeft < 0.1)
	{
		cerr << "You cannot have a fuel level below 0.1." << endl;
		cerr << "Current fuel level: " << fuelLeft << endl;
		cerr << "Acceptable values are between: 0.1 and " << maxFuel << endl;	
		cerr << "Using default value: " << DEFAULT_FUEL_LEVEL << endl;
		
		fuelLeft = DEFAULT_FUEL_LEVEL;
		errorCheck++;
	}
	
	//Checks if the fuel levels are above what is set for the maximum fuel levels
	if (fuelLeft > maxFuel)
	{
		cerr << "You cannot fill past the maximum fuel level." << endl;
		cerr << "Current fuel level: " << fuelLeft << endl;
		cerr << "Acceptable values are between: 0.1 and " << maxFuel << endl;
		cerr << "Using default value: " << DEFAULT_FUEL_LEVEL << endl;

		fuelLeft = DEFAULT_FUEL_LEVEL;
		errorCheck++;
	}
	
	if (errorCheck == 0)
		fuel = fuelLeft;
}

void automobileType::setMaxFuelLevel(float maxFuelLevel)
{
	//Makes sure the maximum fuel level can only be set once
	if (i == 0) 
	{
		maxFuel = maxFuelLevel;
		i++;
	}
	
	else
	{
		cerr << "You cannot change the maximum fuel level once set." << endl;
		cerr << "Current maximum fuel level: " << maxFuel << endl;
		cerr << "Using default value: " << DEFAULT_MAX_FUEL_LEVEL << endl;

		maxFuel = DEFAULT_MAX_FUEL_LEVEL;
		errorCheck++;
	}
}

void automobileType::addFuel(float fuelAdd)
{
	//Adds a given amount of fuel to the vehicle
	fuel = fuel + fuelAdd;
	
	if (fuel > maxFuel)
	{
		cerr << "Adding too much fuel to the tank." << endl;
		cerr << "Current maximum fuel level: " << maxFuel << endl;
		cerr << "Proposed fuel level: " << fuel << endl;
		cerr << "Filling up to maximum fuel level." << endl;

		fuel = maxFuel;
	}

	cout << "Your new fuel level is: " << fuel << endl;
}		

string automobileType::getInfoString() const //Returns a string to main to print the member variables
{
	//Prints a string outputting private variable values
	string str1, str15, str2, str25, str3, str35, str4, str45, finalString;
	str15 = to_string(miles);
	str25 = to_string(fuel);
	str35 = to_string(efficiency);
	str45 = to_string(maxFuel);
	
	str1 = "Total Miles Driven: ";
	str2 = " | Gallons: ";
	str3 = " | MPG: ";
	str4 = " | Max Fuel: ";	
	finalString = str1 + str15 + str2 + str25 + str3 + str35 + str4 + str45;

	return finalString;	
}

float automobileType::getOdometer()
{
	return miles;
}

float automobileType::getFuel()
{
	return fuel;
}

float automobileType::getEfficiency()
{
	return efficiency;
}	

void automobileType::drive(float drivingMiles) //Drives the object vehicle
{
	float gallons, maxMiles, temp;
	
	setProperties(miles, fuel, efficiency);

	//If no value is given through call statement, automatically assigns 10 miles for trip
	if (drivingMiles == 0)
		drivingMiles = 10;

	//If traveling in reverse, adds to odometer
	if (drivingMiles < 0)
		drivingMiles = drivingMiles * -1;
			
	//Calculating gas left with miles given
	maxMiles = fuel * efficiency;
	maxMiles = maxMiles - drivingMiles;

	//Running out of Fuel and recalculating odometer
	if (maxMiles - drivingMiles < 0)
	{
		cout << "You are out of fuel." << endl;
		
		temp = maxMiles;
		temp = temp * -1;

		drivingMiles = drivingMiles - temp;
	}
	
	//Finishing calculations and saving to odometer
	gallons = maxMiles / efficiency;
	miles = miles + drivingMiles;

	//Final Trip Results
	cout << "Your odometer reads: " << endl;
	cout << "Total Miles Driven: " << miles << " | Range: " << maxMiles << " | Gallons: " << gallons << endl;
		
	errorCheck = 0;
};



