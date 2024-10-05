#include <iostream>
#include <string>

class Array{
  int* ptr_;
	// int ptr_[256];
  int size_;
public:
  Array(int size);
	...
  int& operator[] (int ind);
	void operator() (int size); // Resize
  void operator() (int beg, int end, int val);
  // Array operator() (int beg, int end);
};

int main ()
{
	using namespace std;
	Array a(3);

	a[0] = 5;
	a[1] = 1;
	cout << a[0] << "\n";
	a(5);
	a(2,4, 9);
	// {5, 1, 9, 9, 9}
	...

	return 0;
}
