// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
using namespace std;

template <class X> class My_auto_ptr
{
	X *ptr;
public: //конструктор и деструктор
	explicit My_auto_ptr(X *p = nullptr) throw() {
		ptr = p;
	}
	~My_auto_ptr() throw() {
		delete ptr;
	}
	// ...

	//оператор разыменования
	X& operator*() const throw() {
		return *ptr;
	}
	X* operator->() const throw() {
		return ptr;
	}
};
struct Temp
{
	Temp() { cout << "Temp\n\n"; }
	~Temp(){ cout << "~Temp\n\n"; }
	void Test() { cout << "Test\n\n"; }
};

int main()
{
	{
		int *x = new int(5);
		int *y = x;

		delete x;
		delete y; // not success
	}
	{
 		//создаём два автоматических указателя
		//под один из них выделяем память типа Temp
	#if 0
		My_auto_ptr<Temp> ptr1(new Temp), ptr2, copy;
	#endif
		std::auto_ptr<Temp> ptr1(new Temp), ptr2;
		
		ptr2 = ptr1; // передача права владения

	#if 0 // копирование объекта
		copy = std::auto_ptr<Temp>(new Temp(*ptr1));
		copy = ptr1->Clone(); // паттерн клонирования/копирования
	#endif

		ptr2->Test(); // вызов метода через автоматический указатель
		
		// присваивание автоматического указателя
		// обычному указателю на объект класса
		Temp *ptr = &*ptr2;
		ptr->Test(); //вызов метода через обычный указатель
	}
	cout << "Success\n";
	return 0;
}
