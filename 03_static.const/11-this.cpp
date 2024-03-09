#include <stdio.h>

#define CONST 1

class Point {
	int x_;
public:
	Point(int x): x_(x) {}			
#if !CONST
	int GetX() { 
#else
	int GetX() const { 
#endif
		return this->x_; 
	}
};

int main () {
	const Point POINT(1);
	printf("%d\n", POINT.GetX()); 
#if !CONST
				// нельзя вызвать метод
#else
				// теперь безопасно
#endif

	return 0;
}

