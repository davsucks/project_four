#include "Model.h"
#include "View.h"
#include "Sim_object.h"
#include "Structure.h"
#include "Agent.h"
#include "Agent_factory.h"
#include "Structure_factory.h"
#include "Geometry.h"
#include "Utility.h"
#include <string>
#include <iostream>
#include <algorithm>
// using g_Model_ptr = Model *;
using namespace std;

Model* g_Model_ptr = nullptr;

Model::Model()
{
	// TODO: move away from hardcoded strings
	Structure* rivendale = create_structure("Rivendale", "Farm", Point(10., 10.));
	sim_objs.insert( pair<string, Sim_object*>("Rivendale", rivendale) );
	structure_objs.insert( pair<string, Structure*>("Rivendale", rivendale) );

	Structure* sunnybrook = create_structure("Sunnybrook", "Farm", Point(0., 30.));
	sim_objs.insert( pair<string, Sim_object*>("Sunnybrook", sunnybrook) );
	structure_objs.insert( pair<string, Structure*>("Sunnybrook", sunnybrook) );

	Structure* shire = create_structure("Shire", "Town_Hall", Point(20., 20.));
	sim_objs.insert( pair<string, Sim_object*>("Shire", shire) );
	structure_objs.insert( pair<string, Structure*>("Shire", shire) );

	Structure* paduca = create_structure("Paduca", "Town_Hall", Point(30., 30.));
	sim_objs.insert( pair<string, Sim_object*>("Paduca", paduca) );
	structure_objs.insert( pair<string, Structure*>("Paduca", paduca) );
	
	Agent* pippin = create_agent("Pippin", "Peasant", Point(5., 10.));
	sim_objs.insert( pair<string, Sim_object*>("Pippin", pippin) );
	agent_objs.insert( pair<string, Agent*>("Pippin", pippin) );

	Agent* merry = create_agent("Merry", "Peasant", Point(0., 25.));
	sim_objs.insert( pair<string, Sim_object*>("Merry", merry) );
	agent_objs.insert( pair<string, Agent*>("Merry", merry) );

	Agent* zug = create_agent("Zug", "Soldier", Point(20., 30.));
	sim_objs.insert( pair<string, Sim_object*>("Zug", zug) );
	agent_objs.insert( pair<string, Agent*>("Zug", zug) );

	Agent* bug = create_agent("Bug", "Soldier", Point(15., 20.));
	sim_objs.insert( pair<string, Sim_object*>("Bug", bug) );
	agent_objs.insert( pair<string, Agent*>("Bug", bug) );
}

// destroy all objects
Model::~Model()
{
	for(auto& i : sim_objs)
		delete i.second;
}

// is name already in use for either agent or structure?
// either the identical name, or identical in first two characters counts as in-use
bool Model::is_name_in_use(const string& name) const
{
	return sim_objs.find(name) != sim_objs.end();
}

// is there a structure with this name?
bool Model::is_structure_present(const string& name) const
{
	return structure_objs.find(name) != structure_objs.end();
}
// add a new structure; assumes none with the same name
void Model::add_structure(Structure* new_structure)
{
	sim_objs.insert( pair<string, Sim_object*>(new_structure->get_name(), new_structure));
	structure_objs.insert( pair<string, Structure*>(new_structure->get_name(), new_structure));
	new_structure->broadcast_current_state();
}


// will throw Error("Structure not found!") if no structure of that name
Structure* Model::get_structure_ptr(const string& name) const
{
	// invariant: index into structure_objs with the first
	// two chars of name
	auto structure_itr = structure_objs.find(name);
	if (structure_itr == structure_objs.end())
		throw Error("Structure not found!");
		
	return structure_itr->second;
}

// is there an agent with this name?
bool Model::is_agent_present(const string& name) const
{
	return agent_objs.find(name) != agent_objs.end();
}
// add a new agent; assumes none with the same name
void Model::add_agent(Agent* new_agent)
{
	sim_objs.insert( pair<string, Sim_object*>(new_agent->get_name(), new_agent));
	agent_objs.insert( pair<string, Agent*>(new_agent->get_name(), new_agent));
	new_agent->broadcast_current_state();
}
// will throw Error("Agent not found!") if no agent of that name
Agent* Model::get_agent_ptr(const string& name) const
{
	auto agent_itr = agent_objs.find(name);
	if(agent_itr == agent_objs.end())
		throw Error("Agent not found!");
	else
		return agent_itr->second;
}

// tell all objects to describe themselves to the console
void Model::describe() const
{
	for(auto& i : sim_objs)
		i.second->describe();
}
// increment the time, and tell all objects to update themselves
void Model::update()
{
	// add one to the time
	++time;
	// update all the Sim_objects alphabetically
	for(auto& i : sim_objs)
		i.second->update();
	// collect all the Agents that are disappearing, remove them from containers
	// and delete them in alphabetical order
	for(auto agent_itr = agent_objs.begin(); agent_itr != agent_objs.end(); ) {
		if(agent_itr->second->is_disappearing()) {
			// remove from the proper containers and delete
			string key = agent_itr->second->get_name();
			auto temp = agent_itr++;
			sim_objs.erase(key);
			agent_objs.erase(key);
			delete temp->second;
		} else
			++agent_itr;
	}
}

/* View services */
// Attaching a View adds it to the container and causes it to be updated
// with all current objects'location (or other state information.
void Model::attach(View* view)
{
	views.push_back(view);
	for(auto& i : sim_objs)
		i.second->broadcast_current_state();
}
// Detach the View by discarding the supplied pointer from the container of Views
// - no updates sent to it thereafter.
void Model::detach(View* view)
{
	views.remove(view);
}
// notify the views about an object's location
void Model::notify_location(const string& name, Point location)
{
	for(View* view : views)
		view->update_location(name, location);
}
// notify the views that an object is now gone
void Model::notify_gone(const string& name)
{
	for(View* view : views)
		view->update_remove(name);
}
