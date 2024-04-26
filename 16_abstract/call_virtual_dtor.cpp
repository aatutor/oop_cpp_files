#include <iostream>
using namespace std;

#define VIRTUAL_DTOR 0
#define CLEAR_VIRTUAL_DTOR 0


#if !VIRTUAL_DTOR && !CLEAR_VIRTUAL_DTOR
	struct A {
		~A() {
			cout << "~A\n";
		}
	};
#else
#if !CLEAR_VIRTUAL_DTOR
	struct A {
		virtual ~A() {
			cout << "~A\n";
		}
	};
#else
	struct A {
		virtual ~A() = 0;
	};
	A::~A() {
		cout << "~A\n";
	}
#endif
#endif

struct B : public A {
	~B() {
		cout << "~B\n";
	}
};

void TestBase(){
#if !CLEAR_VIRTUAL_DTOR
	{// v1
		A a;
	} // ~A
	{// v2
		A* pa = new A();
		delete pa; // ~A
	}
	// v3
	delete new A(); // ~A
#endif
}
void TestDerived(){
	{
		delete new B(); // ~B, ~A - always good
	}
	{
		A* pb = new B();
#if !VIRTUAL_DTOR && !CLEAR_VIRTUAL_DTOR
		delete pb; // ~A !?!
#else
		delete pb; // ~B, ~A
#endif
	}
}

int main() 
{
	TestBase();
	TestDerived();

	return 0;
}