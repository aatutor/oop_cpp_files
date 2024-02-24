#include <iostream>
using namespace std;

void demo1() {
	try {
		throw 404;  // return | break
	}
	catch (int code) {
		cout << "Error with code: " 
				 << code << endl;
	}
}
void demo2() {
  try {
    throw "Simple error :3";
    throw "Hard ERROR!!!";
  }
  catch (const char* str) {
    cout << str << endl;
  }
}

int main() {
  demo1();
  demo2();

  return 0;
}