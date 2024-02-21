#include <stdio.h>
#include <iostream>

void Test()
{
	Student stud1;
	stud1.Print();

	Student stud2;
	stud2.Init("Ivan", 18);
	stud2.Print();

	Student stud3;
	stud3.Init("Petr", -1);
	stud3.Init("", 1);
	stud3.Print();

	{
		Student stud;
		stud.Print();
	}
	{
		Student stud;
		stud.Init("Ivan", 18);
		stud.Print();
	}
	{
		Student stud;
		stud.Init("Petr", -1);
		stud.Init("", 1);
		stud.Print();
	}
}


int main ()
{
	Test();

	return 0;								
}
