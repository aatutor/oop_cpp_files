#include <iostream>
#include <string>

class Animal {
public:
	std::string name_;
	Animal(std::string name);
	std::string Speak();
};

class Frog: public Animal {
public:
	Frog(std::string name);
	std::string Speak();
};
class Dog: public Animal {
public:
	Dog(std::string name);
	std::string Speak();
};
class Cat: public Animal {
public:
	Cat(std::string name);
	std::string Speak();
};
class Lion: public Cat {
public:
	Lion(std::string name);
	std::string Speak();
};

int main ()
{
	Animal* animals[4] = {
		new Animal("turtle");
		new Dog("Bob"),
		new Cat("Murka"),
		new Frog("Vasya"),
		new Lion("King")
	};

	for(size_t k=0; k != 4; ++k)
		std::cout << animals[k]->Speak() << "\n";
	
	return 0;
}
