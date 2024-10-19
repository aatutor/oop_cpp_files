#include <iostream>
#include <string>
#include <initializer_list>
#include <stack>

class Ring {
    int size_;
public:
    Ring(int s): size_(s) {}
    std::string ToString() {
        return std::to_string(this->size_);
    }
    bool operator< (Ring r) {
        return this->size_ < r.size_;
    }
};
class Stick {
public:
    std::stack<Ring> st_;
    Stick(){}
    Stick(const Ring& r){
        this->st_.push(r);
    }
    std::string ToString() {
        std::stack<Ring> copy;
        copy = this->st_;
        std::string res;
        while(!copy.empty()){
            // res += copy.top().ToString();
            Ring t = copy.top();
            res += t.ToString()+"-";
            copy.pop();
        }
        return res;
    }
    bool Move(Stick& other) {
        if (this->st_.empty())
            throw "stick is empty";
            
        Ring t = this->st_.top();
        if ( t < other.st_.top() ){
            other.st_.push(t);
            this->st_.pop();
            return true;
        }
        return false;
    }
    void Swap(Stick& other) {
        if (other.st_.empty() || this->st_.top() < other.st_.top())
            this->Move(other);
        else
            other.Move(*this);
    }
};
class Hanoy {
    Stick bar_[3];
    int count_;
public:
    Hanoy(int count): count_(count){
        while(count--){
            this->bar_[0].st_.push(count);
        }
    }
    void operator>> (std::ostream& out) {
        for(int i=0; i<3; i++)
            out << bar_[i].ToString() << "\n";
    }
    void Step(){
        // odd: 0-1 0-2 1-2
        // even: 0-2 0-1 1-2
        if(count%2){
            this->bar_[0].Swap(this->bar_[2]);
            this->bar_[0].Swap(this->bar_[1]);
        }
        else{
            this->bar_[0].Swap(this->bar_[1]);
            this->bar_[0].Swap(this->bar_[2]);
            
        }
        this->bar_[1].Swap(this->bar_[2]);
    }
};

int main()
{
    using namespace std;
    Hanoy game(7);
    game >> cout;
    Stick st1(5), st2(3);
    st2.Swap(st1);
    cout << st1.ToString() << endl;
    cout << st2.ToString() << endl;
#if 0
    
    initializer_list<Ring> list{0, 1, 2};
    for(Ring r : list)
        cout << r.ToString() << "-";
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