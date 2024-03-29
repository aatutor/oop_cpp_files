#include <stdio.h>
#include <cmath>

#if 0
// implicit
double d = 10;

double Foo(char c) {
  return c;
}
float x = Foo(5);

#else
// explicit
double d = (double)10;

double Foo(char c) {
  return (double)c;
}
float x = (float)Foo((char)5);

#endif

class Point {
	int x_;
	int y_;
public:
	Point(int n): x_(n), y_(n) {}
};
class PointEx {
	int x_;
	int y_;
public:
	explicit PointEx(int n): x_(n), y_(n) {}
};

void Foo (Point p) {}
void FooEx (PointEx p) {}

int main()
{
	Point p1 = 1;
	Foo(2);

	//PointEx p2 = 3;
	//FooEx(4);
	PointEx p2 = PointEx(3);
	FooEx(PointEx(4));
	
	PointEx p3(5);
}
