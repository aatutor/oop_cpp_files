#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Person {
	std::string name_;
	short age_;
public:
	Person(std::string name, short age);
	std::string Info();
};

class Student: public Person {
	int group_;
public:
	Student(std::string name, short age, int grp);
	std::string Info();
};

class Teacher: public Person {
	std::string education_;
public:
	Teacher(std::string name, short age, std::string edu);
	std::string Info();
};

void Test() 
{
	using namespace std;
	{
		Teacher t("Einstein", 42, "professor");
		cout << t.Info() << endl;
		Student s("Ivan", 20, 321);
		cout << s.Info() << endl;
	}
	cout << string(15, '-') << endl;
	{
		Teacher* t = new Teacher("Einstein", 42, "professor");
		cout << t->Info() << endl;
		Student* s = new Student("Ivan", 20, 321);
		cout << s->Info() << endl;
	}
	cout << string(15, '-') << endl;
	{
		Person* pt = new Teacher("Einstein", 42, "professor");
		cout << pt->Info() << endl;
		Person* ps = new Student("Ivan", 20, 321);
		cout << ps->Info() << endl;
	}
	cout << string(15, '-') << endl;
	{
		Person** person = new Person*[3];

		person[0] = new Teacher("Einstein", 42, "professor");
		person[1] = new Student("Ivan", 20, 321);
		person[2] = new Person("Petrovich", 53);

		for(int i = 0; i < 3; i++)
			cout << person[i]->Info() << endl;
	}
}

int main ()
{
	Test();

	return 0;
}
