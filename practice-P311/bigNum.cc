#include <iostream>
#include <string>

struct Digit {
	char value; // 1-byte int
	Digit* next;
	// ...?
};

class BigNumber{
	Digit* top_ = nullptr;
public:
    // BigNumber(const char* str): BigNumber(std::string{str}) {}
    BigNumber(): BigNumber("0") {}
    BigNumber(std::string str) {
        for(int i=0; i < str.size(); i++){
            this->Append(str[i]);
        }
    }
    BigNumber(BigNumber& other) {
        ...
    }
    void Append(char val) {
        Digit* t = this->top_;
        Digit* n = new Digit{ val, t };
        this->top_ = n;
    }
    void PushBack(char val) {
        if (this->top_ == nullptr)
            this->Append(val);
            
        Digit* temp = this->top_;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = new Digit{ val, nullptr };
    }
	BigNumber operator+ (BigNumber& right){
	    Digit *a, *b;
	    a = this->top_;
	    b = right.top_;
	    BigNumber result;
	    while( a != nullptr || b != nullptr ) {
	        char sum = a->value + b->value;
	        result.PushBack( sum%10 );
	        a->next->value += sum/10;
	        a = a->next;
	        b = b->next;
	    }
	    return result;
	}
    std::string ToString() {
        std::string str;
        Digit* temp = this->top_;
        while (temp != nullptr) {
            str = temp->value + str;
            temp = temp->next;
        }
        return str;
    }
};
std::ostream& operator<< (std::ostream& out, BigNumber num) {
    out << num.ToString();
    return out;
}

int main()
{
	BigNumber a("111222333444555666777888"), b("5333222111");
	
	std::cout << a << "\n" << b << "\n";

	BigNumber c = a + b;

	std::cout << c << std::endl;

	return 0;
}
