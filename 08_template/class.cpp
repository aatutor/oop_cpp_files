#include <iostream>
using namespace std;

struct Point {
	int x_, y_;
	bool operator> (const Point& right);
};
ostream& operator<< (ostream& out, const Point& right);

template <typename T>
class Array {
	T* arr_;
	int size_;
public:
	Array(int size): size_(size){
		this->arr_ = new T[size];
	}
	~Array() { delete[] this->arr_; }

	int& operator[] (int index) {
		return arr_[index]; 
	}
	void Sort();
	void Print();
};


template <typename T>
void Array<T>::Sort()
{
  for (int k = size_ - 1; k > 0; k--)
    for (int j = 0; j < k; j++)
      if (arr_[j] > arr_[j + 1])
        swap(arr_[j], arr_[j + 1]);
}
template <typename T>
void Array<T>::Print() 
{
  for(int i = 0; i < size_; i++)
    cout << arr_[i] <<" ";
  cout << endl;
}

int main ()
{
  // objects
  int intArr[5]{153, 23, 543, 234, 43};
  char chrArr[]{"fdaslnvfjdkl"};

	for(int i = 0; i < this->size_; i++)
		this->arr_[i] = ;

  Array<int> a(intArr, 5);
  Array<char> c(chrArr, 12);

#if 0
  a.Sort();
  c.Sort();

  a.Print();
  c.Print();
#endif

  Point points[]{ {1,2},{3,4},{5,6} };
  Array<Point> p(points, 3);

#if 0
  p.Sort();	// ??
  p.Print();// ??

  p.Sort();	// ok
  p.Print();// ok
#endif

	return 0;
}
