// файл должен быть в кодировке Windows (1251)
// консоль, как правило, в кодировке MS DOS (866)

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void RussianMessage(const char *str)
{
  char message[256];
  //перевод строки из кодировки Windows (1251)
  CharToOemA(str, message);//в кодировку MS DOS (866)
  cout << message;// если .cpp в кодировке 1251
}

#if 1
char* ru(const char *str)
{
  char *rus = new char[strlen(str)];
  CharToOemA(str, rus);
  return rus; // плохой косяк!
}
#else
string ru(const char *str)
{
  char rus[256];
  CharToOemA(str, rus);
  return string{rus};
}
#endif

ostream& operator << (ostream& out, const char* str){
  char rus[256];
  CharToOemA(str, rus);
  // out << rus;
  std::operator<<(out, rus);
  // out << string{rus};
  return out;
}

int main() 
{
	RussianMessage("Здравствуй, мир!");


	cout << ru("привет всем") << endl;


	cout << "нормальный русский" << endl;


	return 0;
}