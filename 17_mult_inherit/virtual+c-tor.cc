#include <iostream>

#if 1
struct A{
	A() { std::cout << "A() > "; }
	~A() { std::cout << "~A() > "; }
};
struct B: A { // +virtual
	B() { std::cout << "B() > "; }
	~B() { std::cout << "~B() > "; }
};
struct C: A { // +virtual
	C() { std::cout << "C() > "; }
	~C() { std::cout << "~C() > "; }
};
struct D: C, B {
	D() { std::cout << "D() > "; }
	~D() { std::cout << "~D() > "; }
};
int main()
{
	D c;
	std::cout << "\n";
}
#else

struct A{
	// A() { std::cout << "0\n"; } // solve #1
	A(int x){
		std::cout << x << "\n";	
	}
};
struct B: virtual A {
	B(): A(1){}
};
struct C: B {
	C() {}
	// C(): A(2){} // solve #2
};

int main()
{
#if 0
	B b;
#else
	C c;
#endif
}
#endif