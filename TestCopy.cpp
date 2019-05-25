#include <iostream>
#include <vector>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

class Item
{
public:
	int m_id;
	explicit Item(int _id) : m_id(_id) 
	{
	}
	~Item()
	{
	}
};

class Monster
{
public:
	Monster() 
	{
	}
	~Monster() 
	{

	}

	//copy constructor
	Monster(const Monster& other) 
	{
		std::vector<Item*> temp;
		for (int i = 0; i < other.items.size(); i++) {
			int id = other.items[i]->m_id;
			temp.push_back(new Item(id));
		}
		items = temp;
	}
	
	//assignment operator
	Monster& operator= (const Monster& other) {
		std::vector<Item*> temp;
		for (int i = 0; i < other.items.size(); i++) {
			int id = other.items[i]->m_id;
			temp.push_back(new Item(id));
		}
		items = temp;

		return *this;

	}

	std::vector<Item*> items;

	
};

void printAllItems( const Monster& m) {
	for (int i = 0; i < m.items.size(); ++i)
	{
		std::cout << m.items[i]->m_id << " ";
	}
	std::cout << "" << std::endl;
}

void printItem(Item i)
{
	std::cout << i.m_id << std::endl;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//printItem(60);

	Monster m1;
	for (int i = 0; i <= 5; i++) 
	{
		m1.items.push_back(new Item(i));
	}

	Monster m2;
	m2 = m1; 
	//Deep Copy

	std::cout << "Monster 1 : " ;
	printAllItems(m1);
	//print for-loop of all items

	m1.items[0]->m_id = 90;

	std::cout << "New Monster : " ;
	printAllItems(m1);

	std::cout << "Monster 2 : " ;
	printAllItems(m2);


	getchar();
}