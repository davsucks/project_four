/* A Structure is a Sim_object with a location and interface to derived types */
#include <string>
#include <iostream>
#include "Geometry.h"

class Structure : Sim_object {
public:
	Structure(std::string _name, Point _location);

	virtual ~Structure() = 0;
		
	Point get_location()
	{return location;}

	void update(){/*noop*/};

	// output information about the current state
	void describe();

	// ask model to notify views of current state
    void broadcast_current_state();
    
	// fat interface for derived types	
	double withdraw(double amount_to_get)
	{return 0.0;}
	void deposit(double amount_to_give)
	{}

private:
	Point location;
};
