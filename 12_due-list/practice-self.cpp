#include <iostream>

template <typename T>
struct Node {
	T val;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class DEList {
	Node<T>* top_ = nullptr;
	Node<T>* tail_ = nullptr;
public:
	...
/* +++
Описать метод очистки
Описать деструктор
Описать конструктор для initializer_list
Реализовать "правило 3" (или 5)
Перегрузить оператор + (объединение)
Перегрузить оператор * (пересечение)
Описать метод для получения последнего/предпоследнего элемента
	с его помощью упростить возможные методы
*/
};

void Test(){
	DEList list;
	list.PushBack(111);
	list >> std::cout;
}

int main()
{
	Test();

	return 0;
}
