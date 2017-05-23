#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <cstdlib>
class String
{
public:
	String();
	~String();
	String(const char*);
	String& operator=(const String&rhs);
	friend std::ostream& operator<<(std::ostream& os, const String&);
private:
	char* pstr;

};

String::String()
{
	pstr = new char[1];
	if (pstr != NULL)
		*pstr = '\0';

}

String::String(const char* str)
{
	if (str != NULL)
	{
		std::size_t len = strlen(str);
		pstr = new char[len + 1];
		if (pstr != NULL)
		{
			strcpy(pstr, str);
		}
	}
}

String& String::operator=(const String&rhs)
{
	if (this == &rhs)
		return *this;
	std::size_t len = strlen(rhs.pstr);
	char* tmp_pstr = new char[len + 1];
	if (tmp_pstr != NULL)
	{
		strcpy(tmp_pstr, rhs.pstr);
		delete[] pstr;
		pstr = tmp_pstr;
	}
	return *this;
}

String::~String()
{
	if (NULL != pstr)
	{
		delete[] pstr;
		pstr = NULL;
		std::cout << "call String destruct" << std::endl;
	}

}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.pstr;
	return os;
}
#endif