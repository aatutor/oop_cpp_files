#include <iostream>
#include <string>
using namespace std;

class Parent {
public:
	virtual void Foo(int x) {
		cout << "Parent::Foo(int)\n";
	}
};
class Child : public Parent {
public:
	virtual void Foo(long x) {
	// virtual void Foo(long x) override {
		cout << "Child::Foo(long)\n";
	}
};

void Test() 
{
	{
		Parent* par = new Parent();
		par->Foo(5); // Parent::Foo
	}
	cout << string(15,'-') << endl;
	{
		Child* ch = new Child();
		ch->Foo(5);  // Child::Foo
		ch->Foo( (long)5 );  // Child::Foo
	}
	cout << string(15,'-') << endl;
	{
		Parent* par = new Child();
		par->Foo(5); // Parent::Foo
		par->Foo( (long)5 ); // Parent::Foo
	}
}

int main ()
{
	Test();

	return 0;
}
