#include <iostream>
#include <string>

class Point {
public:
	int x_;
	int y_;
public:
	Point(int x, int y): x_(x), y_(y) {}
#if 0
	Point operator+ (Point p){ // this == &left
		Point res{ this->x_ + p.x_, this->y_ + p.y_ };
		return res;
	}
#else
	Point operator+ (const Point& p) const {
		return { this->x_ + p.x_, this->y_ + p.y_ };
	}
#endif
	double operator* (Point p) const {
		double res = this->x_ * p.x_ + this->y_ * p.y_;
		return res;
	}
	Point operator- () const {
		Point res{-(this->x_), -(this->y_)};
		return res;
	}
	std::string ToString(){
		return std::to_string(x_)+","+ std::to_string(y_);
	}
};

#define GLOBAL 0
#if GLOBAL
Point operator+ (Point left, Point right)
{
	Point res{ left.x_ + right.x_, left.y_ + right.y_ };
	return res;
}
#endif

int main ()
{
	using namespace std;
	Point p1{1,2}, p2{3, 4};

{
	Point p3 = p1 + p2;
	cout << p3.ToString() << endl;

	Point p4 = Point(1,4) + Point(8,1);
	cout << p4.ToString() << endl;
}
{
	Point p3 = p1.operator+ (p2);
	cout << p3.ToString() << endl;
}	
{
	cout << (p1 * p2) << endl;
}
{
	Point p3 = -p1;
	cout << p3.ToString() << endl;
}
{
	cout << p1.operator+(p2).ToString() << endl;
#if GLOBAL
	cout << operator+(p1, p2).ToString() << endl;
#endif

	cout << (p1 + p2).ToString() << endl;
}

	return 0;
}

