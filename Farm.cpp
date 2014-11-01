#include "Farm.h"
using namespace std;

Farm::Farm(string& name_, Point location_)
: 
name(name_),
location(location_.x, location_.y),
amount{50},
production_rate{2}
{
	cout << "Farm " <<  << " constructed" << endl;
}

Farm::~Farm()
{
	cout << "Farm " <<  << " destructed" << endl;	
}

double Farm::withdraw(double amount_to_get)
{
	if (amount_to_get > amount)
		amount_to_get = amount;

	amount -= amount_to_get;
	return amount_to_get;
}

void Farm::update()
{
	amount += production_rate;
	cout << "Farm " <<  << " now has " << << endl;
}

void Farm::describe()
{
	cout << "Farm " << Structure::describe();
	cout << "   Food available: " <<  << endl;
}
