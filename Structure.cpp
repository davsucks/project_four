#include "Structure.h"
using namespace std;

Structure::Structure(std::string _name, Point _location)
	: name(_name), location(_location.x, _location.y)
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
