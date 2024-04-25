#include <iostream>
using namespace std;

#define SIMPLE 0

#if SIMPLE
	class A {
	public:
		int x_;
	};
	class B : public A {
	public:
		int y_;
	};

	void Test()	{
		A dim1{1};
		cout << dim1.x_ << endl;

	#if 0
		B dim2{2, 3}; // error of initialization
		B dim2{2}; 		// error too
	#else
		B dim2;
	#endif
		dim2.x_ = 2;
		dim2.y_ = 3;
		cout << dim2.x_ << " " << dim2.y_ << endl << endl;
	}
#else
	class A {
		int x_;
	public:
		A(int x): x_(x) {}
		int GetX() {
			return x_;
		}
	};
	class B : public A {
		int y_;
	public:
		B(int x, int y):  A(x), y_(y) {}
		int GetX() {
			return A::GetX();
		}
		int GetY() {
			return y_;
		}
	};

	void Test() 
	{
		A dim1{1};
		B dim2{2, 3};

		cout << dim1.GetX() << endl;
		cout << dim2.GetX() << " " << dim2.GetY() << endl;
	}
#endif
int main ()
{
	Test();

	return 0;
}
