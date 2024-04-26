#include <iostream>
using namespace std;

struct A {
	string type_;
	A(){
		this->type_ += "A() ";
	}
	A(A& a) {
		this->type_ += a.type_;
		this->type_ += "A(&) ";
	}
};
struct B : virtual public A {
	B(){
		this->type_ += "B() ";
	}
	B(B& b):A(b){
		// this->type_ += b.type_;
		this->type_ += "B(&) ";
	}
};

A* copy(A* a) {
	return new A(*a);
}

int main() 
{
	{
		A a;
		cout << a.type_ << endl;
		// A* pa = copy(&a);
		A* pa = new A(a);
		cout << pa->type_ << endl;
		
		B b;
		cout << b.type_ << endl;
		// A* pb = copy(&b);
		A* pb = new A( *(A*)(&b) );
		cout << pb->type_ << endl;
	}
	{

	}

	return 0;
}