#include <iostream>
#include "MyMemoryPool.hpp"

int main()
{
	MyMemoryPool m;
	m.init(sizeof(int), 1);
	getchar();
}