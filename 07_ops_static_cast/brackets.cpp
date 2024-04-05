#include <iostream>
using namespace std;

class Point3D {
	int x_;
	int y_;
	int z_;
public:
	Point3D(int x, int y, int z)
			: x_(x), y_(y), z_(z) {}

	int GetAxis(int ind) {
		if (ind == 0) return this->x_;
		if (ind == 1) return this->y_;
		if (ind == 2) return this->z_;
		throw "bad axis";
	}
#if 0
	int operator[] (int ind) {
		return this->GetAxis(ind);
	}
#else
	int& operator[] (int ind) {
		if (ind == 0) return this->x_;
		if (ind == 1) return this->y_;
		if (ind == 2) return this->z_;
		throw "bad axis";
	}
#endif
	int& operator[] (char axis) {
		if (axis == 'x') return this->x_;
		if (axis == 'y') return this->y_;
		if (axis == 'z') return this->z_;
		throw "bad axis";
	}

	void SetAxis(int axis, int val) {
		if (axis == 0) this->x_ = val;
		if (axis == 1) this->y_ = val;
		if (axis == 2) this->z_ = val;
	}
	void operator() (char c, int val) {
		this->SetAxis(c, val);
	}
	void operator() (int x, int y, int z) {
		this->x_ = x;
		this->y_ = y;
		this->z_ = z;
	}

	friend ostream& operator<<(ostream &out, const Point3D &p) {
		out << "(" << p.x_ << ", " << p.y_ << ", " << p.z_ << "), ";
		return out;
	}
};

int main()
{
	Point3D a(0, 0, 0);

	a.SetAxis(0, 1);
	cout << a.GetAxis(0) << endl;

	int x = a[0];
	cout << "x = " << x << endl;

#if 0
	a[1] = 3; // fail
#endif

	a[1] = 3; // ok
	a['y'] = 3; // ok

	a('z', 9);

	cout << a << endl;

	a(0, 1, 2);
	cout << a << endl;
	
	return 0;
}