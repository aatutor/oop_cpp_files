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

template <typename T>
void Print(initializer_list<T> list) {
#if 1
	const T* ptr = list.begin();
	while (ptr != list.end()){
		cout << *ptr <<" ";
		++ptr;
	}

#elif 1
	const T* ptr = list.begin();
	for(unsigned i = 0; i != list.size(); ++i)
	{
		cout << ptr[i] <<" ";
	}

#else
	for(const T el : list)
	{// for each el in list
		cout << el << " ";
	}
#endif
	cout << endl;
}

int main ()
{
	Print({10, 15, 25, 135}); 
	// Print(init_list<int>)
	
	Print({'x', 'y', 'z'}); 
	// Print(init_list<char>)

	std::initializer_list<int> list{1,2,3};
	Print(list);

	return 0;
}
