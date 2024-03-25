// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN_NAME = 20;
const int MARK_COUNT = 3;	 

struct Student 
{
	char* name_ = nullptr; // ФИО
	int* marks_ { nullptr }; // оценки
	int count_ = 0;

	// Student();
	// Student(const char*);
	// Student(const char*, const int[], int);
	// ~Student();

	void InitStudent(const char*, const int [], int);

	void PrintStudent();
	double AverageMark();
};

int main()
{
	int studentMarks[]{ 4,4,3 };
	Student* pSt = new Student("Petr", studentMarks, 3);
	char* str = pSt->name_;
	// delete pSt;
	cout << str << endl;

	// Student stud("Alexey");

	// Student student;
	// student.InitStudent("Petrov A.O.", studentMarks, 3);

	// cout << "Student profile:\n";
	// student.PrintStudent();
	// cout << "Average mark: " << student.AverageMark() << endl;

	return 0;
}

// // заполнение данных о студенте
// void Student::InitStudent(const char* name, const int marks[], int count)
// {
// 	if (name_ == nullptr || strlen(this->name_) < strlen(name)){
// 		delete [] name_;
// 		name_ = new char[strlen(name)+1];
// 	}
// 	strcpy(this->name_, name);// \0 ?

// 	delete [] marks_;
// 	marks_ = new int[count];

// 	this->count_ = count;

// 	for (int i = 0; i < count_; i++)
// 		this->marks_[i] = marks[i];
// }
// // вычисление средней оценки
// double Student::AverageMark()
// {
// 	double sum = 0;
// 	for (int i = 0; i < count_; i++)
// 		sum += marks_[i];
// 	return sum / count_;
// }
// // вывод данных о студенте
// void Student::PrintStudent()
// {
// 	cout << name_ << endl;
// 	cout << "Marks: ";
// 	for (int i = 0; i < count_; i++)
// 		cout << setw(4) << marks_[i];
// 	cout << endl;
// }