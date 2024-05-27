// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>

// функция
bool isMultiple(int num, int div) 
{
	return num % div == 0;
}

// функтор
class More { 
	public: bool operator() (int a, int b) { return a > b; }
} isMore;

// лямбда-выражение
auto isEqual = [](int a, int b) { return a == b; }; 

// использование чего угодно
bool check(int x, int y, std::function<bool(int,int)> pred) // pred - предикат
{
	return pred(x, y);
}

int main ()
{
	using namespace std;
	cout << (check(10, 5, isMultiple) ? "yes":"no") << endl;

	cout << (check(10, 5, isMore) ? "yes":"no") << endl;

	cout << (check(10, 5, isEqual) ? "yes":"no") << endl;

	return 0;
}
