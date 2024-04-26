#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
	Ханойская башня.

	Даны три стержня, на один из которых нанизаны восемь колец, 
	причём кольца отличаются размером и лежат меньшее на большем. 
	Задача состоит в том, чтобы перенести пирамиду из восьми колец 
	за наименьшее число ходов на другой стержень. За один раз 
	разрешается переносить только одно кольцо, причём нельзя класть 
	большее кольцо на меньшее.
*/

class Ring {
	int radius_;
	static int id;
public:
	Ring(): radius_(id++){}
	int GetR(){
	    return radius_;
	}
	string ToString() {
	    return to_string(this->radius_);
	}
};
int Ring::id = 0;

int x = 5;
string ToString(int z) {
    int y=10;
    return to_string(x+y+z);
}
ToString(100);

Ring r;
r.ToString();

class Bar {
	std::stack<Ring*> st_; // или std::stack<Ring*>
public:
	void Push(Ring* r){
	    st_.push(r);
	}
	size_t GetSize() {
	    return st_.size();
	}
	void ShowLevel(int lvl){
	    string s = ":";
	    if (st_.size() == lvl){
	        s = st_.top()->ToString();
	        st_.pop();
	    }
	    cout <<" "<< s << " ";
	}
	void Swap(Bar& other){
	    if (st_.size() + other.st_.size() == 0)
	        return;
	        
	    if (st_.size() == 0)
	        other.MoveTo(*this);
	    else if (other.st_.size() == 0)
	        this->MoveTo(other);
	    else {
	        if (st_.top()->GetR() > other.st_.top()->GetR())
	            other.MoveTo(*this);
	        else
	            this->MoveTo(other);
	    }
	}
	void MoveTo(Bar& target) {
	    target.st_.push(st_.top());
	    st_.pop();
	}
};

class Solver {
    size_t iter_ = 0;
    struct Ind{ size_t a, b; };
    Ind indexes_[3];
    size_t steps_ = 0;
public:
    Solver(size_t size) {
	    bool even = size+1 % 2;
	    indexes_[0] = { 0, even ? 1 : 2 };
	    indexes_[1] = { 0, even ? 2 : 1 };
	    indexes_[2] = { 1, 2 };
    }
    void Move(Bar bars[]){
        bars[indexes_[iter_].a].Swap(bars[indexes_[iter_].b]);
        iter_ = (iter_+1)%3;
        ++steps_;
    }
    size_t GetSteps() {
        return steps_;
    }
};

class Hanoy {
    static const size_t N = 3;
	Bar bars_[N];
    Ring* r;
    size_t countRings_;
    Solver solver_;
public:
    Hanoy(size_t size): 
        r(new Ring[size]), 
        countRings_(size),
        solver_(size){
        for (int i = size-1; i >= 0; --i) {
            bars_[0].Push(r + i);
        }
    }
	void ShowState(){ // console output
	    Bar copy[N];
	    size_t max = 0;
	    for (int i = 0; i < N; i++){
	        copy[i] = bars_[i];
	        if (max < bars_[i].GetSize())
	            max = bars_[i].GetSize();
	    }
	    ++max;
	    while(max > 0) {
	        for (int i = 0; i < N; i++) {
	            copy[i].ShowLevel(max);
	        }
            cout << endl;
	        --max;
	    }
	    cout << string(9, '-') << endl;
	}
	void Solve() {
	    bool even = countRings_+1 % 2;
	    
	    while(bars_[N-1].GetSize() != countRings_){
	        solver_.Move(bars_);
            ShowState();
            // bars_[0].Swap(bars_[f]);
            // ShowState();
            // bars_[0].Swap(bars_[s]);
            // ShowState();
            // bars_[1].Swap(bars_[2]);
            // ShowState();
	    }
	}
	size_t GetSteps() {
	    return solver_.GetSteps();
	}
};

int main()
{
// 	std::cout << "main";
	Hanoy tower(5);
	
	tower.Solve();
	cout << tower.GetSteps() << endl;
	
// #if 0
// 	tower.Solve();
// #else
// 	while(tower.IsSolved() == false)
// 		tower.Move();
// #endif

	return 0;
}

/*
	Циклическое решение:
	Обозначим через «1-2» такое действие: переложить диск или с 1-го штыря на 2-й, 
	или со 2-го на 1-й, в зависимости от того, где он меньше. Тогда, чтобы решить 
	головоломку с чётным количеством дисков, надо многократно повторять действия: 
	1-2, 1-3, 2-3. Если число дисков нечётно — 1-3, 1-2, 2-3. 
*/