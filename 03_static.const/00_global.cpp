#include <stdio.h>

#define GLOB 1

#if GLOB
int commonY = 3;
#endif

class Point {
	int x_;
public:
#if !GLOB
	static int commonY;
#endif
	Point (): x_(0) {}
	Point (int x): x_(x) {}
	void Print() {
		printf("(%d, %d)\n", 
				this->x_, commonY);		
	}
};
// инициализация
int Point::commonY = 3;
int main ()
{
	Point p1;
	Point p2(1);

	p1.Print();	// (0,3)
	p2.Print(); // (1,3)

#if GLOB
	commonY = 4;
#else
	Point::commonY = 4;
#endif

	p1.Print(); // (0,4)
	p2.Print(); // (1,4)

#if GLOB
	printf("%d\n", commonY);
#else
	printf("%d\n", Point::commonY);
#endif

	return 0;
}

class Demo {
	inline static int st = 0;
}