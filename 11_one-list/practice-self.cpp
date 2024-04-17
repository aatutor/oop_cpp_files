#include <iostream>

struct Node {
	int val;
	Node* next;
};

class List {
	enum { EMPTY = -1 };
	Node* top_ = nullptr;
public:
	...
/*
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
	List list;
	list.PushBack(111);
	list >> std::cout;
}

int main()
{
	Test();

	return 0;
}
