#include "Town_Hall.h"
using namespace std;

Town_Hall::Town_Hall(const string& name_, Point location_)
:
name(name_),
location(location_.x, location_.y),
amount{0}
{
	cout << "Town_Hall " <<  << " constructed" << endl;
}

Town_Hall::~Town_Hall()
{
	cout << "Town_Hall " <<  << " destructed" << endl;	
}

void Town_Hall::deposit(double deposit_amount)
{
	amount += deposit_amount;
}

double withdraw(double amount_to_obtain)
{
	double amount_available = amount * .9;
	if (amount_available < 1.0)
		amount_to_obtain = 0;
	else if (amount_available < amount_to_obtain)
		amount_to_obtain = amount_availble;

	amount -= amount_to_obtain;
	return amount_to_obtain;

}

void Town_Hall::describe()
{
	cout << "Town_Hall " << Structure::describe();
	cout << "   Contains " << amount << endl;
}
