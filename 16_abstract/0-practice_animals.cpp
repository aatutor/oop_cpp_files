#include <iostream>
#include <string>

class Animal {
protected:
	std::string name_;
	std::string kind_;
public:
	Animal(std::string name, std::string kind);
	virtual void Speak()=0;
};

class Frog: public Animal {
public:
	Frog(std::string name);
};
class Dog: public Animal {
public:
	Dog(std::string name);
};
class Cat: public Animal {
public:
	Cat(std::string name);
};
class Lion: public Cat {
public:
	std::string* zoo_;
	Lion(std::string name);
	void AddZoo(std::string zoo);
	void EraseZoo(std::string zoo);
	~Lion();
};

#define COUNT 4
int main ()
{
	Lion* leo = new Lion("King");
	leo->AddZoo("Siberia");

	Animal* animals[] = {
		new Dog("Bob"),
		new Cat("Murka"),
		new Frog("Vasya"),
		leo
	};
	
	for(int k=0; k<COUNT; k++)
		animals[k]->Speak();

	for(int k=0; k<COUNT; k++)
		delete animals[k];
	
	return 0;
}
