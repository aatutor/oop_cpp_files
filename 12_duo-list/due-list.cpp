#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class DEList {
	Node* top_ = nullptr;
	Node* tail_ = nullptr;
public:
	DEList() {}
	void operator>> (std::ostream& out);
	bool IsEmpty();
	int GetSize();
	void PushFront(int value);
	void PushBack(int value);
	int Extract();
	int Search(int value);
	void Remove(int value);
	void Insert(int index, int value);
	void Clear();
	~DEList();
};

int main()
{
	DEList list;
	list.PushBack(8);
	list.PushBack(2);
	list.PushBack(5);
	cout << "Size: " << list.GetSize() << endl; // 3
	list >> cout; // 8 2 5

	list.PushFront(4);
	list.Insert(2, 10);
	list >> cout; // 4 8 10 2 5

	cout << "5 on " << list.Search(5) << endl; // 5 on 3
	list.Remove(3);
	list >> cout; // 4 8 10 5
}
