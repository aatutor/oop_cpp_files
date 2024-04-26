#include <iostream>
using namespace std;

class Parent {
public:
	void Foo() {
		cout << "Parent::Foo\n";
	}
};
class Child : public Parent {
public:
	void Foo() {
		cout << "Child::Foo\n";
	}
	void Bar() {
		cout << "Child::Bar\n";
	}
};

void TestAccess() {
	{
		Parent p();
		p.Foo();

		Child c();
		c.Foo();
		c.Bar();
	}
	{
		Parent p();
		p.Parent::Foo();

		Child c();
		c.Parent::Foo();
		c.Child::Foo();
		c.Child::Bar();
	}
}

void TestCast() {
	Child ch;
	Parent par = (Parent)ch;
	par.Foo();
#if 0
	par.Bar(); // fail
	Child ch2 = (Child)par; // fail: not exists Child::Child(Parent&)
#endif
}

int main ()
{
	TestAccess();
	TestCast();

	return 0;
}
