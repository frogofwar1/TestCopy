#include "MyMemoryPool.hpp"

#include <stdlib.h>
#include <iostream>

MyMemoryPool::MyMemoryPool()
{
}


MyMemoryPool::~MyMemoryPool()
{
}

void MyMemoryPool::init(unsigned int blockSize, unsigned int blockNumber)
{
	const unsigned int headerSize = sizeof(m_pChunkHead);
	unsigned int realBlockSize = blockSize + headerSize;

	std::cout << "blockSize : " << blockSize << std::endl;
	std::cout << "header blockSize : " << headerSize << std::endl;
	std::cout << "Real blockSize : " << realBlockSize << std::endl;

	m_pChunkHead = reinterpret_cast<unsigned char*> (malloc( blockSize * blockNumber));
	if (m_pChunkHead != nullptr)
	{
		//Todo = Manage my own Memory
		*m_pChunkHead = 10;
		std::cout << static_cast<int>(*m_pChunkHead) << std::endl;
	}
	delete m_pChunkHead;
}

void* MyMemoryPool::alloc()
{
	return nullptr;
}

void MyMemoryPool::release(void* p)
{

}
