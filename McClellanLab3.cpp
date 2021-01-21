/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 3: Circle Calculation
*/

#include<iostream>
#include<cmath>

using namespace std;

//Functions
float DistanceCalc(float x1, float y1, float x2, float y2);
float RadiusCalc(float x1, float y1, float x2, float y2);
float CircumferenceCalc(float radius);
float AreaCalc(float radius);
void PrintResults(float radius);

int main()
{
	float x1, x2, y1, y2, radius, distance, circumference, area;
	
	//User Input
	cout << "Put in the center's value, X and Y, with a space in between:" << endl;	
	cin >> x1 >> y1;
	cout << endl;

	cout << "Put in another point on the circle, X and Y, with a space in between:" << endl;
	cin >> x2 >> y2;
	cout << endl;
	
	//Calculations
	radius = RadiusCalc(x1, x2, y1, y2);
	PrintResults(radius);
	return 0;
}

float DistanceCalc(float x1, float y1, float x2, float y2)
{
	float distance, temp;
	
	temp = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	distance = sqrt(temp);

	return distance;
}

float RadiusCalc(float x1,float y1, float x2, float y2)
{	

	return DistanceCalc(x1, y1, x2, y2);
}

float CircumferenceCalc(float radius)
{
	float circumference;

	circumference = 2 * 3.1416 * radius;

	return circumference;
}

float AreaCalc(float radius)
{
	float area;
	
	area = 3.1416 * pow(radius, 2);

	return area;
}

void PrintResults(float radius)
{
	float diameter = radius * 2;
	
	float circumference = CircumferenceCalc(radius);
	float area = AreaCalc(radius);		

	//Final Results
	cout << "Your circle's calculations are:" << endl;
	cout << "Radius: " << radius << endl;
	cout << "Diameter: " << diameter << endl;
	cout << "Circumference: " << circumference << endl;
	cout << "Area: " << area << endl;
}
