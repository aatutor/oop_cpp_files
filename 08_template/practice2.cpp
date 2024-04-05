#include <iostream>
using namespace std;

template <typename T>
class Matrix{
  T** arr_;
  int rows_;
  int cols_;
public:
  Matrix(initializer_list<initializer_list<T>>);
	...
  ~Matrix();
	friend std::ostream& operator<< (std::ostream&, Matrix&);
	void Randomize();
	T& operator() (int row, int col);
	T& operator[] (int index);
};

int main ()
{
	

	return 0;
}
