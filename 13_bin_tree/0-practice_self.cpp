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
/* +++
Описать метод очистки
Описать деструктор
Реализовать "правило 3" (или 5)

Описать конструктор для initializer_list
Перегрузить оператор + (объединение)
Перегрузить оператор * (пересечение)
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
