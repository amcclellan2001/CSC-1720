/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 7: Automobile Type Implementation File
*/
#ifndef automobileType_H
#define automobileType_H
#include<string>

using namespace std;

class automobileType
{
	public:
		void setProperties(float, float, float); 
		//Sets the variables to equal the class'
		
		string getInfoString() const; 
		//Displays the current info about the car
		
		void drive(float); 
		//Moves the car and calculates how much fuel is used, dependent on user input

		void setMaxFuelLevel(float);
		//Sets the max amount of fuel a vehicle can hold 

		void setProperties(float, float, float, float);
		//Constructor for setProperties if fourth value for max fuel is given

		void setProperties();
		//Constructor for setProperties if nothing is passed through
	
		automobileType(float, float, float, float);
		//Parameterized constructor for fuel, in order of miles, fuel, efficiency, and max fuel (in gallons)
		
		void addFuel(float);
		//Adds a set amount of fuel to the vehicle

		void setFuelLevel(float);
		//Sets the default fuel level as a function

		void setMileage(float);
		//Sets the default mileage as a function

		void setEfficiency(float);
		//Sets the default efficiency as a function

		float getOdometer();
		//Returns the value of the odometer back to main

		float getFuel();
		//Returns the amount of fuel back to main

		float getEfficiency();
		//Returns the efficiency level back to main

		const float DEFAULT_FUEL_LEVEL = 10;
		//Sets the default amount of fuel per vehicle

		const float DEFAULT_MAX_FUEL_LEVEL = 20;
		//Sets the default maximum amount of fuel per vehicle	

		const float DEFAULT_MILEAGE = 10000;
		//Sets the default mileage on the vehicle
	
		const float DEFAULT_EFFICIENCY = 30;
		//Sets the default efficiency on the vehicle
		
		automobileType();

		automobileType(float, float, float);
	
	protected:
		float miles;
		float fuel;
		float efficiency;
		float maxFuel;
		float errorCheck;
		float i;
};

#endif		
	
