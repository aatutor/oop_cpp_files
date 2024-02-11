
#define CONST_VARIABLE 10; 
    // на самом деле макрос
const int REAL_CONST = 20;
    // или kRealConst 
    // в венгерской нотации
class ClassName {
  type fieldName_;
  type MethodName();
}

struct Point {
	int x_;       // поле
	char name_[60];// поле
	void Print(); // метод
	double Distance(Point*); // метод
	// this – собственный объект метода
};
