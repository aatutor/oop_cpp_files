#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <string>

void TestRp(){
	using namespace std;

	FILE* file = fopen("test.txt", "r+");

	//char str[100];
	char c;
	fscanf(file, "%c", &c);
	cout << c << endl;

	fprintf(file, "world");

	fclose(file);
}
void TestWp(){
	using namespace std;

	FILE* file = fopen("test.txt", "w+");

	fprintf(file, "st");
	//char str[100];
	char c = '-';
	for (int i = 0; i < 5; i++) {
		fscanf(file, "%c", &c);
		cout << c << endl;
		c = '-';
	}
	fprintf(file, "hello");
}
void CreateFile(){
	FILE* file;
	file = fopen("test.txt", "w");
	fprintf(file, "new");
	fclose(file);
}

int main()
{
	CreateFile();

#if 1
	TestRp();
#else
	TestWp();
#endif

	return 0;
}

