#include <iostream>
using namespace std;

class A {};
class B {};

class C : public A, public B {};

#define COPY 0

class ParentOne {
protected:
	int one_ = 1;
};

class ParentTwo {
protected:
	int two_ = 2;
};

class Child : public ParentOne, public ParentTwo {
public:
#if COPY
	Child() = default;
	Child(ParentOne& par): ParentOne(par), ParentTwo() {}
#endif
	void Foo() {
		cout << one_ <<" "<< two_ << endl;
	}
	void Bar() {
		one_ = 3;
		two_ = 4;
	}
};

void TestPtr() {
	Child* chPrt = new Child(); // (1, 2)
	chPrt->Bar(); // (3, 4)

	ParentOne* parPrt = (ParentOne*)chPrt;
	Child* chPrt2 = (Child*)parPrt;
	chPrt2->Foo();	// 3 4
}

void TestCast() 
{
	Child ch; 
	ch.Bar(); // (3, 4)
	ch.Foo(); // 3 4

#if COPY
	ParentOne p1 = (ParentOne)ch;
	Child ch2 = (Child)p1;
#if !COPY
	Child ch2 = (Child)p1; // fail: no exists Child::Child(ParentOne&)
#endif

	ch2.Foo(); // 3 2 - wat?
#endif
}


int main ()
{
	TestPtr();
	cout << string(15, '-') << endl;
	TestCast();
	
	return 0;
}
