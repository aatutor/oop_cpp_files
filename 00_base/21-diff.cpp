#include <stdio.h>
#include <iostream>

void Menu()
{
	double a, b;
	while (true) {
		cout << "input: ";
		cin >> a;
		if (a == 0) break;
		cin >> b;
		try {
			cout << Div(a, b) << endl;
		}
		catch(int error) {
			cout << "Inf\n";
		}
	}
}

void Test()
{
	cout << Div(1, 2) << endl;
	cout << Div(3, 4) << endl;
	cout << Div(0, 1) << endl;
	cout << Div(1, 0) << endl;
}

int main ()
{
	// Test();
	Menu();

	return 0;									
}
