#include <iostream>

struct Digit {
	char value; // 1-byte int
	Digit* next;
	// ...?
};

class BigNumber{
	Digit* top_ = nullptr;
public:
	...
	BigNumber operator+ (BigNumber& right);
	...
};

int main()
{
	BigNumber a("111222333444555666777888"), b("333222111");

	BigNumber c = a + b;

	std::cout << c << endl;

	return 0;
}
