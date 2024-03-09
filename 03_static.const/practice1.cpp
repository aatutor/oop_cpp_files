#include <stdio.h>

struct Student 
{
	char* name_; // ФИО
	int* marks_; // оценки
	int count_;
	static char* university;
public:
	Student(char* name, int* marks, int count);
	~Student();
	void PrintInfo() const;
	friend double MaxMark(Student stud[]);
};


int main () {

	return 0;
}
