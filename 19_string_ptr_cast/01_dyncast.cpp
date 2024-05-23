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

template <class T>
void CheckPtr(T* ptr) {
	// если произошла ошибка - вернулся nullptr
	if (ptr) {
		throw "Error work!!!\n\n";
	}
	cout << "Good work - ";
	// иначе - произошло приведение
	ptr->Test();
}

int main()
{
	A *ptr_a, obj_a;

	B *ptr_b, obj_b;

	//приводим адрес объекта (&A) к указателю типа A*
	ptr_a = dynamic_cast<A*>(&obj_a);
	CheckPtr(ptr_a);

	ptr_b = dynamic_cast<B*>(&obj_b);
	CheckPtr(ptr_b);

	ptr_a = dynamic_cast<A*>(&obj_b);
	CheckPtr(ptr_a);
	
	try {
		//ВНИМАНИЕ!!! ЭТО НЕВОЗМОЖНО
		ptr_b = dynamic_cast<B*>(&obj_a); // warning: dynamic_cast of 'A obj_a' to 'class B*' can never succeed
		CheckPtr(ptr_b);
	}
	catch (const char* error) {
		cout << error;
	}
		
	return 0;
}
