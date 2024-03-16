#include <stdio.h>
#include <iostream>

void Test()
{
	double x = Div(1, 1);
	cout << x << endl;

	double y = Div(0.0, 3.1);
	cout << y << endl;

	try {
		double z = Div(1, 0);
	} catch (int msg) {
		cout << msg << endl;
	}

	{
		double x = Div(1, 1);
		cout << x << endl;
	}
	{
		double y = Div(0.0, 3.1);
		cout << y << endl;
	}
	{
		try {
			double z = Div(1, 0);
		} catch (int msg) {
			cout << msg << endl;
		}
	}
}


int main ()
{
	Test();

	return 0;								
}
