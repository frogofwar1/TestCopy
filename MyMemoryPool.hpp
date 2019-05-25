#pragma once
class MyMemoryPool
{
public:
	MyMemoryPool();
	~MyMemoryPool();

	unsigned char* m_pChunkHead;

	void init(unsigned int blockSize, unsigned int blockNumber);
	void* alloc();
	void release(void* p);
};

