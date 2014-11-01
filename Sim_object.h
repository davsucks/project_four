/* The Sim_object class provides the interface for all of simulation objects. 
It also stores the object's name, and has pure virtual accessor functions for 
the object's position and other information. */
#include <string>

class Sim_object {
public:
	Sim_object(const std::string& name_);
	~Sim_object();
	
	const std::string& get_name() const
		{return name;}
			
	// ask model to notify views of current state
    virtual void broadcast_current_state() {}
	virtual Point get_location() const = 0;
	virtual void describe() const = 0;
	virtual void update() = 0;

private:
	std::string name;
};

