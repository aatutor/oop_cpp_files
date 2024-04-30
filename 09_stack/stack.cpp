#include <iostream>

class Stack {
	enum { 
		EMPTY = -1, 
		FULL = 20 
	};
	int st_[FULL + 1];
	int top_;
public:
	void Clear();
	Stack();
	bool IsFull();
	void Push(int);
	int GetCount();
	bool IsEmpty();
	int GetTop();
	void Pop();
	int Extract();
};

int main()
{
	using namespace std;

	Stack st;
	st.Push(2);
	st.Push(5);
	st.Push(1);
	cout << st.Extract() << endl;
	cout << st.Extract() << endl;
	cout << st.Extract() << endl;

	return 0;
}
