#include <iostream>

struct Node {
	int value;
	Node* next;
};

class List {
	enum { EMPTY = -1 };
	Node* top_ = nullptr;
public:
	List() {}
	void operator>> (std::ostream& out);
	bool IsEmpty();
	int GetSize();
	void PushFront(int val);
	void PushBack(int val);
	int Extract();
	int Search(int val);
	void Remove(int val);
	void Insert(int pos, int val);
	// void Clear();
	// ~List();
	// List(std::initializer_list<int> list);
};

void Demo() {
	using namespace std;
	List list;
	list.PushFront(8);
	list.PushFront(2);
	list.PushFront(5);
	cout <<"size: "<< list.GetSize() << endl; // 3
	list >> cout; // 5 2 8
#if 0
	list.PushBack(4);
	list.Insert(2, 10);
	list >> cout;
	cout << "2 on "<< list.Search(2) + 1 << " position" << endl;
	list.Remove(2);
	cout << "Removed 2\n";
	list >> cout;

	List list2({5, 6, 7});
	list2 >> cout;
#endif
}

int main()
{
	Demo();

	return 0;
}
