#include <iostream>
#include <list>
// using namespace std;


struct Pair {
	int key;
	char value;
};

struct Node {
	Pair element;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};


class ElemTree {
	Node* root_ = nullptr;
public:
	bool IsEmpty();
	void Insert(Pair elem);
	void operator>> (std::ostream& out) const;
	Pair& Search(int key);
	std::list<Pair> SearchAll(int key);
	void Remove(int key);
private:
	void Print(Node* obj, std::ostream& out) const;
	Node* Min(Node* obj) const;
	Node* Next(Node* obj) const;
	Node* Search(int key, Node* temp) const;
	void Remove(Node* obj);
};


std::ostream& operator<<(
		std::ostream& out, const ElemTree& obj) {
	obj >> out;
	return out;
}

int main()
{
	using namespace std;

	ElemTree tree;
	Pair pairs[] = {{5, 'a'}, {1, 'b'}, {8, 'c'}, {1, 'd'}};

	for (size_t i = 0; i < 4; i++)
		tree.Insert(pairs[i]);
	cout << "tree: " << tree << endl;

	cout << "found 8: " << tree.Search(8).value << endl;

	std::list<Pair> list = tree.SearchAll(1);
	cout << "found [1]: ";
	for (Pair p : list)
		cout << p.value << " ";
	cout << endl;

	tree.Remove(5);
	cout << "removed 5: " << tree << endl;

	tree.Remove(1);
	cout << "removed 1: " << tree << endl;

	tree.Remove(8);
	cout << "removed 8: " << tree << endl;
}



bool ElemTree::IsEmpty() {
	return root_ == nullptr; 
}


void ElemTree::Insert(Pair elem) {
	Node* obj = new Node{ elem };

	if (IsEmpty()) {
		root_ = obj;
		return;
	}

	Node* temp = root_;
	Node* curParent;
	bool flag;
	while (temp) {
		curParent = temp;
		flag = obj->element.key < temp->element.key;
		if (flag)
			temp = temp->left;
		else
			temp = temp->right;
	}
	obj->parent = curParent;
	if (flag)
		curParent->left = obj;
	else
		curParent->right = obj;
}


/// TODO: fix last ','
void ElemTree::operator>> (
		std::ostream& out) const {
	Print(root_, out);
}


void ElemTree::Print(
		Node* obj, std::ostream& out) const {
	if (obj == nullptr)
		return;

	Print(obj->left, out);
	out << obj->element.value << "["
			<< obj->element.key << "], ";
	Print(obj->right, out);
}


Pair& ElemTree::Search(int key) {
	return Search(key, root_)->element;
}


Node* ElemTree::Search(int key, Node* temp) 
		const {
	while(temp){
		int tempKey = temp->element.key;
		if (key == tempKey)
			break;
		if (key < tempKey)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}


std::list<Pair> ElemTree::SearchAll(int key) {
	std::list<Pair> list;
	Node* temp = Search(key, root_);
	while (temp->element.key == key) {
		list.push_back(temp->element);
		temp = Next(temp);
	}
	return list;
}


Node* ElemTree::Min(Node* obj) const {
	while (obj->left)
		obj = obj->left;
	return obj;
}


Node* ElemTree::Next(Node* obj) const {
	if (!obj) // obj == nullptr
		throw "can't find next from null";

	if (obj->right){
		return Min(obj->right);
	}
	Node* curParent = obj->parent;
	while (obj == curParent->right 
			&& curParent != nullptr) {
		obj = curParent;
		curParent = curParent->parent;
	}
	return curParent;
}


void ElemTree::Remove(int key) {
	Remove(Search(key, root_));
}


void ElemTree::Remove(Node* obj) {
	if (!obj)
		throw "nothing to delete\n";
	
#if 1
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
#else
	
	if (root_ == obj) { // delete root
		if (obj->left == 0 && obj->right == 0){
			root_ = nullptr;
		}
		else if (obj->right == 0) {
			obj->left->parent = nullptr;
			root_ = obj->left;
		}
		else if (obj->left == 0) {
			obj->right->parent = nullptr;
			root_ = obj->right;
		}
		else {
			root_ = obj->right;
			obj->right->parent = nullptr;

			Node* temp = Next(obj);
			temp->left = obj->left;
			obj->left->parent = temp;
		}
	}
	else if (obj->left == 0 && obj->right == 0) {
		if (obj == obj->parent->right)
			obj->parent->right = nullptr;
		else
			obj->parent->left = nullptr;
	}
	else if (obj->left == 0) {
		obj->right->parent = obj->parent;
		if (obj == obj->parent->right)
			obj->parent->right = obj->right;
		else
			obj->parent->left = obj->right;
	}
	else if (obj->right == 0) {
		obj->left->parent = obj->parent;
		if (obj == obj->parent->right)
			obj->parent->right = obj->left;
		else
			obj->parent->left = obj->left;
	}
	else {
		if (obj == obj->parent->right)
			obj->parent->right = obj->right;
		else
			obj->parent->left = obj->right;
		obj->right->parent = obj->parent;

		Node* temp = Next(obj);
		temp->left = obj->left;
		obj->left->parent = temp;
	}
	delete obj;
#endif
}
