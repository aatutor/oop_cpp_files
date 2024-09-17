#include <iostream>
#include <string>
using std::string;

class Car {
	string model_;
	short year_;
	static string factoryName;
public:
	Car(string model, short year);
	string ToString();
	static void SetFactoryName (string factory);
};
string Car::factoryName = "Niva";


int main ()
{
	Car lot("Renaut logan", 2010);

	// Car::SetFactoryName("Lada");

	Car lot2("Lada vesta");

	std::cout << lot.ToString() << "\n";
	std::cout << lot2.ToString() << "\n";

	return 0;
}
