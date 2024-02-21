#include <iostream>
using namespace std;

void err_any(int x) {
  try {
    if (x == 0) throw 55;
    if (x == 1) throw "Error one!!!11";
    if (x == 2) throw false;
  }
  catch (int err) {
    cout << "Error with code:) " 
         << err << endl;
  }
  catch (const char* err) {
    cout << err << endl;
  }
  catch (...) {  // default
    cout << "Other error =(\n";
  }
}

int main() 
{
  err_any(0);
  err_any(1);
  err_any(2);

  return 0;
}