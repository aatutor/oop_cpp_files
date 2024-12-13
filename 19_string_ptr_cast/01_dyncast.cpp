// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//базовый класс
struct A {
	virtual void Test() {
		std::cout << "Test A\n";
	}
};

struct B : A {
	void Test() override {
		std::cout << "Test B\n";
	}
};

template <class T, class U>
void CheckCast(U* ptr) {
	T* temp = dynamic_cast<T*>(ptr);
	if (temp != nullptr)
		temp->Test();
}

int main()
{
	A obj_a;
	B obj_b;

	//приводим адрес объекта (&A) к указателю типа A*	
	CheckCast<A>(&obj_a);

	CheckCast<B>(&obj_b);

	CheckCast<A>(&obj_b);

	CheckCast<B>(&obj_a); // это невозможно

	return 0;
}
