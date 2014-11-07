#include "View.h"
#include "Geometry.h"
#include <math.h>
using namespace std;

static int def_size {25};
static double def_scale {2.0};
static double def_origin_x {-10.0};
static double def_origin_y {-10.0};

// default constructor sets the default size, scale, and origin
View::View()
:
size {def_size},
scale {def_scale},
origin(def_origin_x, def_origin_y)
{ }

// Save the supplied name and location for future use in a draw() call
// If the name is already present,the new location replaces the previous one.
void View::update_location(const std::string& name, Point location)
{

}

// Remove the name and its location; no error if the name is not present.
void View::update_remove(const std::string& name)
{

}

// prints out the current map
void View::draw()
{

}

// Discard the saved information - drawing will show only a empty pattern
void View::clear()
{

}

// modify the display parameters
// if the size is out of bounds will throw Error("New map size is too big!")
// or Error("New map size is too small!")
void View::set_size(int size_)
{

}

// If scale is not postive, will throw Error("New map scale must be positive!");
void View::set_scale(double scale_)
{

}

// any values are legal for the origin
void View::set_origin(Point origin_)
{

}

// set the parameters to the default values
void View::set_defaults()
{

}

// Calculate the cell subscripts corresponding to the supplied location parameter, 
// using the current size, scale, and origin of the display. 
// This function assumes that origin is a  member variable of type Point, 
// scale is a double value, and size is an integer for the number of rows/columns 
// currently being used for the grid.
// Return true if the location is within the grid, false if not

bool View::get_subscripts(int &ix, int &iy, Point location)
{
	// adjust with origin and scale
	Cartesian_vector subscripts = (location - origin) / scale;
	// truncate coordinates to integer after taking the floor
	// floor function will return the largest integer smaller than the supplied value
	// even for negative values, so -0.05 => -1., which will be outside the array.
	ix = int(floor(subscripts.delta_x));
	iy = int(floor(subscripts.delta_y));
	// if out of range, return false
	if ((ix < 0) || (ix >= size) || (iy < 0) || (iy >= size)) {
		return false;
		}
	else
		return true;
}
