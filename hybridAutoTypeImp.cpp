/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 8: Hybrid Auto Type Implementation File
*/
#include "automobileTypeImp.cpp"

using namespace std;

hybridAutoType::hybridAutoType() //Default constructor
{
	miles = 0;
	fuel = 0;
	efficiency = 0;
	hybridCharge = 100;
	hybridEfficiency = 40;
}

hybridAutoType::hybridAutoType(float milesLeft, float fuelLeft, float overallEfficiency, float hybridC, float hybridE) //Parameterized constructor
{
	miles = milesLeft;
	fuel = fuelLeft;
	efficiency = overallEfficiency;	
	hybridCharge = hybridC;
	hybridEfficiency = hybridE;
	bool engineMode = !GAS;
}

float hybridAutoType::setProperties(float milesLeft, float fuelLeft, float overallEfficiency, float hybridC, float hybridE)
{
	miles = milesLeft;
	fuel = fuelLeft;
	efficiency = overallEfficiency;
	hybridCharge = hybridC;
	hybridEfficiency = hybridE;
	bool engineMode = !GAS;
}

void hybridAutoType::setChargeLevel(float hybridC)
{
	if (hybridCharge < 0.1)
	{
		cerr << "You have no charge left." << endl;
		cerr << "Current charge level: " << hybridCharge << endl;
		cerr << "Using default value: " << DEFAULT_CHARGE << endl;
	
		hybridCharge = DEFAULT_CHARGE;
	}
	
	else
		hybridCharge = hybridC;
}

float hybridAutoType::getChargeLevel()
{
	cout << "Hybrid Charge Level: " << hybridCharge << endl;

	return hybridCharge;
}

void hybridAutoType::setChargeEfficiency(float hybridE)
{
	if (hybridEfficiency < 1)
	{
		cerr << "You cannot have an efficiency level below 1." << endl;
		cerr << "Current efficiency level: " << hybridEfficiency << endl;
		cerr << "Using default value: " << DEFAULT_EFFICIENCY << endl;

		hybridEfficiency = DEFAULT_EFFICIENCY;
	}
	
	else
		hybridEfficiency = hybridE;
}


float hybridAutoType::getChargeEfficiency()
{
	cout << "Hybrid Efficiency: " << hybridEfficiency << endl;

	return hybridEfficiency;
}

string hybridAutoType::getInfoString() const
{
	string str5, str55, str6, str65, finalString;

	str55 = to_string(hybridCharge);
	str65 = to_string(hybridEfficiency);
	
	str5 = " | Hybrid Charge Level: ";
	str6 = " | Hybrid Efficiency: ";

	automobileType::getInfoString();
	
	finalString = finalString + str5 + str55 + str6 + str65;

	return finalString;
}

void hybridAutoType::drive(float drivingMiles) //Drives the Hybrid object vehicle
{
	float maxMiles, temp;
	string finalString;
	
	//If car is in gas mode, call gas driving mode
	if (engineMode = GAS)
		automobileType::drive(drivingMiles);

	//If no value is given through call statement, automatically assigns 10 miles for trip
	if (drivingMiles == 0)
		drivingMiles = 10;

	//If traveling in reverse, adds to odometer
	if (drivingMiles < 0)
		drivingMiles = drivingMiles * -1;
			
	//Calculating gas left with miles given
	maxMiles = hybridCharge * hybridEfficiency;
	maxMiles = maxMiles - drivingMiles;

	//Running out of Fuel and recalculating odometer
	if (maxMiles - drivingMiles < 0)
	{
		cout << "You are out of charge." << endl;
		
		temp = maxMiles;
		temp = temp * -1;

		drivingMiles = drivingMiles - temp;
	}
	
	//Finishing calculations and saving to odometer
	hybridCharge = (maxMiles / hybridEfficiency) * 0.10;
	miles = miles + drivingMiles;
	
	//Printing trip results
	hybridAutoType::getInfoString();
	
	cout << finalString;
};
