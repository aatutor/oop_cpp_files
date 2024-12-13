// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	std::cout << 1/3 << std::endl;

	std::cout << 1.0/3 << std::endl;
	std::cout << (float)1/3 << std::endl;

	std::cout << static_cast<float>(1)/3 << std::endl;

	return 0;
}
