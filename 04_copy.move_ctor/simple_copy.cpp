#include <stdio.h>

void Foo(Point p);

int main ()
{
	{
		int x1 = 5;
		int x2 = x1;
	}
	{
		int x1(5);
		int x2(x1);
	}
	{
		int x1{5};
		int x2{x1};
	}
	{
		Point p1(10);		
		Foo(p1);
	}

 
	return 0;
}
