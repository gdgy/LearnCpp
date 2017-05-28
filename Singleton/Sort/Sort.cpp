#include <iostream>
#include <exception>
#include <ctime>
#include "Sort.h"

void randomArry(int* pArry, int len = 10, int max=100)
{
	srand((unsigned int) time(0));
	for (size_t i = 0; i < len; ++i)
		pArry[i] = rand() % 100 + 1;
}

void Swap(int&a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


int Partation(int* arry, int start, int end)
{
	if (arry == NULL || start < 0 || end <= start)
		return 0;
	if (end > start)
	{
		int beg = start;
		int middle = arry[start];
		std::cout << middle << std::endl;
		while (start < end)
		{
			while (start < end && arry[end] >= middle)
				--end;
			arry[start] = arry[end];
			while (start < end && arry[start] <= middle)
				++start;
			arry[end] = arry[start];
		}
		arry[start] = middle;
	}
	return start;
}

void Print(int * arry, int len)
{
	for (int i = 0; i < len; ++i)
		std::cout << arry[i] << " ";
	std::cout << std::endl;
}

void QuickSort(int * arry, int start, int end)
{
	int midium = Partation(arry, start, end);
	if (midium)
	{
		QuickSort(arry, start, midium - 1);
		QuickSort(arry, midium + 1, end);
	}
	
}

void InsertSort(int* arry, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int num = arry[i];
		int index = i;
		while (index > 0 && num < arry[index - 1])
		{
			arry[index] = arry[index - 1];
			--index;
		}
		/*while (index > 0)
		{
			if (arry[index - 1] > num)
			{
				arry[index] = arry[index - 1];
				--index;
			}
			else
				break;
		}*/
		arry[index] = num;
	}
}

void TestSort()
{
	const int len = 10;
	int arry[len];
	randomArry(arry, len);
	Print(arry, len);
	//QuickSort(arry, 0, len - 1);
	InsertSort(arry, len);
	Print(arry, len);
}