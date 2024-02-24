#include <stdio.h>
#include <iostream>

void demo1()
{
	// if (b != 0)
	// 	cout << (a / b) << endl;
	// else
	// 	cout << "Inf\n";

	try {
		cout << Div(a, b) << endl;
	}
	catch(int error) {
		cout << "Inf\n";
	}
}

void demo2() 
{
#if 0
	if (b != 0)
		cout << (a / b) << endl;
	else
		cout << "Inf\n";
#else
	try {
		cout << Div(a, b) << endl;
	}
	catch(int error) {
		cout << "Inf\n";
	}
#endif
}