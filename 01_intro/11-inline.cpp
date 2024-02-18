
#include <stdio.h>
using namespace std;

struct PointClass {
	int x_;
	int y_;
	void PrintInline(){ // вариант 1
		printf("(%d,%d)\n", x_, y_);
	}
	void PrintGlobal(); // вариант 2
};

void PointClass::PrintGlobal(){
	printf("(%d,%d)\n", x_, y_);
}

int main()
{
	PointClass pointC{6, 8};        
	pointC.PrintInline();
	pointC.PrintGlobal();
}