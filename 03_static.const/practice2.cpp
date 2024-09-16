#include <iostream>
#include <string>

struct Student 
{
	int* marks_; // оценки
	int count_;
public:
	std::string name_; // ФИО

	static std::string university;

	Student(std::string name, int* marks, int count);
	~Student();
	std::string ToString();
	int* GetMarks();
};


int main () {
	using namespace std;
	int arr[3]{4, 4, 3};

	Student petr("Petrov", arr, 3);	
	cout << petr.ToString() << endl;

	arr[0] = 5;
	const Student ivan("Ivanov", arr, 3);
	cout << petr.ToString() << endl;

	return 0;
}
