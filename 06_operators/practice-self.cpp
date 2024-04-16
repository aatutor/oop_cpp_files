#include <iostream>

class Point{
	int x_;
	int y_;
public:
	...
	Point& operator-- ();
	Point  operator-- (int);

	Point& operator+= (const Point&);
	Point& operator-= (const Point&);
	Point& operator*= (const int&);
	Point& operator/= (const int&);
}


int main ()
{
	using namespace std;
{
	Point p(1,2);
	cout << --p << endl;
	cout << p-- << endl;
	cout << p << endl;
}
{
	Point p(1,2), q(0,0);
	q += p;
	cout << q << endl;
	cout << (q *= 2) << endl;
	cout << (q /= 4) << endl;
	cout << (q -= p) << endl;
}


	return 0;
}
