
#include <stdio.h>
using namespace std;


// struct style
{
	struct Point {
		int x_;
		int y_;
	};
	void Print(Point p) {
		printf("(%d,%d)\n", p.x_, p.y_);            
	}

	int main() {
		Point p{6, 8};
		Print(p);
	}
}

// class style 
{
	struct Point {
		int x_;
		int y_;
		void Print(){
				printf("(%d,%d)\n", x_, y_);            
		}
	};

	int main() {
		Point p{6, 8};
		p.Print();
	}
}

