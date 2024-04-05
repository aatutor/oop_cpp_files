#include <iostream>
using namespace std;

class Box{
  std::string value_;
public:
  Box(const char*);
  ~Box();
  double Size() { return 2; }
};
class Car{
  std::string model_;
public:
  Car(const char*);
  ~Car();
  double Size() { return 3; }
};

template <typename T>
class Container{
  T* arr_;
  int count_;
  static const int limit_ = 6; //*
public:
  Container(initializer_list<T>);
  ~Container();
  void Show();
  bool IsFull();
  void Add(T);
};


int main ()
{
	

	return 0;
}
