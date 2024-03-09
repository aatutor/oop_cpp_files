#include <stdio.h>

// 1
// 2
class Point;

class Triangle {			
	Point* points;
public:
	Triangle(Point points[3]): points(new Point[3]) {
		for(int i = 0; i < 3; i++) {
			this->points[i] = points[i];
		}
	}
	void Print();
};

class Point {
	int x_;
	int y_;
public:
	Point(int x, int y): x_(x), y_(y) {}
	friend void Triangle::Print();
};
void Triangle::Print() {
	printf("{A(%d, %d) B(%d, %d) C(%d, %d)}\n",
		this->points[0].x_, this->points[0].y_,
		this->points[1].x_, this->points[1].y_,
		this->points[2].x_, this->points[2].y_
	);
}

int main () {

	return 0;
}

