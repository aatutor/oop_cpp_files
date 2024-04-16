#include <iostream>

struct Node {
	char val; // 1-byte int
	Node* next;
	// ...?
};

class BigNumber{
	Node* top_ = nullptr;
public:
	...
	BigNumber operator+ (BigNumber& right);
	...
}

int main()
{
	BigNumber a("111222333444555666777888"), b("333222111");

	BigNumber c = a + b;

	std::cout << c << endl;

	return 0;
}
