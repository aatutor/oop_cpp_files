#include <iostream>
#include <stack>

class Ring {
	int radius_;
public:
    Ring(int size): radius_(size) {}
    friend std::ostream& operator<< (std::ostream&, Ring&);
};
std::ostream& operator<< (std::ostream& out, Ring& r) {
    out << r.radius_;
    return out;
}

class Bar {
	std::stack<Ring*> st_;
public:
    void Push(Ring* r) {
        st_.push(r);
    }
    void Show() {
        std::stack<Ring*> temp(this->st_);
        std::cout << "-";
        while(temp.empty() != true) {
            std::cout << *temp.top() << "-";
            temp.pop();
        }
        std::cout << "\n|\n";
    }
};

class Hanoy {
	Bar bars_[3];
	int count_;
public:
    Hanoy(int size): count_(size) {
        while(size) {
            this->bars_[0].Push(new Ring(size));
            size--;
        }
    }
	void ShowState() {
	    for(int i=0; i<3; i++) {
	        this->bars_[i].Show();
	    }
	}
	void Solve(){
	    if (this->count_ % 2 == 0) {
	        this->bars_[0].Swap(this->bars_[1]); //1-2 [0-1]
	        this->bars_[0].Swap(this->bars_[2]); //1-3 [0-2]
	        this->bars_[1].Swap(this->bars_[2]); //2-3 [1-2]
	    } else {
	        this->bars_[0].Swap(this->bars_[2]); //1-3 [0-2]
	        this->bars_[0].Swap(this->bars_[1]); //1-2 [0-1]
	        this->bars_[1].Swap(this->bars_[2]); //2-3 [1-2]

	    }
	    std::cout << "Решено!\n\n";
	}
};

int main()
{
	Hanoy tower(4);

#if 1
	tower.Solve();
#else
	while(tower.IsSolved() == false)
		tower.Move();
#endif

    tower.ShowState();

	return 0;
}

/*
	Циклическое решение:
	Обозначим через «1-2» такое действие: переложить диск или с 1-го штыря на 2-й, 
	или со 2-го на 1-й, в зависимости от того, где он меньше. Тогда, чтобы решить 
	головоломку с чётным количеством дисков, надо многократно повторять действия: 
	1-2, 1-3, 2-3. Если число дисков нечётно — 1-3, 1-2, 2-3. 
*/