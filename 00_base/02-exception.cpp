#include <iostream>
using namespace std;

double Div(double a, double b) {
  if (b == 0)
    throw 1;

	return a / b;
}

int main() {
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
	}
}