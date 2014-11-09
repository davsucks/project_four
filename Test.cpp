// just tests a view a little further, can it print basic points with not
// all on the grid?
#include "View.h"
#include "Geometry.h"
using namespace std;

int main()
{
	Point origin(-10, -10);
	Point two(0, 0);
	Point three(2, 2);
	Point four(24, 0);
	Point five(50, 100);
	View view;
	view.set_scale(0.5);
	view.set_size(30);
	view.set_origin(Point(10.0, 10.0));
	view.update_location("First", origin);
	view.update_location("Second", two);
	view.update_location("Third", three);
	view.update_location("Fourth", four);
	view.update_location("Fifth", five);
	view.draw();
	return 0;
}
