// Вычислить среднюю оценку студента
#include <iostream>

struct Class {
public: 
	Class() {
		std::cout << "Object created\n";
	}
	~Class() {
		std::cout << "Object deleted\n";	
	}
};

int main()
{
	Class* object;
	object = new Class();// Object created
	delete object;		// Object deleted

	{
		int number = 0; // копирующая инициализация							
		int value(42);  // прямая инициализация
		int size{33};   // унифицированная инициализация

		int answer{ 42 }; // любая переменная
		int grades[4]{ 3, 5, 8, 2 };  // одномерный массив
		int matrix[2][2]{ {1,2}, {3,4} }; // двумерный массив
		int* dataPtr{ nullptr };      // указатель
		char* str{ new char[14]{"Hello, world!"} };
					// c-style строка, или точнее - указатель
		int& reference{ answer }; // переменная, иниц. ссылкой
		Point p1{ 10,-6 }; // экземпляр (объект) структуры
	}

	return 0;
}