// really straightforward test, just does some updating, withdrawing and depositing
// doesn't really test much of the deposit edge cases
#include "Town_Hall.h"
#include "Geometry.h"
#include <iostream>
using namespace std;

int main()
{
	Point home(55.4, 1);
	Town_Hall my_th("David's sexy town hall", home);
	my_th.describe();
	cout << "depositing 100" << endl;
	my_th.deposit(100);

	my_th.describe();
	cout << "withdrawing 25" << endl;
	my_th.withdraw(25);
	my_th.describe();

	cout << "depositing 25" << endl;
	my_th.deposit(25);
	my_th.describe();

	cout << "updating, depositing 5, and withdrawing 10" << endl;
	my_th.update();
	my_th.deposit(5);
	my_th.withdraw(10);
	my_th.describe();
	cout << "done" << endl;
	return 0;
}
