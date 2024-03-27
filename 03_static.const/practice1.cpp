#include <iostream>
#include <string>
using std::string;

struct Student 
{
	string name_; // ФИО
	int* marks_; // оценки
	int count_;
	static string university;
public:
	Student(string name, int* marks, int count);
	~Student();
	void PrintInfo() const;
	friend int MaxMark(Student* stud[], int n);
};


int main () {

	return 0;
}
