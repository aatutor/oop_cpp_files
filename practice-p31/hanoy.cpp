#include <iostream>
#include <stack>
#include <string>

// https://github.com/aatutor/oop_cpp_files
/*
	Ханойская башня.

	Даны три стержня, на один из которых нанизаны восемь колец, 
	причём кольца отличаются размером и лежат меньшее на большем. 
	Задача состоит в том, чтобы перенести пирамиду из восьми колец 
	за наименьшее число ходов на другой стержень. За один раз 
	разрешается переносить только одно кольцо, причём нельзя класть 
	большее кольцо на меньшее.
*/

// template <typename T> class Stack { ... };

class Ring {
	int radius_;
public:
	Ring(int r): radius_(r) {}
	std::string ToString() {
	    return std::to_string(radius_);
	}
};

class Bar {
	std::stack<Ring> st_;
public:
	void Push(Ring ring){
	    this->st_.push(ring);
	}
	std::string ToString() {
	    std::string temp;
	    std::stack<Ring> copy = this->st_;
	    
	    while(copy.empty() != true){
	        temp += copy.top().ToString();
	        temp += "-";
	        copy.pop();
	    }
	    return temp;
	}
	std::string ToString(size_t n) {
	    return (n == this->st_.size()) 
	        ? (this->Extract()) 
	        : ("|") ;
	}
	std::string Extract(){
	    std::string t = st_.top().ToString();
	    st_.pop();
	    return t;
	}
};

class Hanoy {
    enum {SIZE = 3};
	Bar bars_[SIZE];
	size_t n_;
public:
    Hanoy(size_t n): n_(n) {
        while(n != 0){
            this->bars_[0].Push(Ring(n--));
        }
    }
	void ShowState(){
	    size_t n = this->n_;
	    
	    Bar temps[SIZE];
	    for (int i = 0; i < SIZE; i++) {
	        temps[i] = this->bars_[i];
	    }
	    while(n != 0){
	        for (int i = 0; i < SIZE; i++) {
	            std::cout << temps[i].ToString(n) << " ";
	        }
	        std::cout << "\n";
	        --n;
	    }
	}
};

int main()
{
	Hanoy tower(4);

	tower.ShowState();

#if 0
    Ring r[]{1,2,3};
    
    Bar b, c;
    b.Push(r[2]);
    b.Push(r[1]);
    b.Push(r[0]);
    std::cout << b.ToString() << "\n";
    std::cout << c.ToString() << "\n";

	while(tower.IsSolved() == false){
		tower.Move();
	    tower.ShowState();
	}
#endif

	return 0;
}

/*
	Циклическое решение:
	Обозначим через «1-2» такое действие: переложить диск или с 1-го штыря на 2-й, 
	или со 2-го на 1-й, в зависимости от того, где он меньше. Тогда, чтобы решить 
	головоломку с чётным количеством дисков, надо многократно повторять действия: 
	1-2, 1-3, 2-3. Если число дисков нечётно — 1-3, 1-2, 2-3. 
*/