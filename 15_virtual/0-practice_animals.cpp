#include <iostream>
#include <string>

class Animal {
public:
	std::string name_;
	Animal(std::string name);
	void Speak();
};

class Frog: public Animal {
public:
	Frog(std::string name);
	void Speak();
};
class Dog: public Animal {
public:
	Dog(std::string name);
	void Speak();
};
class Cat: public Animal {
public:
	Cat(std::string name);
	void Speak();
};
class Lion: public Cat {
public:
	Lion(std::string name);
	void Speak();
};

int main ()
{
	Animal *animals[4] = {
		new Dog("Bob"),
		new Cat("Murka"),
		new Frog("Vasya"),
		new Lion("King")
	};

	for(size_t k=0; k != 4; ++k)
		animals[k]->Speak();
	
	return 0;
}
