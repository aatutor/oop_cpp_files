#include <iostream>
#include <string>

class Point {
public:
	int x_;
	int y_;
  Point(int x, int y): x_(x), y_(y) {}
	Point operator+ (const Point&) const;
	Point operator- () const {
		return {-this->x_, this->y_};
	}
	Point Point::operator- (const Point& right) const {
		return { this->x_ - right.x_, this->y_ - right.y_ };
	}
	std::string ToString() const {
		return std::to_string(x_)+","+ std::to_string(y_);
	}
};

Point operator+ (const Point& left, const Point& right){
	return Point{ left.x_ + right.x_, left.y_ + right.y_ };
}

Point Point::operator+ (const Point& right) const {
	return { this->x_ + right.x_, this->y_ + right.y_ };
}

int main ()
{
	using namespace std;

	Point p1(1,2), p2(3, 4);

	cout << operator+(p1, p2).ToString() << endl;
	cout << p1.operator+(p2).ToString() << endl; 

	cout << (p1 + p2).ToString() << endl; // ???

	Point p3 = p1 - p2; // ??
	cout << p3.ToString() << endl;

	return 0;
}
