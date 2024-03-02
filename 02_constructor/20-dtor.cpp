#include <iostream>
using namespace std;

struct Point {
private: 
	int x_ = 0;
	int y_ = 0;
	char* name_ = nullptr;
public: 
#if 0
  Point(){
    this->name_ = new char[50]{"noname"};
  }
#else
#if 0
	Point(): Point(0, 0) { } // 1
#else
	Point(): Point(0) { } // 1
#endif
	Point(int xy): Point(xy, xy) {} // 2
#if 0
	Point(int x, int y): Point(x, y, "noname") { } // 3
	Point(int x, int y, const char* name){ // 4
#else
	Point(int x, int y, const char* name = "noname"){ // 3+4
#endif
		this->name_ = new char[strlen(name)+1];
		strcpy(this->name_, name);
		cout << "Object created\n";
	}
#endif
	~Point() {
		delete[] this->name_;
		cout << "Object deleted\n";
	}
};

int main()
{
	{	
		Point* point;
		point = new Point(); // Object created		
		delete point;        // Object deleted
	}

	return 0;
}