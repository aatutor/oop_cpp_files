#include <iostream>


template <class T>
class Point {
protected:
	T x_;
public:
	Point(T x): x_(x) {}

	void operator>> (std::ostream& out) {
		out << x_ << "\n";
	}
};

template <class T>
class Point2d : public Point<T> {
	T y_;
public:
	Point2d(T x, T y): Point<T>(x), y_(y) {}

	void operator>> (std::ostream& out) {
		out << Point<T>::x_ <<" "<< y_ << "\n";
	}
};

int main ()
{
	{
		Point<int> p1(1);
		p1 >> std::cout;
	}
	{
		Point2d<double> p2(2, 3);
		p2 >> std::cout;
	}

	return 0;
}
