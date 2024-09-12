#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iomanip>
#include <cstring>

const int MAX_LEN_NAME = 50;
const int CURRENT_YEAR = 2024;

struct Student {
	char name_[MAX_LEN_NAME]; // ФИО
	short birthYear_;
	short age_;
};
void InitStudent(Student&, const char*, short);
void PrintStudent(Student);

int main() {
	Student ivan;
	InitStudent(ivan, "Ivanov Ivan", 2002);
	PrintStudent(ivan);
	return 0;
}

// заполнение данных о студенте
void InitStudent(Student& stud, 
		const char* name, short year)
{
	strcpy(stud.name_, name);
	stud.birthYear_ = year;
	stud.age_ = CURRENT_YEAR - year;
}
// вывод данных о студенте
void PrintStudent(Student stud) 
{
    printf("%s (%d y.o)\n", 
				stud.name_, stud.age_);
}