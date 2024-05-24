// doc: https://en.cppreference.com/w/cpp/container/array
// more examples: https://www.geeksforgeeks.org/array-in-cpp-stl/

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <array>
using namespace std;

const int N = 5;

template <class IT>
void ShowArray(IT begin, IT end)
{
	cout << "\narray ["<< end-begin <<"] -->\t";
	for (IT iter = begin; iter != end; ++iter) {
		cout << *iter << '\t';
	}
	cout << "\n-----------------------------------\n";
}
int main()
{
	array<int, N> arr;
	// int simpleArray[N];

	for(int i = 0; i != arr.size(); ++i){
		arr[i] = i * i;
	}

	cout << "Size : " << arr.size();
	cout << "\nMax_Size : " << arr.max_size();

	ShowArray<array<int, N>::iterator>( // int*
			arr.begin(), arr.end());
 
	cout << "\nReversed:";
	ShowArray<array<int, N>::reverse_iterator>(
			arr.rbegin(), arr.rend());
	
	cout << "\nFill:";
	arr.fill(7);
	
	reverse_iterator<array<int, N>::iterator> hardBeginIter = arr.rbegin();
	auto easyEndIter = arr.rend();

	while( hardBeginIter != easyEndIter ) {
		cout << *(hardBeginIter++) << "\t";
	}
	
	return 0;
}