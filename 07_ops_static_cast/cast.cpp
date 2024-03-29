#include <iostream>
#include <string>
#include <cmath>

struct Point {
	int x_;
	int y_;

#if 1
	operator bool() {
		return (this->x_ == 0) && (this->y_ == 0);
	}
	operator double() {
		return sqrt(pow(this->x_, 2) + pow(this->y_, 2));
	}
#else
	explicit operator bool() {
		return (this->x_ == 0) && (this->y_ == 0);
	}
	explicit operator double() {
		return sqrt(pow(this->x_, 2) + pow(this->y_, 2));
	}
#endif
};

std::ostream& operator<<(std::ostream &out, const Point &p) {
	return out <<"("<< p.x_ <<","<< p.y_ <<")";
}

int main ()
{
	using namespace std;

	Point p1{3, 4}, p2{0, 0};

	// cannot convert 'Point' to 'bool'
	bool b = p2;
	cout << b << endl;

	cout << (bool)p1 << endl;

	double d = p2;
	cout << d << endl;

	cout << (double)p1 << endl;

	return 0;
}
