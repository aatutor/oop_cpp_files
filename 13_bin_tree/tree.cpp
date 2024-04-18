#include <iostream>
// using namespace std;

struct Pair {
	int key;
	char value;
};

struct Node {
	Pair* element;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};
class ElemTree {
	Node* root_ = nullptr;

public:
	bool IsEmpty() { 
		return root_ == nullptr; 
	}
	void Insert(Pair* elem) {
		Node* obj = new Node{ elem };

		if (IsEmpty()) {
			root_ = obj;
			return;
		}

		Node* temp = root_;
		Node* curParent = nullptr;
		bool flag = true;
		do {
			curParent = temp;
			flag = obj->element->key < temp->element->key;
			if (flag)
				temp = temp->left;
			else
				temp = temp->right;
		} while (temp);

		obj->parent = curParent;
		if (flag)
			curParent->left = obj;
		else
			curParent->right = obj;
	}
	// friend ostream& operator<< (ostream& out, ElemTree& tree)
	// void operator>> (ostream& out)
	void Print() {
		if (IsEmpty())
			return;

		using namespace std;
		Node* temp = Min(root_);
		while(temp){
			cout << temp->element->value << "["
			     << temp->element->key << "], ";
			temp = Next(temp);
		}
		cout << endl;
	}
	Pair* Search(int key) {
		return Search(key, root_)->element;
	}
	void Remove(int key) {
		// search node
		// remove node

	}
private:
	Node* Min(Node* obj) {
		while (obj->left)
			obj = obj->left;
		return obj;
	}
	Node* Next(Node* obj) {
		if (!obj) // obj == nullptr
			throw "can't find next from null";

		if (obj->right){
			return Min(obj->right);
		}
		Node* curParent = obj->parent;
		while (obj == curParent->right && curParent) {
			obj = curParent;
			curParent = curParent->parent;
		}
		return curParent;
	}
	Node* Search(int key, Node* temp){
		while(temp){
			int tempKey = temp->element->key;
			if (key == tempKey)
				break;
			else if (key < tempKey)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return temp;
	}
	void Remove(Node* obj) {
		if (root_ == obj) { // delete root
			if (obj->left == 0 && obj->right == 0)
				root_ = nullptr;
			else if (obj->left != 0 && obj->right != 0) {
				root_ = obj->right;
				obj->right->parent = nullptr;

				Node* temp = Next(obj);
				temp->left = obj->left;
				obj->left->parent = temp;
			}
			else if (obj->left != 0) {
				obj->left->parent = nullptr;
				root_ = obj->left;
			}
			else {
				obj->right->parent = nullptr;
				root_ = obj->right;
			}
		}
		else if (obj->left == 0 && obj->right == 0) {
			if (obj == obj->parent->right)
				obj->parent->right = nullptr;
			else
				obj->parent->left = nullptr;
		}
		else if (obj->left != 0 && obj->right != 0) {
			if (obj == obj->parent->right)
				obj->parent->right = obj->right;
			else
				obj->parent->left = obj->right;
			obj->right->parent = obj->parent;

			Node* temp = Next(obj);
			temp->left = obj->left;
			obj->left->parent = temp;
		}
		else if (obj->left != 0) {
			obj->left->parent = obj->parent;
			obj->parent->left = obj->left;
		}
		else {
			obj->right->parent = obj->parent;
			obj->parent->right = obj->right;
		}
		delete obj;
	}
	void Remove1(Node* obj){
		Node* temp, *curParent;
		if (obj->left == nullptr || obj->right == nullptr)
			curParent = obj;
		else
			curParent = Next(obj);

		if (curParent->left)
			temp = curParent->left;
		else
			temp = curParent->right;

		if (temp)
			temp->parent = curParent->parent;

		if ( !(curParent->parent) )
			root_ = temp;
		else if (curParent == curParent->parent->left)
			curParent->parent->left = temp;
		else
			curParent->parent->right = temp;

		if (curParent != obj) {
			obj->element = curParent->element;
		}
		delete curParent;
	}

};

int main()
{
	using namespace std;

	ElemTree tree;
	Pair pairs[] = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
	for (size_t i = 0; i < 3; i++)
		tree.Insert(&pairs[i]);

	tree.Print();
	cout << endl;
	tree.Remove(0);
	tree.Print();
	cout << endl;
	tree.Remove(1);
	tree.Print();
	cout << endl;
	tree.Remove(2);
	tree.Print();
	cout << endl;
}
