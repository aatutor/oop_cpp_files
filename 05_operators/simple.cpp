#include <iostream>
#include <string>

class Point {
public:
	int x_;
	int y_;

	Point Add(Point p) {
		Point res{ this->x_ + p.x_, 
				this->y_ + p.y_ };
		return res;
	}
	std::string ToString(){
		return std::to_string(this->x_)
				+","+ std::to_string(this->y_);
	}
};

int main ()
{
	using namespace std;
	{
		int x, y;
		int z = x + y; // ok

		Point p1, p2;
		Point p3 = p1 + p2; // fail
	}
	{
		Point p1{1,2}, p2{3, 4};
		
		Point p3 = p1.Add(p2);
		cout << p3.ToString() << endl;
	}

	return 0;
}
