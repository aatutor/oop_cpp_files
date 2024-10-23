#include <iostream>

template <typename T>
struct Node {
	T val;
	Node<T>* next;
};

template <typename T>
class List {
	enum { EMPTY = -1 };
	Node<T>* top_ = nullptr;
public:
	...
/* +++
Описать метод очистки
Описать деструктор
Реализовать "правило 3" (или 5)
Описать конструктор для initializer_list
Перегрузить оператор + (объединение)
Перегрузить оператор * (пересечение)
Описать метод для получения последнего/предпоследнего элемента
	с его помощью упростить возможные методы
*/
};

void TestInt(){
	List<int> list;
	list.PushBack(111);
	list >> std::cout;
}

int main()
{
	TestInt();

	return 0;
}
