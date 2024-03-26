#include <iostream>
using namespace std;

class Array {
    int arr_[255];
    int size_ = 255;
public:
    Array(int size);
    int GetElem(int ind) const;
    void SetElem(int ind, int val);
    void Print() const;
    bool operator== (const Array& right) const;
    bool operator!= (const Array& right) const;
    Array operator+ (const Array& right) const;
    Array operator+ (int value) const;
    Array operator* (int value) const;
    Array operator- () const;
    Array operator- (const Array& right) const;
}

int main()
{
	Array a(3);
	...

	return 0;
}