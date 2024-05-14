#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>

//Функция копирования файла
void CopyFile(const char *source, const char *destination)
{
	FILE *src, *dest;

	// Открытие файла-источника
	if ( (src = fopen(source, "rb")) == 0 ){
		throw "Failed to open source file";
	}
	// Открытие файла-назначения (куда копировать)
	if ( (dest = fopen(destination, "wb")) == 0 ) {
		throw "Failed to open destination file";
	}

#if 0
		// Получение дескриптора файла
		int handle = _fileno(src);
		long len = _filelength(handle);
#endif

	while (!feof(src))
	{
		const int SIZE = 65536;
		//выделение памяти под буффер
		char buf[SIZE];
		//Чтение данных из файла
		int realsize = fread(buf, sizeof(char), SIZE, src);
		//Запись данных в файл
		fwrite(buf, sizeof(char), realsize, dest);
	}

	//Закрытие файлов
	fclose(src);
	fclose(dest);
}

void Test1()
{
	using namespace std;
	try {
		{
			FILE* file = fopen("test.txt", "w");
			fputs("int main()\n{\n\tcout << \"Hello World\" << endl;\n}", file);
			fclose(file);
		}
		CopyFile("test.txt", "clone.cpp");
	}
	catch(const char* ex) {
		cout << ex << endl;
	}
	catch(...){
		cout << "Unknown error" << endl;
	}

	system("pause");

	remove("test.txt");
	remove("clone.cpp");
}

void AccessRead(char* filename){
	if (_access(filename, 00) != 0) {
		throw "File not exists";
	}
	if (_access(filename, 04) != 0) {
		throw "File unreadable";
	}
}
void AccessWrite(char* filename){
	if (_access(filename, 00) == 0) {
		// throw "File already exists";
		if (_access(filename, 02) != 0){
			std::cout << _access(filename, 02) << std::endl;
			throw "File already exists. Protected to write\n";
		}
	}
}
void Test2()
{
	using namespace std;
	
	char source[] = "test.txt";
	char clone[] ="clone.bin";

	try {
		{
			FILE* file = fopen(source, "wb");
			for(size_t i = 0; i != 1024; ++i)
			{
				long buf[1024];
				fwrite(buf, sizeof(long), 1024, file);
			}
			fclose(file);
		}
		
		AccessRead(source);
		AccessWrite(clone);

		cout << "Copying file\n";
		CopyFile(source, clone);
	}
	catch(const char* ex) {
		cout << ex << endl;
	}
	catch(...){
		cout << "Unknown error" << endl;
	}

	system("pause");

	remove(source);
	remove(clone);
}

// int main(int argc, char *argv[])
int main()
{
#if 0
	Test1();
#else
	Test2();
#endif

	return 0;
}

