#include <iostream>
#include <cstdlib>
using namespace std;

typedef void(*Fun)();
class Base
{
public:

	Base(int i) :baseI(i){};
	virtual void print(void){ cout << "�������麯��Base::print()"; }
	virtual void setI(){ cout << "�������麯��Base::setI()" << endl; }
	virtual ~Base(){ cout << "call Base::~Base()" << endl; }

private:

	int baseI;

};

void TestB()
{
	Base b(5);
	//�麯����

	Fun vfunc = (Fun)*((int *)*((int*)(&b)));
	Fun vfunb = (Fun)*((int *)*((int*)(&b)) + 1);
	cout << "Hello world" << endl;
	vfunc();
	vfunb();
}

class Derive : public Base
{
public:
	Derive(int d) :Base(1000), DeriveI(d){};
	//overwrite�����麯��
	virtual void print(void){ cout << "Drive::Drive print()" << endl; }
	// Derive�������µ��麯��
	virtual void Drive_print(){ cout << "Drive::Drive_print()" << endl; }
	virtual ~Derive(){ cout << "call Derive::~Derive" << endl; }
private:
	int DeriveI;
};

void TestD()
{
	//���Ե��̳�Derive
	Derive d(10);
	Fun pFun = (Fun)(*(int*)*(int*)&d);
	Fun pFun2 = (Fun)*((int*)*(int*)&d + 1);
	//��������
	Fun pFun3 = (Fun)*((int*)*(int*)&d + 2);
	Fun pFun4 = (Fun)*((int*)*(int*)&d + 3);
	pFun();
	pFun2();
	//pFun3();
	pFun4();
	
}

void fun1()
{
	cout << "call fun1 last" << endl;
}

int main()
{
	//TestD();
	atexit(fun1);
	system("pause");
}