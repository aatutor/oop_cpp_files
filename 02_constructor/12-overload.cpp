#include <iostream>
using namespace std;

struct Point {
private: 
	int x_;
	int y_;
public: 
#if 1
	Point(): x_(0), y_(0) { }
#else
	Point(): Point(0, 0) { }
#endif
	Point(int x, int y): x_(x), y_(y) { }
};

int main()
{
	{
		Point* p1 = new Point(); // снова работает
		Point* p2 = new Point(3, 4);
	}
	{
		Point* p1 = new Point();
		Point* p2 = new Point(3, 4);					 
	}
	return 0;
}