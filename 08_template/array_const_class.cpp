#include <iostream>
using namespace std;

template <typename T, int SIZE>
class Array {
  T arr_[SIZE];
public:
  Array(T arr[]){
    for(int i = 0; i < SIZE; i++)
      arr_[i] = arr[i];
  }
	void Sort();
	void Print();
};

template <typename T, int SIZE>
void Array<T, SIZE>::Sort()
{
  for (int k = SIZE - 1; k > 0; k--)
    for (int j = 0; j < k; j++)
      if (arr_[j] > arr_[j + 1])
        swap(arr_[j], arr_[j + 1]);
}
template <typename T, int SIZE>
void Array<T, SIZE>::Print() 
{
  for(int i = 0; i < SIZE; i++)
    cout << arr_[i] <<" ";
  cout << endl;
}

int main ()
{
  // const size
  int intArr[]{153, 23, 43};
  Array<int, 3> a(intArr);
  a.Sort();
  a.Print();

  char chrArr[]{"fdaslnvfj"};
  Array<char, 9> c(chrArr);
  c.Sort();
  c.Print();

	return 0;
}
