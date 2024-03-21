#include <stdio.h>

class Point {
	int* dot_;
public:
	Point(int d){
		this->dot_ = new int(d);
	}
#if 0
	Point(Point& p): dot_(p.dot_) {} // def
#else
	Point(Point& p) {
		printf("Point&\n");
		this->dot_ = new int(*(p.dot_));
	}
#endif
#if 0
	Point(Point&& p): dot_(p.dot_) {}
#else
	Point(Point&& p) {
		printf("Point&&\n");
		this->dot_ = new int( *(p.dot_) );
		delete p.dot_;
		p.dot_ = nullptr;
	}
#endif
	~Point() { delete this->dot_; }
	void SetX(int d) { *(this->dot_) = d; }
	void Print() {
		printf("%d\n", *(this->dot_));
	}
};

Point PointFactory(int x) {  
	Point p1(x), p2(x);
	if (1)
		return p1;
	else
		return p2;
}

int main ()
{
	{
		Point p1(5);
		Point p2(p1);

		p2.Print(); // ??
		p1.SetX(6);
		p2.Print(); // ??
	}
	{
		Point* pp1 = new Point(5);
		Point* pp2 = new Point(*pp1);
		pp2->Print(); // ??

		delete pp1;
		pp2->Print(); // ??

		delete pp2;
	}
	{
		Point p1(std::move(Point(5)));
		p1.Print();

		std::vector<Point> v;
		v.push_back(Point(10));
			// где-то внутри vector'а
			// вызван move ctor


		Point p1 ( PointFactory(5) );
		p1.Print();
	}

	return 0;
}

