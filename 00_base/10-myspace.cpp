#include <stdio.h>
#include <iostream>

namespace MySpace 
{
  int x = 5;

  void foo() {
    ++x;
  }

  class A {};
}

namespace { // nameless namespace
  int y;
}

namespace MySpace 
{
  A* pa = nullptr;            
}


int main() 
{
  printf("x: %d\n", MySpace::x); // 5

  MySpace::foo();
  printf("x: %d\n", MySpace::x); // 6

  MySpace::A a;

  {           // local scope
    int y = 10;
    ::y = 5;
  }
  printf("y: \n", y); // error     
  printf("y: \n", ::y); // 5

  MySpace::pa = new MySpace::A();

  {
    using namespace MySpace;

    foo();
    A a;
    printf("x: %d\n", x);
  }
  printf("x: %d\n", x); // error

  {
    using MySpace::foo;
    using MySpace::A;

    foo();
    A a;
    printf("x: %d\n", x); // error
  }

  {
    using namespace std;

    cout << string{"Hello world"} << endl;     
  }

  {
    using std::cout;
    using std::endl;
  
    cout << std::string{"Hello world"} << endl;
  }


}