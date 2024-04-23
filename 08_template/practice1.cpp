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
  T* arr_;
  int count_;
  static const int limit_ = 6; //*
public:
  Container(initializer_list<T>);
  ~Container();
  void Show();
  bool IsFull();
  void Load(T);
};


int main ()
{
	

	return 0;
}
