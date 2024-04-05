#include <iostream>
using namespace std;


void Print(int count, int t, ...){
	int* p = &t;
	while(count--){
		cout << *p <<" ";
		p++;
	}
	cout << endl;
}


int Sum() {
	return 0;
}
template <typename... T>
int Sum(int x, T... list){
	cout << x <<" ";
	return x + Sum(list...);	
}

int main ()
{
	Print(5, 1,2,3,4,5);
	// cnt, t, ...

	int s = Sum(1,2,3,4,5);
	cout << s << endl;

    return 0;
}
