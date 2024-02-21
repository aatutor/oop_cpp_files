#include <stdio.h>

namespace One 
{
  int var = 1;
}
namespace Two
{
  char var = ',';
}
namespace 
{
  int var = 3;
}

int main() {
  double var = 4;

  cout <<"vars: "<< ::var 
                 << Two::var 
                 << One::var 
                 << var << endl;
}
