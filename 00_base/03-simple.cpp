#include <iostream>
using namespace std;

void demo1() {
	try {
		throw 404;  // return | break
	}
	catch (int err) {
		cout << "Error with code: " 
				<< err << endl;
	}
}
void demo2() {
  try {
    throw "Simple error :3";
    throw "Hard ERROR!!!";
  }
  catch (const char* err) {
    cout << err << endl;
  }
}

int main() {
  demo1();
  demo2();

  return 0;
}