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
	int seats_;
public:
	...
	int GetFreeSeats();
	bool Inplace(size_t people);
	bool Outplace(size_t people);
}

int main ()
{
	{
		
	}	

	return 0;
}
