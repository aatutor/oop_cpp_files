// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//указатель на объект является константным,
//следовательно, через него изменить значение
//объекта нельзя
void test_pow(const int& v)
{
	//снимаем модификатор const
	//и теперь можем изменять объект
	int* temp = const_cast<int*>(&v);
#if 0
	int& temp = const_cast<int>(v);
	//error: invalid use of const_cast with type 'int', which is not a pointer, reference, nor a pointer-to-data-member type
#endif
	//изменение объекта
	*temp = v * v;
}

int main ()
// int main(int argc, char *argv[])
{
	int x = 10; 
	const int y = 11;
	cout<<"Before - "<<x<<"\n\n";	//на экране — 10
	test_pow(x); 
	test_pow(y); 
	cout<<"After - "<<x<<"\n\n";	//на экране — 100
	return 0;
}
