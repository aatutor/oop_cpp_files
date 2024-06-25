// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void f1() 
{
	FILE *f;
	if (!(f = fopen("test.txt", "rt"))) {
		throw 1; //не удалось открыть файл — выходим
	}
	// работаем с файлом дальше но, может возникнуть 
	// исключение и до следующей строки мы не 
	// доберемся, а файл не будет закрыт

	fclose(f);
}

class FileOpen
{
	FILE *f;
public:
	FileOpen(char *filename, char *mode) 
	{
		f = fopen(filename, mode);
		if (f == NULL) {
			throw 1;
		}
	}
	~FileOpen()
	{
		fclose(f);
	}
	FILE& operator* () {
		return *f;
	}
	FILE* operator-> () {
		return f;
	}
};
void f2()
{
	FileOpen myFile("test.txt", "r+");
	//здесь выполняем нужную работу с файлом
}
// TODO: добавить работу с файлом

int main()
{
	try {
		f1();
		f2();
	}
	catch (...) {
		cout << "Error with file!\n";
	}

	return 0;
}
