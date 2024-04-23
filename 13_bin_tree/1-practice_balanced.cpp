#include <iostream>

template <typename T>
struct Node {
	T val;
	Node<T>* parent;
	Node<T>* left;
	Node<T>* right;
};

template <typename T>
class BinTree {
	Node<T>* root_ = nullptr;
public:
	...
/* 
Переписать методы добавления и удаления так, чтобы 
дерево всегда оставалось сбалансированно (не идеально) 
- т.е. для каждой ветви высота (макс. расстояние от ветви до листа)
её двух поддеревьев различается не более чем на 1.
*/
};

void TestInt(){
	BinTree<int> list;
	list.PushBack(111);
	list >> std::cout;
}

int main()
{
	TestInt();

	return 0;
}
