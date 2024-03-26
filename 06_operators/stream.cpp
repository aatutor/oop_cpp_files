#include <iostream>
#include <string>
using namespace std;

class Point {
public:
	int x_;
	int y_;

	friend ostream& operator<< (ostream& out, const Point& p) {
		out <<"("<< p.x_ <<","<< p.y_ <<")";
		return out;
	}
	friend istream& operator>> (istream& in, Point& p) {
		in >> p.x_;
		in.ignore(1);
		in >> p.y_;
		return in;
	}
};

int main ()
{
	Point point(1, 2);
	//cout << point.ToString() << endl;
	cout << point << endl;
	 
	cin >> point;
	cout << point << endl;

	return 0;
}
