#include <iostream>
using namespace std;

template <typename T> T Max(T a, T b);

template <typename T>
T* Geterate(int size) {
  return new T[size];
}

int main ()
{
	{
		cout << Max(3, 5) << endl;
		cout << Max(3.4, 5) << endl;
		cout << Max('b', 'h') << endl;
	}
#if 0
	Max(5, 6); // T = int
	Geterate(5); // T = ???
#endif
	{
		int* x = Generate<int>(5);  // T=int
		char* y = Generate<char>(5);// T=char

		bool* b = Generate<char>(5);// T=?
	}
	{
		cout << Max<int>(3, 5) << endl;
		cout << Max<double>(3.5, 3.3) << endl;
		cout << Max<char>('b', 'h') << endl;
	}
	{
		cout << Max(10, 20) << endl;      // 20
		cout << Max(10.0, 20.0) << endl;  // 20
		cout << Max("hi", "bye") << endl; // buy ('h'>'b')
	}
	{
		cout << Max("hi", "bye") << endl; // hi
	}

	return 0;
}

template <typename T>
T Max(T a, T b) {
	return (a > b) ? a : b ;
}
#if 0
int Max(int t1, int t2);
double Max(double t1, double t2);
char Max(char t1, char t2);
#endif

// template <> const char* Max<const char*>(-//-)
const char* Max(const char* t1, const char* t2)
{
  return (strcmp(t1, t2) > 0) ? t1 : t2;
}
