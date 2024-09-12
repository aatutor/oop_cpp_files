#include <iostream>
#include <string> // класс
using namespace std;

int main()
{
  std::string h {"Helly"};    
  std::string w = "world";
  std::string str = h;
  str += " ";
  str.append(w + "!");
  str[4] = 'o';

  std::cout << str << std::endl;
  std::cout << str.size() << std::endl;
}
