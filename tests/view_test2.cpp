// just tests a view a little further, can it print basic points all on the grid?
#include "View.h"
#include "Geometry.h"
using namespace std;

int main()
{
	Point origin(-10, -10);
	Point two(0, 0);
	Point three(2, 2);
	Point four(24, 0);
	View view;
	view.update_location("First", origin);
	view.update_location("Second", two);
	view.update_location("Third", three);
	view.update_location("Fourth", four);
	view.draw();
	return 0;
}
