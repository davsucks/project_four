// tests basic peasant behavior
#include "Peasant.h"
#include "Farm.h"
#include "Town_Hall.h"
#include "Geometry.h"
#include <iostream>
using namespace std;

int main()
{
	Point home(10, 10);
	Point farm_p(10, 15);
	Point town_hall_p(10, 5);

	Farm farm("DA FOOD PLACE", farm_p);
	Town_Hall town_hall("DA STORE PLACE", town_hall_p);
	Peasant david("david", home);

	david.describe();
	david.start_working(&farm, &town_hall);
	david.describe();
	cout << endl << "looping and working!" << endl; 
	for(int i = 0; i < 5; ++i) {
		david.update();
		david.describe();
	}
	
	cout << "Done!" << endl;
	return 0;
}