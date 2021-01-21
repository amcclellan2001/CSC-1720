/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 8: Hybrid Objects
File Location: home/students/amcclellan/csc1720/lab8


Note: I keep getting a multiple definition error for the class, I imagine it has to do with how the include statements are set up, but I'm not sure on how thet are supposed to be.

*/

#include<iostream>
#include "automobileType.h"
#include "hybridAutoType.h"

using namespace std;

int main()
{
	//Variables
	float milesLeft, fuelLeft, overallEfficiency, hybridC, hybridE, drivingMiles, maxFuelLevel, miles, fuel, maxFuel, efficiency;
	string finalString;
		
	//Setting the cars up
	cout << "Setting the cars up: " << endl << endl;

	automobileType sedan;
	automobileType SUV;
	hybridAutoType tesla;


	sedan.setProperties(10000, 12.2, 33.3);
	SUV.setProperties(30000, 30, 17.8);	

	finalString = sedan.getInfoString();
	cout << finalString << endl;

	finalString = SUV.getInfoString();
	cout << finalString << endl << endl;
	
	//Setting maximum fuel and getting parameters
	cout << "Setting maximum fuel and returning parameters: " << endl << endl;
	
	sedan.setMaxFuelLevel(400);
	SUV.setMaxFuelLevel(450);

	cout << finalString;
	cout << endl << endl;

	cout << "Using the sedan to retrieve values from the class:" << endl << endl;
	cout << "Returning odometer to main: " << miles << endl;
	cout << "Returning fuel level to main: " << fuel << endl;
	cout << "Returning efficiency level to main: " << efficiency << endl;	
	cout << "Odometer: " << miles << " | Fuel: " << fuel << " | Efficiency: " << efficiency;
	cout << endl << endl;
	
	//Driving the cars
	cout << "Driving the Sedan: " << endl << endl;
	sedan.drive(40);
	
	cout << finalString;
	cout << endl << endl;
	
	cout << "Driving the SUV: " << endl << endl;
	SUV.drive(40);
	
	cout << finalString;	
	cout << endl << endl;

	//Testing Out of Gas condition
	cout << "Out of Gas and adding too much Fuel: " << endl << endl;
	
	sedan.setProperties(10040, 1, 33.3);
	sedan.drive(40);
	sedan.addFuel(100);	

	cout << finalString;
	cout << endl << endl;

	//Lowering the Odometer
	cout << "Trying to lower the odometer and setting parameters: " << endl << endl;
	
	sedan.setProperties(10080, 12.2, 33.3);
	sedan.setMileage(5000);

	sedan.setProperties(-5000, 12.2, 33.3);

	cout << finalString;
	cout << endl << endl;

	//Driving with lowered Odometer
	cout << "Trying to drive with lowered odometer: " << endl << endl;
	
	sedan.drive(20);

	cout << finalString;
	cout << endl << endl;

	//Initializing with Default Parameters and resetting Maximum Fuel
	cout << "Initializing with default parameters: " << endl << endl;
	
	sedan.setProperties();

	cout << finalString;
	cout << endl << endl;

	cout << "Trying to set maximum fuel again: " << endl << endl;
	sedan.setMaxFuelLevel(100);
	sedan.drive(20);

	cout << finalString;
	cout << endl << endl;

	//Resetting Efficiency
	cout << "Setting Efficiency lower than 1: " << endl << endl;

	sedan.setProperties();
	sedan.setEfficiency(-1);
	sedan.drive(20);
	
	cout << finalString;
	cout << endl << endl;

	//Resetting Fuel Level
	cout << "Setting Fuel Level lower than 1: " << endl << endl;
	
	sedan.setProperties();
	sedan.setFuelLevel(-1);
	sedan.drive(20);

	cout << finalString;
	cout << endl << endl;  

	cout << "Setting Fuel Level above maximum fuel and using get functions: " << endl << endl;
	
	sedan.setProperties();
	sedan.setFuelLevel(100);
	sedan.drive(20);

	sedan.getOdometer();   
	sedan.getFuel();
	sedan.getEfficiency(); 
	
	cout << "Odometer: " << miles << " | Fuel: " << fuel << " | Efficiency: " << efficiency;	
	cout << endl << endl;

	 //Driving in reverse
	cout << "Driving in reverse and using 4 parameters: " << endl << endl;

	sedan.setProperties(10000, 10, 30, 20);
	sedan.drive(-20);

	cout << finalString;
	cout << endl << endl;

	//Hybrid Initializing
	cout << "Testing the Tesla with an implicit Constructor: " << endl << endl;
	tesla.setProperties(20000, 20, 40, 100, 40);
	tesla.getInfoString();

	cout << finalString;
	cout << endl << endl;

	//Hybrid Charge and Efficiency Level Testing
	cout << "Testing the Tesla with getting efficiency and charge level: " << endl << endl;

	tesla.getChargeLevel();
	tesla.getChargeEfficiency();

	cout << "Setting new efficiency and charge level: " << endl << endl;

	tesla.setChargeLevel(100);
	tesla.setChargeEfficiency(40);

	tesla.getChargeLevel();
	tesla.getChargeEfficiency();

	//Hybrid Constructor Testing
	cout << "Testing the Tesla default constructor and parameterized constructor: " << endl << endl;

	cout << "Default Constructor: " << endl;
	tesla.setProperties(10000, 20, 40, 100, 40);
	
	tesla.getInfoString();
	
	cout << finalString;

	cout << "Parameterized Constructor: " << endl;
	tesla.setProperties(10000, 20, 40, 100, 40);

	tesla.getInfoString();
	
	cout << finalString;



		
	return 0;
}
