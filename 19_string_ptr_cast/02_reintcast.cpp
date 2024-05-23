// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//базовый класс
struct A {
	virtual void Test() {
		cout << "Test A\n\n";
	}
};

struct B : A {
	void Test() override {
		cout << "Test B\n\n";
	}
};

int main()
{
	{
		A* ptrA = new A;
		ptrA->Test();
		B* ptrB = reinterpret_cast<B*>(ptrA);
		ptrB->Test();
	}
	int x = -5;
	unsigned int* y = reinterpret_cast<unsigned int*>(&x);
#if 0
	unsigned int y = reinterpret_cast<unsigned int>(x);
#endif
	*y -= 10;
	std::cout << *y << "\n";
	std::cout << x << "\n";

	return 0;
}
