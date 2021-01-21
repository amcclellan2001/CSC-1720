/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 8: Hybrid Auto Type
*/
#ifndef hybridAutoType_H
#define hybridAutoType_H
#include "automobileType.h"

using namespace std;

class hybridAutoType: public automobileType
{
	public:
		void setChargeLevel(float);
		//Sets the charge level at the given float
	
		float getChargeLevel();
		//Prints and returns the charge level value

		void setChargeEfficiency(float);
		//Sets the efficiency level at the given float
	
		float getChargeEfficiency();
		//Prints and returns the efficiency value

		string getInfoString() const;

		void drive(float);
		//Moves the car and calculates the odometer for the hybridAutoType

		float setProperties(float, float, float, float, float);
		//Sets the properties with all parameters		
		
		static const bool GAS = true;
		static const bool ELECTRIC = !GAS;
		const float DEFAULT_CHARGE = 100;

		hybridAutoType();
		hybridAutoType(float, float, float, float, float);

	private:
		float hybridEfficiency;
		float hybridCharge;
		bool engineMode;
};

#endif
