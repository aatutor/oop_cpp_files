#include <iostream>

// &Foo::a == &main::x
int& Foo(int& a) {
	a = 10;
	return a;
} // return original

int main() {
	int x = 5;
	int& y = Foo(x);
	std::cout 
			<< &y << std::endl
			<< &x << std::endl;
}