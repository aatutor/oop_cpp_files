#include <iostream>
using namespace std;

class ParentOne {
public:
	int common_ = 1;
};

class ParentTwo {
public:
	int common_ = 2;
};

class Child : public ParentOne, public ParentTwo {};


int main ()
{
	Child ch;
#if 0
	cout << ch.common_ << endl; // fail: 'common_' is ambiguous
#endif
	cout << ch.ParentOne::common_ << endl;
	cout << ch.ParentTwo::common_ << endl;

	return 0;
}
