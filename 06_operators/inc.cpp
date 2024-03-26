#include <iostream>
#include <string>

class Point {
public:
	int x_;
	int y_;

#if 0
	Point operator++ (){
		++(this->x_);
		++(this->y_);
		return *this;
	}
#else
	Point& operator++ (){
		++(this->x_);
		++(this->y_);
		return *this;
	}
#endif
	Point operator++ (int) {
		Point before(*this); // copy
		++(this->x_);
		++(this->y_);
		return before;
	}
	std::string ToString(){
		return std::to_string(x_)+","+ std::to_string(y_);
	}
};

int main ()
{
	using namespace std;

{
	Point p{1,2};
	++p;
	cout << p.ToString() << endl;
}
{
	Point p{1,2};
	cout << (p++).ToString() << endl;
	cout << p.ToString() << endl;

	p++; // (p) ++ (0)							 
}

	return 0;
}
