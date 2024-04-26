#include <iostream>
#include <string.h>
using namespace std;

struct A {
	virtual int& Get() = 0;
	virtual int* GetP() = 0;
#if 1
	virtual ~A() {}
#endif
};

struct B: A
{
	int x_ = 10;
	int* px_ = new int{100};
	int& Get() override {
		return x_;
	}
	int* GetP() override {
		return px_;
	}
	~B() {
		cout << "~B - d-tor calling\n";
		delete px_;
	}
};


int main ()
{
	A* pa = new B();

	int &x = pa->Get();
	int *px = pa->GetP();

	cout << x << endl;
	cout << *px << endl;

	delete pa;
	cout << "-- del\n";

	cout << x << endl;
	cout << *px << endl;
    
    return 0;
}
