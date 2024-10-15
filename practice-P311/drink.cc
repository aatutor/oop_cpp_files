#include <iostream>
#include <initializer_list>
#include <string>

template<typename T>
struct Card {
    T value_;
    Card(T v): value_(v) {}
    std::string ToString() const {
        std::iostream s;
        s << this->value_;
        return s.str();
        // return std::to_string(this->value_);
    }
    // operator<<()
};

int main()
{
    using namespace std;
    initializer_list<Card> list {0, 1, 2, 3};
    
    for(Card x : list)
        cout << x.ToString() << " ";
        
    cout << 1 << "string" << 'c';

    return 0;
}