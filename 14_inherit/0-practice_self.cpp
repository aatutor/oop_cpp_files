#include <iostream>
#include <string>
using namespace std;

class Point1d {
public:
	int x_;

	Point1d(int x);
	string ToString();
	// string InBrackets(string inner);
	// string LineToBrackets(initializer_list<int> line);
};
class Point2d : public Point1d {
public:
	int y_;

	Point2d(int x, int y);
	string ToString();
};

int main ()
{
	{
		Point1d p(3);
		cout << p.ToString() << endl;
	}
	{
		Point2d p(1, 2);
		cout << p.ToString() << endl;
	}

	return 0;
}
