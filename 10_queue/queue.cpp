#include <iostream>
#include <time.h>

class Queue
{
	enum { EMPTY = 0, FULL = 10 };
	int wait_[FULL];//Очередь
	int length_;	//Текущий размер очереди
public:
	Queue();
	void Clear();	//Очистка очереди
	bool IsEmpty();	//Проверка на пустоту
	bool IsFull();	//Проверка на заполненость
	int GetCount();	//Количество элементов
	void Add(int);//Добавление элемента
	int GetTop();	//Первый элемент
	void Pop();		//Удаление первого элемента
	int Extract(); 	//Извлечение элемента
	friend ostream& operator<< (ostream&, Queue&);
};

int main()
{
	using namespace std;
	srand(time(0));

	Queue q;

	for (int i = 0; i < 5; i++) 
		q.Add( rand() % 50 );

	cout << q << endl; // 12 9 40 2 27
	cout << "First: " << q.Extract() << endl;
	cout << q << endl; // 9 40 2 27

// - Заполнить очередь до максимума
// - Вывести содержимое
// - *Дополнительно:*
// 	- *Освободить половину*
// 	- *Заполнить освободившееся место*
// 	- *Вывести содержимое*
// - Извлечь все элементы и вывести каждый на экран

	return 0;
}