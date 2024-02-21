#include <iostream>
using namespace std;

int main() {
	double a, b;
	while (true) {
		cout << "input: ";
		cin >> a;
		if (a == 0)
			break;

		cin >> b;
		if (b != 0)
			cout << (a / b) << endl;
		else
			cout << "Inf\n";
	}
}

// input: 1 2
// 0.5
// input: 2 0
// Inf           <-- b = 0
// input: 3 4
// 0.75
// input: 0
