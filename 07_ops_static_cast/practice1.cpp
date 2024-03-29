#include <iostream>
#include <string>

class Array{
  int* arr_;
	// int arr_[256];
  int size_;
public:
  Array(int size);
	...
  int& operator[] (int ind);
  void operator() (int ind, int val);
	void operator() (int size); // Resize
  operator bool(); // HasNotZero
  operator int();	 // GetSize
  // добавим explicit
};

int main ()
{
	using namespace std;
	Array a(3);

	...

	return 0;
}
