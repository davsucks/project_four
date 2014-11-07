#include "View.h"
#include "Geometry.h"
#include "Utility.h"
#include <math.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

static const int def_size_c {25};
static const double def_scale_c {2.0};
static const double def_origin_x_c {-10.0};
static const double def_origin_y_c {-10.0};

// default constructor sets the default size, scale, and origin
View::View()
:
size {def_size_c},
scale {def_scale_c},
origin(def_origin_x_c, def_origin_y_c)
{ }

// Save the supplied name and location for future use in a draw() call
// If the name is already present,the new location replaces the previous one.
void View::update_location(const std::string& name, Point location)
{
	object_list[name] = location;
}

// Remove the name and its location; no error if the name is not present.
void View::update_remove(const std::string& name)
{
	object_list.erase(name);
}

// prints out the current map
void View::draw()
{
	// first populate an empty grid
	vector< vector<string>> grid (size, vector<string>(size, ". "));
	vector<string> outside;
	// populate grid/outside with proper names and locations
	int ix = 0;
	int iy = 0;
	for (auto& i : object_list) {
		ix = i.second.x;
		iy = i.second.y;
		if (!get_subscripts(ix, iy, i.second)) {
			// isn't present in the grid, need to add it to the outside container
			auto insert_itr = lower_bound(outside.begin(), outside.end(), i.first);
			outside.insert(insert_itr, i.first);
		} else {
			// is in the grid so add to grind!
			// TODO: which looks better?
			// TODO: this:
			// if (grid[iy][ix] != ". ") {
			// 	// a name is already in this cell
			// 	grid[iy][ix] = "* ";
			// } else {
			// 	grid[iy][ix] = i.first;
			// }
			// TODO: or this?
			const int beginning_c = 0;
			const int max_char_c = 2;
			grid[iy][ix] = (grid[iy][ix] == ". " ? i.first.substr(beginning_c, max_char_c) : "* ");
		}
	}
	// then print everything
	cout << "Display size: " << size << ", scale: " << scale << ", origin: " << origin << endl;
	// print everyone who's outside of the grid
	if (outside.size()) {
		ostringstream ss;
		copy(outside.begin(), outside.end() - 1, ostream_iterator<string>(ss, ", "));
		ss << outside.back();
		cout << ss.str();
		cout << " outside the map" << endl;
	}
	// print the grid
	const int label_freq_c = 3;
	for (int y = size - 1; y >= 0; --y) {
		if (y % label_freq_c == 0) {
			// store the label
			int label = (y * scale) + origin.y;
			// save old settings
			ios::fmtflags old_settings = cout.flags();
			// actually print the label
			cout << setw(4) << fixed << label << " ";
			// resore old settings
			cout.flags(old_settings);
		} else {
			cout << "     ";
		}
		for (int x = 0; x < size; ++x) {
			cout << grid[y][x];
		}
		cout << endl;
	}
	// now print labels for the last row
	// TODO: refactor all this shite
	for (int x = 0; x < size; x += 3) {
		int label = (x * scale) + origin.x;
		// save old settings
		ios::fmtflags old_settings = cout.flags();
		// actually print the label
		cout << "  " << setw(4) << fixed << label;
		// restore old settings
		cout.flags(old_settings);
	}
	cout << endl;
}

// Discard the saved information - drawing will show only a empty pattern
void View::clear()
{
	object_list.clear();
}

// modify the display parameters
// if the size is out of bounds will throw Error("New map size is too big!")
// or Error("New map size is too small!")
static const int max_size_c = 30;
static const int min_size_c = 6;
void View::set_size(int size_)
{
	if (size_ > max_size_c)
		throw Error("New map size is too big!");
	if (size_ <= min_size_c)
		throw Error("New map size is too small!");
	size = size_;
}

// If scale is not postive, will throw Error("New map scale must be positive!");
void View::set_scale(double scale_)
{
	if (scale_ <= 0)
		throw Error("New map scale must be positive!");
	scale = scale_;
}

// any values are legal for the origin
void View::set_origin(Point origin_)
{
	origin = origin_;
}

// set the parameters to the default values
void View::set_defaults()
{
	size = def_size_c;
	scale = def_scale_c;
	origin = Point(def_origin_x_c, def_origin_y_c);
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
