// https://metanit.com/cpp/tutorial/15.1.php

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Add{
	int operator() (int, int) { return x + y; }
};
struct Sub{
	int operator() (int, int) { return x - y; }
};

template <class T>
int operation(T op, int a, int b) // первый параметр - объект функтора
{
	return op(a, b);
}

int main()
{
	using namespace std;
	int a{10};
	int b{6};
	{ // var 1
		Add add;
		Sub sub;
		std::cout << "result: " << add(a, b) << std::endl;	
		std::cout << "result: " << sub(a, b) << std::endl;	
	}
	{ // var 2
		int result = operation(Add(), a, b);
		std::cout << "result: " << result << std::endl;

		result = operation(Sub(), a, b);
		std::cout << "result: " << result << std::endl;
	}
}