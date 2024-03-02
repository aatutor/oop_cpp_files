#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN_NAME = 20;
const int MARK_COUNT = 3;	 

struct Student 
{
	char* name_; // ФИО
	int* marks_; // оценки
	int count_;

	Student();
	Student(const char*);
	Student(const char*, const int[], int);
	~Student();

	void InitStudent(const char*, const int [], int);

	void PrintStudent();
	double AverageMark();
};

int main()
{
	cout << "Student profile.\n";

	Student student;
	int studentMarks[]{ 4,4,3 };

	Student stud("Alexey");
	Student st2("Petr", studentMarks, 3);
	// Student st3("Alex", studentMarks);

	const char* studentName{ "Petrov A.O." };

	student.InitStudent(studentName, studentMarks, 3);
	student.PrintStudent();
	cout << "Average mark: "
		<< fixed << setprecision(2)
		<< student.AverageMark() << endl;
	return 0;
}

Student::Student(): Student("Ivan") {}
Student::Student(const char* name): Student(name, {}, 0) {}
// Student::Student(const char* name, const int marks[], int count){
// 	// InitStudent(name, marks, count);

//	 this->name_ = new char[strlen(name)+1];
//	 strcpy(this->name_, name);

// 	this->count_ = count;

//	 this->marks_ = new int[count];
//	 for (int i = 0; i < count_; i++)
//		 this->marks_[i] = marks[i];
// }

Student::Student(
		const char* name, 
		const int marks[], 
		int count)
	:count_ (count), 
	name_(new char[strlen(name)+1]),
	marks_(new int[count])
{
	strcpy(this->name_, name);

	for (int i = 0; i < count_; i++)
		this->marks_[i] = marks[i];
}
Student::~Student(){
	delete [] name_;
	delete [] marks_;
}

// заполнение данных о студенте
void Student::InitStudent(const char* name, const int marks[], int count)
{
	if (name_ == nullptr || strlen(this->name_) < strlen(name)){
		delete [] name_;
		name_ = new char[strlen(name)+1];
	}
	strcpy(this->name_, name);// \0 ?

	delete [] marks_;
	marks_ = new int[count];

	this->count_ = count;

	for (int i = 0; i < count_; i++)
		this->marks_[i] = marks[i];
}
// вычисление средней оценки
double Student::AverageMark()
{
	double sum = 0;
	for (int i = 0; i < count_; i++)
		sum += marks_[i];
	return sum / count_;
}
// вывод данных о студенте
void Student::PrintStudent()
{
	cout << name_ << endl;
	cout << "Marks: ";
	for (int i = 0; i < count_; i++)
		cout << setw(4) << marks_[i];
	cout << endl;
}