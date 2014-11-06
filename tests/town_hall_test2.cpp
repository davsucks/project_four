// tests more of the deposit edge-cases
#include "Town_Hall.h"
#include "Geometry.h"
#include <iostream>
using namespace std;

int main()
{
	Point home(55.4, 1);
	Town_Hall my_th("David's sexy town hall", home);
	my_th.describe();
	cout << "depositing 1" << endl;
	my_th.deposit(1);

	my_th.describe();
	cout << "withdrawing 1" << endl;
	my_th.withdraw(1);
	my_th.describe();

	cout << "depositing 25" << endl;
	my_th.deposit(25);
	my_th.describe();

	cout << "withdrawing 50" << endl;
	my_th.withdraw(50);
	my_th.describe();
	cout << "done" << endl;
	return 0;
}
