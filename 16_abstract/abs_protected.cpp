#include <iostream>
using namespace std;

#define SECURE 2

struct A {
	int x_ = 3;
protected:
#if SECURE >= 1
	A() {}
#if SECURE >= 2
	A(A& a) = default; // copy ctor
#if SECURE >= 3
	A(A&& a) = default; // move ctor
#endif
#endif
#endif
};

struct B : public A {
	int y_ = 4;
public:
	B(): A() {}
};


void TestBase()
{
	{
		B b;
		cout << b.x_ << " " << b.y_ << endl << endl;
	#if SECURE < 1
		A a; // error: 'Test()::A::A()' is protected
		cout << "default: " << a.x_ << endl;
	#endif
	}
	{
	#if SECURE < 2
		B b;
		A a( b ); // A(A& a) - copy
		cout << "copy: " << a.x_ << endl;
	#endif
	}
	{
	#if SECURE < 3 // unstable
		A a( B() ); // A(A&& a) - move
		cout << "move: " << a.x_ << endl;
	#endif
	}
	{
		B b;
		B b2( b );
		cout << "derive check: " << b2.x_ << endl;
	}
}

struct C: public A
{
	A* GetObj() {
	#if SECURE < 1
		A* t = new A();
		return t;
	#endif
	#if SECURE < 2
		A* p = new A(*this);
		return p;
	#endif
		return nullptr;
	}
	A* GetThis() {
		return (A*)this;
	}
};

void TestDerived(){
	{
		A* a = C().GetThis();
		cout << "cast: " << a->x_ << endl;
	}
	{
		A* a = new C();
		cout << "cast: " << a->x_ << endl;
	}
}

int main ()
{
	TestBase();
	TestDerived();

	return 0;
}
