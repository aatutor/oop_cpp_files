#include <iostream>
#include <string>
using namespace std;

class Box{
  std::string value_;
public:
  Box();
  Box(const char*);
  double Size() { return 2; }
  string ToString();
};
class Car{
  std::string model_;
public:
  Car();
  Car(const char*);
  double Size() { return 3; }
  string ToString();
};
// template <typename T, int LIMIT>
template <typename T>
class Container{
  T* ptr_;
  int count_;
  static const int limit_ = 6; //*
public:
  Container(initializer_list<T>);
  ~Container();
  void Show();
  // bool IsFull();
  // void Load(T);
};


int main ()
{
	Container<int> cInt({1, 2, 5, 8});

	return 0;
}
