/*
SingletonPatternDemo1
*/

#ifndef SINGLETON_H_
#define SINGLETON_H_
#include <iostream>
class Singleton
{
public:
	static Singleton* GetInstance();
	static Singleton* GetInstance2();
private:
	Singleton();
	Singleton& operator=(const Singleton&);
	static Singleton* m_Instance;
	static const Singleton* m_Instance2;
};

const Singleton* Singleton::m_Instance2 = new Singleton();
Singleton* Singleton::m_Instance = NULL;

Singleton* Singleton::GetInstance2()
{
	std::cout << "get m_Instance2" << std::endl;
	return const_cast<Singleton*> (m_Instance2);
}
Singleton* Singleton::GetInstance()
{
	std::cout << "get m_Instanche1" << std::endl;
	if (m_Instance == NULL)
	{
		//Lock();
		//if (m_Instance == NULL)
		m_Instance = new Singleton();
		//unclock;
	}
	return m_Instance;
}

#endif