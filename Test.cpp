// just tests a view a little further, can it print basic points with not
// all on the grid?
#include "View.h"
#include "Model.h"
#include <iostream>
using namespace std;

int main()
{
	Model my_model;
	View my_view;
	View my_other_view;

	cout << endl << endl;
	my_model.attach(&my_view);
	my_model.attach(&my_other_view);

	cout << endl << endl;
	my_model.detach(&my_view);
	my_model.detach(&my_other_view);

	return 0;
}
