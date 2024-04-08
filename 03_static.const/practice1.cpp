#include <iostream>
#include <string>
using std::string;

class Car {
	string model_;
	int year_;
	static string conveyourModel_;
public:
	Car();
	string ToString();
	static void SetConveyourModel (string model);
};
string Car::conveyourModel_ = "Niva";


int main () 
{
	Car lot[3];

	Car::SetConveyourModel("Lada");

	Car lot2[4];

	for (int i = 0; i < 3; i++)
		cout << lot[i].ToString() << endl;

	for (int i = 0; i < 4; i++)
		cout << lot2[i].ToString() << endl;

	return 0;
}
