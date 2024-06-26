#include <iostream>
#include <algorithm>
using namespace std;

class Point {
	int* x_;
	int* y_;
public:
	Point(int x, int y)
		:x_(new int(x)), y_(new int(y)) {}

	~Point() {
		delete this->x_;
		delete this->y_;
	}
#if 0
  Point() = default;
  
  Point(const Point& from) = delete;
  Point(Point&& from) = delete;
#endif


	Point(const Point& from) {
		printf("copy\n");
		this->x_ = new int{*(from.x_)};
		this->y_ = new int{*(from.y_)};
	}
	Point& operator= (const Point& from) {
		printf("copy=\n");
		*(this->x_) = *(from.x_);
		*(this->y_) = *(from.y_);
		return *this;
	}

	Point(Point&& from) {
		printf("move\n");
		swap(this->x_, from.x_);
		swap(this->y_, from.y_);
	}
	Point& operator= (Point&& from) {
		printf("move=\n");
		swap(this->x_, from.x_);
		swap(this->y_, from.y_);
		return *this;
	}

	friend ostream& operator<< (ostream& out, const Point& p) {
		out <<"("<< *(p.x_) <<","<< *(p.y_) <<")";
		return out;
	}
};

int main ()
{
	{
		Point p1(8, 12);
		Point p2(p1); // copy ctor
		Point p3 = p2;// ??
		p3 = p1;      // copy optor
	}
	{
		Point p( move( Point(7, 8) ) );
		//    ↑↑↑ move ctor

		p = Point(4, 5); // move optor
		cout << p << endl;
	}
#if 0
	{ //    ↓↓↓ выключено
		Point p1(move(Point(1, 2)));
		Point p2(p1); // copy
	}
	{
		Point p1(); // по умолчанию
		p1 = Point(3, 4); // move=
	}
#endif

	return 0;
}
