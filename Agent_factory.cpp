#include "Agent_factory.h"
#include "Peasant.h"
#include "Soldier.h"
#include "Utility.h"
using namespace std;

Agent * create_agent(const string& name, const string& type, Point location)
{
	if (type == "Peasant") {
		return new Peasant(name, location);
	} else if (type == "Soldier") {
		return new Soldier(name, location);
	} else {
		throw Error("Trying to create agent of unknown type!");
	}
}
