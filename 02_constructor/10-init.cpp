#include <iostream>
using namespace std;

struct Point {
private: 
#if 1
	int x_;
	int y_;
#else
	int x_ = 0;
	int y_ = 0;
#endif
public: 
#if 0
	Point(int x, int y) : x_(x), y_(y) {

#else
#if 1
	Point() {
		this->x_ = 0;
		this->y_ = 0;
#else
	Point(): x_(0), y_(0) {
// member ^^^^^init^^^^^  list
#endif
#endif
		// some code
		cout << "Object created\n";
	}
};

int main()
{
	Point* point;

	{
		point = new Point();// Object created
		delete point;		// Object deleted
		Point* pp1 = new Point();			  
		Point p2();
	}
	{
		Point* p2 = new Point(3, 4);					

		point = new Point(3, 4);// Object created
		delete point;		// Object deleted
	}
	return 0;
}