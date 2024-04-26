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
	std::string zoo_;
	Lion(std::string name);
};

int main ()
{
	Animal* animals[4] = {
		new Dog("Bob"),
		new Cat("Murka"),
		new Frog("Vasya"),
		new Lion("King")
	};
	
	for(int k=0; k<4; k++)
		animals[k]->Speak();
	
	return 0;
}
