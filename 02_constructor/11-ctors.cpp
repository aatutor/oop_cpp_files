#include <iostream>
using namespace std;

struct Point {
private: 
	int x_;
	int y_;
public: 
	Point()
			: x_(0), y_(0) { 
		// default constructor 
	}
	Point(int x, int y)
			: x_(x), y_(y) {
		// common constructor										 
	}
};

int main()
{
	{
		Point* pp1 = new Point();  	
		Point p2; // Point p2();
	}
	{
		Point* p1 = new Point(); // больше не работает
		Point* p2 = new Point(3, 4);
	}
	return 0;
}