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
	Point peasant_home(20, 20);


	Soldier david("david", david_home);
	Peasant victim("bernie", peasant_home);

	david.describe();
	victim.describe();
	// first try to kill the peasant
	try {
		david.start_attacking(&victim);
	} catch (Error& e) {
		cout << "Should be an out of range error:\n";
		cout << e.what() << endl;;
	}
	// now move to the peasant
	david.move_to(victim.get_location());
	// step.. step.. step..
	david.update(); david.update(); david.update();
	// im here!
	david.describe();
	// kill the peasant
	david.start_attacking(&victim);
	// whee
	david.describe();
	// stab stab stab
	david.update(); david.update(); david.update();
	david.describe();
	for (int i = 0; i < 3; ++i) {
		victim.describe();
		victim.update();
	}
	
	cout << "Done!" << endl;
	return 0;
}