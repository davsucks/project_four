#include "Structure.h"
using namespace std;

Structure::Structure(std::string name_, Point location_)
:
name(name_),
location(location_.x, location_.y)
{
		cout << "Structure " << name << " constructed" << endl;
}
Structure::~Structure()
{
	cout << "Structure " << name << " destructed" << endl;
}

void Structure::describe()
{
	cout << name << " at " << location << endl;
}
