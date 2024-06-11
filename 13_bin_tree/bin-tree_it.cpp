#include <iostream>
#include <list>
// using namespace std;

struct Pair {
	int key;
	char value;
};

class ElemTree {
	struct Node {
		Pair *element;
		Node *parent = nullptr;
		Node *left = nullptr, *right = nullptr;
	};

	Node* root_ = nullptr;

public:
	class Iterator {
	protected:
		Node *node_ = nullptr;
	public:
		Iterator(Node *node) : node_(node) {}
		Iterator& operator++();
		Pair& operator* ();
		Pair* operator->();
		Iterator& Next();
		Iterator& Previous();
		Iterator& Min();
		Iterator& Max();
		Iterator& Search(int key);
	};
private:
	class Container : public Iterator {
		Container(Node *node) : Iterator(node) {}
		Node* GetNode();
	};
#if 0
public:
	bool IsEmpty();
	void Insert(Pair* elem);
	Pair* Search(int key);
	std::list<Pair*> SearchAll(int key);
	void Remove(int key);
private:
	void Print(Node* obj, std::ostream& out);
	Node* Min(Node* obj);
	Node* Next(Node* obj);
	Node* Search(int key, Node* temp);
	void Remove(Node* obj);
	void Delete(Node* obj);
#endif
};
#if 0
void Test() {
	using namespace std;

	ElemTree tree;
	Pair pairs[] = {{5, 'a'}, {1, 'b'}, {8, 'c'}, {1, 'd'}};

	for (size_t i = 0; i < 4; i++)
		tree.Insert(&pairs[i]);
	tree >> cout;

	std::list<Pair*> list = tree.SearchAll(1);
	cout << "found [1]: ";
	for (Pair* p : list)
		cout << p->value << " ";
	cout << endl;
	
	tree.Remove(5);
	tree >> cout;

	tree.Remove(1);
	tree >> cout;

	tree.Remove(8);
	tree >> cout;
}
#endif
int main() {
	// Test();



	return 0;
}