#include <iostream>
using namespace std;


template <typename T>
void Sort(T arr[], int size)
{
  for (int k = size - 1; k > 0; k--)
    for (int j = 0; j < k; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}
template <typename T>
void Print(T arr[], int size) 
{
  for(int i = 0; i < size; i++)
    cout << arr[i] <<" ";
  cout << endl;
}

int main ()
{
  // functions
  int intArr[3]{153, 23, 43};
  Sort(intArr, 3);
  Print(intArr, 3);

  char chrArr[]{"fdaslnvfj"};
  Sort(chrArr, 9);
  Print(chrArr, 9);

	return 0;
}
