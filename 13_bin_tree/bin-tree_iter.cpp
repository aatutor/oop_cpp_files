#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <list>
// using namespace std;

struct Pair {
	int key;
	int value;

	bool operator< (const Pair& right) const {
		return this->key < right.key;
	}
	bool operator== (const Pair& right) const {
		return this->key == right.key;
	}
	bool operator!= (const Pair& right) const {
		return *this != right;
	}
	bool operator< (int key) {
		return this->key < key;
	}
	bool operator== (int key) {
		return this->key == key;
	}
	bool operator!= (int key) {
		return *this != key;
	}
	std::string ToString() const {
		return "[" + std::to_string(this->key) + "]:" + std::to_string(this->value);
	}
};
std::ostream &operator<<(std::ostream &out, const Pair &obj) {
	out << obj.ToString();
	return out;
}


class Tree 
{
	struct Node {
		Pair obj;
		Node *left, *right, *parent;
	};
	Node* root_ = nullptr; //корень
public:
	class Iterator;
	Node* GetNode(Tree::Iterator& iter);
	bool IsEmpty();
	void Print();
	Iterator Search(Iterator, int);
	Tree::Iterator Min(Tree::Iterator);
	Tree::Iterator Max(Tree::Iterator);
	Tree::Iterator Next(Tree::Iterator);
	Tree::Iterator Previous(Tree::Iterator);
	void Insert(const Pair&);
	void Delete(Tree::Iterator);
	Tree::Iterator GetRoot();
private:
	void Print(Node*);
};

class Tree::Iterator {
	Node* node_;
public:
	Iterator() : node_(nullptr) {}
	Iterator(Node *node) : node_(node) {}
	Pair& operator* () const {
		return node_->obj;
	}
	Pair* operator-> () const {
		return &(node_->obj);
	}
	friend Node* Tree::GetNode(Tree::Iterator&);
};
//Рекурсивный обход дерева
bool Tree::IsEmpty() {
	return root_ == nullptr; 
}
void Tree::Insert(const Pair& node) {
	Node* elem = new Node { node, 0, 0, 0 };

	if (IsEmpty()) {
		root_ = elem;
		return;
	}
		
	Node* temp = root_;
	Node* parent = nullptr;
	bool flag;
	while (temp != 0) {
		parent = temp;
		flag = elem->obj < temp->obj;
		if (flag)
			temp = temp->left;
		else
			temp = temp->right;
	}
	elem->parent = parent;
	if (flag)
		parent->left = elem;
	else
		parent->right = elem;
}
Tree::Node* Tree::GetNode(Tree::Iterator& iter) { 
	return iter.node_;
}
void Tree::Print() {
	std::cout << "Tree values: ";
	Print(root_);
	std::cout << std::endl;
}
void Tree::Print(Node* node) {
	if (node == nullptr)
		return;

	Print(node->left);
	std::cout << node->obj << " | ";
	Print(node->right);
}
Tree::Iterator Tree::Search(Tree::Iterator iter, int key) {
	Node* node = this->GetNode(iter);
	//Пока есть узлы и ключи не совпадают
	while (node != 0 && node->obj != key)
	{
		if (node->obj < key)
			node = node->right;
		else
			node = node->left;
	}
	return Tree::Iterator(node);
}
Tree::Iterator Tree::Min(Tree::Iterator iter) {
	Node* node = this->GetNode(iter);
	if (node != nullptr)
		while (node->left != 0)
			node = node->left;
	return node;
}
Tree::Iterator Tree::Max(Tree::Iterator iter) {
	Node* node = this->GetNode(iter);
	//Поиск самого "правого" узла
	if (node != 0)
		while (node->right != 0)
			node = node->right;
	return node;
}
Tree::Iterator Tree::Next(Tree::Iterator iter) {
	Node* node = this->GetNode(iter);
	if (node == 0)
		return nullptr;

	//если есть правый потомок
	if (node->right != 0)
		return Min( Tree::Iterator(node->right) );

	//родитель узла
	Node* parent = node->parent;
	//если node не корень и node справа
	while (parent != 0 && node == parent->right)
	{
		//Движемся вверх
		node = parent;
		parent = node->parent;
	}
	return parent;
}
Tree::Iterator Tree::Previous(Tree::Iterator iter) {
	Node* node = this->GetNode(iter);
	if (node == 0)
		return nullptr;

	//если есть левый потомок
	if (node->left != 0)
		return Max( Tree::Iterator(node->left) );

	//родитель узла
	Node* parent = node->parent;
	//если node не корень и node слева
	while (parent != 0 && node == parent->left)
	{
		//Движемся вверх
		node = parent;
		parent = node->parent;
	}
	return Tree::Iterator(parent);
}
Tree::Iterator Tree::GetRoot() {
	return Tree::Iterator(root_);
}
void Tree::Delete(Tree::Iterator iter) {
	Node* node = this->GetNode(iter);
	Node* temp, *toDelete;
	//не 2 потомка
	if (node->left == 0 || node->right == 0)
		toDelete = node;
	else
		toDelete = Next( Tree::Iterator(node) );

	if (toDelete->left != 0)
		temp = toDelete->left;
	else
		temp = toDelete->right;

	if (temp != 0)
		temp->parent = toDelete->parent;

	// Запись в родителя
	if (toDelete->parent == 0)
		//Удаляется корневой узел?
		root_ = temp;
	else if (toDelete == toDelete->parent->left)
		//слева от родителя?
		toDelete->parent->left = temp;
	else
		//справа от родителя?
		toDelete->parent->right = temp;

	if (toDelete != node)
	{
		//Копирование данных узла
		node->obj = toDelete->key;
	}
}

int main()
{
	using namespace std;
	srand(time(0));
	{
		int size = 10;
		std::list<Pair> arr;
		for(int i=0; i != size; ++i){
			arr.push_back(Pair{rand()%50, rand()%50});
		}
		Tree tree;
		cout << "list: ";
		for(Pair& p : arr){
			cout << p.key << " ";
			tree.Insert(p);
		}
		cout << "\n";
		//Вывод результатов
		tree.Print();

		cout << "less 10 items: ";
		Tree::Iterator mid;
		Tree::Iterator el = tree.Min(tree.GetRoot());
		// Node* n; el.GetNode()->parent_ = nullptr;
		for(int i=0; i != size; ++i){
			int x = el->key;
			if (x < 10)
				cout << x << " ";
			el = tree.Next(el);
			if (i+1 == size/2)
				mid = el;
		}
		cout << "\n";

		cout << mid->key << " removed\n";
		tree.Delete(mid);
		tree.Print();
		cout << "list: ";
		for(Pair& e : arr)
			cout << e.key << " ";
		cout << "\n\n";
	}
	{
		int size = 10;
		std::list<Pair> arr;
		for(int i=0; i != size; ++i){
			arr.push_back(Pair{rand()%10, rand()%50});
		}
		Tree tree;
		for(Pair& e : arr){
			tree.Insert(e);
		}
		//Вывод результатов
		tree.Print();

		if ( *tree.Search(tree.GetRoot(), 0) == nullptr )
			cout << "> has no '0' item\n";
		else
			cout << "> tree has item '0'\n";
	}
}
