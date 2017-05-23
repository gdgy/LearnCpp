#include <iostream>
#include <cstdlib>
#include "String.h"
int main()
{
	String str;
	std::cout << str << std::endl;
	String str2("sdlfjsldfkj");
	str = str2;
	std::cout << str2 << std::endl;
	system("pause");
}