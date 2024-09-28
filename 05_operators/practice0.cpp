#include <iostream>
#include <string>

class Student {
	std::string name_;
	short born_;
	short age_;
public:
	Student(std::string name, short year);
	std::string ToString();
	void operator+ (std::string name);
	short operator+ (short age); // return year
};

int main ()
{
	Student student("Ivan", 2010);
	student + "Petrov";
	std::cout << student.ToString(); // Ivan Petrov (14)

	return 0;
}
