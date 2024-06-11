#include <iostream>
#include <string>
using namespace std;

class Car{
	int speed_;
	int maxspeed_;
public:
	string color_;
	...
	void SetSpeed(int speed);
	int GetSpeed();
}
class Bolid : public Car{
	string sponsor_;
public:
	...
	string GetSponsor();
}

class Bus : public Car{
	size_t seats_;
public:
	...
	size_t GetPeople();
	size_t GetFreeSeats();
	bool Inplace(size_t people);
	bool Outplace(size_t people);
}

int main ()
{
	{
		Car lada(110);
		lada.SetSpeed(60);
		cout << "Lada speed: " << lada.GetSpeed() << endl;
	}	
	{
		Bolid marusya(350, "Gazprom");
		marusya.SetSpeed(200);
		cout << "Bolid ride with: " << marusya.GetSpeed() 
				<< " km/h, by sponsor " << marusya.GetSponsor() << endl;
	}
	{
		Bus paz(90, 55);
		paz.Inplace(25);
		paz.SetSpeed(50);
		cout << "Pazik carry " << paz.GetPeople()
				<< " people with " << paz.GetSpeed()
				<< " km/h\n";
	}

	return 0;
}
