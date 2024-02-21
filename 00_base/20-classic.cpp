#include <stdio.h>
#include <iostream>

double Div(double a, double b)
{
	if (b == 0)
		throw 1;

	return a / b;
}

int main () {
	/// main ↓
	// cout << Div(1, 2) << endl;
	// cout << Div(3, 4) << endl;
	// cout << Div(0, 1) << endl;
	// cout << Div(1, 0) << endl; 

	double a, b;
	while (true) {
		cout << "input: ";
		cin >> a;
		if (a == 0)
			break;
		cin >> b;
		try {
			cout << Div(a, b) << endl;
		}
		catch(int error) {
			cout << "Inf\n";
		}
	} /// end main
}