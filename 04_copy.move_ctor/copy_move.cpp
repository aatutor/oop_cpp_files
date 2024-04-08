#include <iostream>
#include <string>
#include <vector>

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
	std::string ToString() {
		return std::to_string(*(this->dot_));
	}
};

Point PointFactory(int x) {  
	return 1 ? Point(x) : Point(0);
}

int main ()
{ 
	using namespace std;
	{
		Point p1(5);
		Point p2(p1);

		cout << p2.ToString() << endl; // ??
		p1.SetX(6);
		cout << p2.ToString() << endl; // ??
	}
	{
		Point* pp1 = new Point(5);
		Point* pp2 = new Point(*pp1);
		cout << pp2->ToString() << endl; // ??

		delete pp1;
		cout << pp2->ToString() << endl; // ??

		delete pp2;
	}
	{
		Point p1(std::move(Point(5)));
		cout << p1.ToString() << endl;

		std::vector<Point> v;
		v.push_back(Point(10));
			// где-то внутри vector'а
			// вызван move ctor
	}
	{
		Point p1 ( PointFactory(5) );
		cout << p1.ToString() << endl;
	}

	return 0;
}

