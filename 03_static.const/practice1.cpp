#include <iostream>
#include <string>
using std::string;

class Car {
	string model_;
	int year_;
	static string factoryName;
public:
	Car();
	string ToString();
	static void SetFactoryName (string model);
};
string Car::factoryName = "Niva";

int main ()
{
	Car lot[3];

	Car::SetFactoryName("Lada");

	Car lot2[4];

	for (int i = 0; i < 3; i++)
		cout << lot[i].ToString() << endl;

	for (int i = 0; i < 4; i++)
		cout << lot2[i].ToString() << endl;

	return 0;
}
