#include <iostream>
#include <time.h>

class Queue
{
	enum { EMPTY = 0, FULL = 10 };
	int wait_[FULL];//Очередь
	int length_;	//Текущий размер очереди
public:
	void Clear();	//Очистка очереди
	Queue();
	bool IsFull();	//Проверка на заполненость
	void Add(int);//Добавление элемента
	void operator>> (std::ostream&);
	int GetCount();	//Количество элементов
	bool IsEmpty();	//Проверка на пустоту
	int GetFront();	//Первый элемент
	void PopFront();		//Удаление первого элемента
	int Extract(); 	//Извлечение элемента
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

/*
Используя объект класса:
- Заполнить очередь до максимума (независимо от значения FULL)
- Вывести содержимое
- Освободить половину очереди
- Заполнить освободившееся место новыми зачениями
- Извлечь все элементы и вывести каждый на экран
*/

	return 0;
}