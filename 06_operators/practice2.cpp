#include <iostream>
using namespace std;

class Array {
    int* arr_;
    size_t size_;
public:
    Array(size_t size = 0);
    int GetElem(size_t ind) const;
    void SetElem(size_t ind, int val);
    void Print() const;
    friend ostream& operator<< (ostream& out, const Array& p);
    friend istream& operator>> (istream& in, Array& p);
    Array& operator++ ();
    bool operator= (const Array& right);
    bool operator= (Array&& right);
    Array operator+= (int value);
    Array operator+= (const Array& right);
}

int main()
{
	Array a(3);
	...

	return 0;
}