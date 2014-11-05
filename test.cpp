#include "Farm.h"
#include "Geometry.h"
#include <iostream>
using namespace std;

int main()
{
	Point home(55.4, 1);
	Farm my_farm("David's sexy farm", home);
	my_farm.describe();
	cout << "updating" << endl;
	my_farm.update();

	my_farm.describe();
	cout << "withdrawing 25.75" << endl;
	my_farm.withdraw(25.75);
	my_farm.describe();

	cout << "updating" << endl;
	my_farm.update();
	my_farm.describe();

	cout << "updating and withdrawing 10" << endl;
	my_farm.update();
	my_farm.withdraw(10);
	my_farm.describe();
	cout << "done" << endl;
	return 0;
}
