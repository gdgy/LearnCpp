#include <iostream>
#include <cstdlib>
using namespace std;

extern void TestSort();
void fun1()
{
	cout << "call fun1" << std::endl;
}
int main(int argc, char**argv)
{
	TestSort();
	
	system("pause");
}