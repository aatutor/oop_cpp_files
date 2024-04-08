#include <stdio.h>
#include <math.h>

class Point {
	int x_;
	int y_;
public:
	Point (): x_(0), y_(0) {}
	Point (int x, int y): x_(x), y_(y) {}
	static double Distance(const Point& a, const Point& b) {
		return sqrt(pow(a.x_ - b.x_, 2) + pow(a.y_ - b.y_, 2));
	}
	friend double Distance(const Point& a, const Point& b){
		return sqrt(pow(a.x_ - b.x_, 2) + pow(a.y_ - b.y_, 2));
	}
}

int main () {
	Point p1(0, 0), p2(3, 4);

	printf("%f\n", Point::Distance(p1, p2));
	printf("%f\n", Distance(p1, p2));

	return 0;
}

