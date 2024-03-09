#include <stdio.h>

void Foo(char* s) {
	printf("%s\n", s);		 
}
void Bar(const char* S){
	printf("%s\n", S);
}

int main () {
	const int A = 1;
	const char S1[]{"Hello"};
	const char* P_S2{"world"};
	const int NUMBERS[]{5, 25, 125};

	const Point POINT{3, 4};

	Foo(S1); // error
	Bar(S1); // ok

	return 0;
}

