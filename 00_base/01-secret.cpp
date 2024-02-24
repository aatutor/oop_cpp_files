#include <iostream>
using namespace std;

double Div(double a, double b) {
  if (b == 0)
    return '???';

	return a / b;
}

int main() {
	double a, b;
	while (true) 
	{
		cout << "input: ";
		cin >> a;
		if (a == 0)
			break;
		cin >> b;

		double result = Div(a, b);    
		if (result != '???')
			cout << result << endl;
		else
			cout << "Inf\n";
	}
}
