// this just tests basic agent functionality
// note: Agent needs to be a concrete class for this test to work
// 		 so be sure to move its constructor to make it a public member
#include "Agent.h"
#include "Geometry.h"
#include <cassert>
#include <iostream>
using namespace std;

int main()
{
	Point home(10, 10);
	Agent my_agent("David", home);
	my_agent.describe();
	assert(my_agent.is_alive());
	cout << "get_location == " << my_agent.get_location();
	cout << "moving to (20, 15)" << endl;
	my_agent.move_to(Point(20, 15));
	cout << endl;
	cout << "updating 5 times" << endl;
	for(int i = 0; i < 5; ++i) {
		my_agent.update();
		my_agent.describe();
	}
	cout << endl;
	cout << "testing stop()" << endl;
	my_agent.move_to(Point(20, 0));
	my_agent.update();
	my_agent.describe();
	my_agent.stop();
	my_agent.describe();
	cout << "=============" << endl << "testing health" << endl;
	my_agent.take_hit(1, nullptr);
	my_agent.describe();
	my_agent.take_hit(3, nullptr);
	my_agent.describe();
	my_agent.take_hit(10, nullptr); 
	my_agent.describe();
	for(int i = 0; i < 3; ++i) {
		my_agent.update();
		my_agent.describe();
	}
	cout << "Done!" << endl;
	return 0;
}
