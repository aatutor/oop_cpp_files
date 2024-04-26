#include <iostream>
using namespace std;

class Parent {
public:
	void Foo() {
		cout << "Parent::Foo\n";
	}
};
#if !POLYMORPHIC
class Child : public Parent {}

#else
class Child : public Parent {
public:
	void Foo() {
		cout << "Child::Foo\n";
	}
};
#endif


void Test() 
{
#if !POLYMORPHIC
	{
		Parent* par = new Parent();
		Parent* ch = new Child();
		
		par->Foo(); // Parent::Foo
		ch->Foo();  // Parent::Foo
	}
#else
	{
		Parent* par = new Parent();
		par->Foo(); // Parent::Foo

		Child* ch = new Child();
		ch->Foo();  // Child::Foo
		
		ch->Parent::Foo(); // Parent::Foo
	}
	{
		Parent* par = new Child();
		par->Foo(); // Parent::Foo
	}
#endif
}

int main ()
{
	Test();

	return 0;
}
