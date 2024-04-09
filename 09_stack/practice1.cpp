#include <iostream>

/*
	1. Сделать стек динамическим
	class Stack {
		int* st_;
		…
	}

	2. Сделать стек шаблонным
	template <typename T, int SIZE_> class Stack{...};
*/
class Stack {
	...
};

int main()
{
	using namespace std;
	
#if 1
	Stack st(50);
#else
	Stack<int, 50> st;
#endif

	for (size_t i = 0; i < 50; i++)
		st.Push(i);

	while(!st.IsEmpty())
		cout << st.Pop() << endl;

	return 0;
}
