#include "Model.h"
#include "Structure.h"
#include "Structure_factory.h"
#include "Agent_factory.h"
#include "Agent.h"
#include "Sim_object.h"
#include <string>
#include <iostream>
#include <algorithm>
// using g_Model_ptr = Model *;
using namespace std;

// used to index into containers
struct Structure_Comp {
	bool operator()(Structure* lhs, string name) {
		return lhs->get_name() < name;
	}
} comp;

Model::Model()
{
	Structure* rivendale = create_structure("Rivendale", "Farm", Point(10., 10.));
	Structure* sunnybrook = create_structure("Sunnybrook", "Farm", Point(0., 30.));
	Structure* shire = create_structure("Shire", "Town_Hall", Point(20., 20.));
	Structure* paduca = create_structure("Paduca", "Town_Hall", Point(30., 30.));
	
	Agent* pippin = create_agent("Pippin", "Peasant", Point(5., 10.));
	Agent* merry = create_agent("Merry", "Peasant", Point(0., 25.));
	Agent* zug = create_agent("Zug", "Soldier", Point(20., 30.));
	Agent* bug = create_agent("Bug", "Soldier", Point(15., 20.));

	// insert into containers in alphabetical order
	sim_objs.push_back(bug);
	agent_objs.push_back(bug);
	sim_objs.push_back(merry);
	agent_objs.push_back(merry);
	sim_objs.push_back(paduca);
	structure_objs.push_back(paduca);
	sim_objs.push_back(pippin);
	agent_objs.push_back(pippin);
	sim_objs.push_back(rivendale);
	structure_objs.push_back(rivendale);
	sim_objs.push_back(shire);
	structure_objs.push_back(shire);
	sim_objs.push_back(sunnybrook);
	structure_objs.push_back(sunnybrook);
	sim_objs.push_back(zug);
	agent_objs.push_back(zug);

}

// destroy all objects
Model::~Model()
{
	for(Sim_object* i : sim_objs)
		delete i;
}

// is name already in use for either agent or structure?
// either the identical name, or identical in first two characters counts as in-use
bool Model::is_name_in_use(const string& name) const
{
	// TODO: implement this
	return false;
}

// is there a structure with this name?
bool Model::is_structure_present(const string& name) const
{
	// TODO: implement this
	return false;
}
// add a new structure; assumes none with the same name
void Model::add_structure(Structure*)
{

}
// will throw Error("Structure not found!") if no structure of that name
Structure* Model::get_structure_ptr(const string& name) const
{
	auto itr = lower_bound(structure_objs.begin(), structure_objs.end(), name, comp);
	if ((*itr)->get_name() == name)
		return *itr;
	else
		return nullptr;
}

// is there an agent with this name?
bool Model::is_agent_present(const string& name) const
{
	// TODO: implement this
	return true;
}
// add a new agent; assumes none with the same name
void Model::add_agent(Agent*)
{

}
// will throw Error("Agent not found!") if no agent of that name
Agent* Model::get_agent_ptr(const string& name) const
{
	// TODO: implement this
	Point home(10, 10);
	Agent me("david", home);
	return &me;
}

// tell all objects to describe themselves to the console
void Model::describe() const
{

}
// increment the time, and tell all objects to update themselves
void Model::update()
{

}

/* View services */
// Attaching a View adds it to the container and causes it to be updated
// with all current objects'location (or other state information.
void Model::attach(View*)
{

}
// Detach the View by discarding the supplied pointer from the container of Views
// - no updates sent to it thereafter.
void Model::detach(View*)
{

}
// notify the views about an object's location
void Model::notify_location(const string& name, Point location)
{

}
// notify the views that an object is now gone
void Model::notify_gone(const string& name)
{

}
