// tests basic soldier functionality
#include "Soldier.h"
#include "Peasant.h"
#include "Geometry.h"
#include "Utility.h"
#include <iostream>
using namespace std;

int main()
{
	Point david_home(10, 10);
	Point enemy_home(0,0);


	Soldier david("david", david_home);
	Soldier enemy("osama_bin_laden", enemy_home);

	david.describe();
	enemy.describe();
	// first try to kill the peasant
	try {
		david.start_attacking(&enemy);
	} catch (Error& e) {
		cout << "Should be an out of range error:\n";
		cout << e.what() << endl;;
	}
	// now move to the peasant
	david.move_to(enemy.get_location());
	// step.. step.. step..
	david.update(); david.update(); david.update();
	// im here!
	david.describe();
	// kill the peasant
	david.start_attacking(&enemy);
	// whee
	david.describe();
	// stab stab stab
	david.update(); david.update(); david.update();
	david.describe();
	for (int i = 0; i < 3; ++i) {
		enemy.describe();
		enemy.update();
	}
	
	cout << "Done!" << endl;
	return 0;
}