#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue 
{
public:
	int inventorySize;
	int entries;
	T* inventory;

	Queue()
	{
		inventorySize = 1;
		entries = 0;
		inventory = new T[inventorySize]{ -1 };

	}

	//RULE OF THREE
	//Copy Constructor
	Queue(const Queue& other)
	{
		//cout << "Copy Constructor" << endl;

		inventorySize = other.inventorySize;
		entries = other.entries;
		inventory = new T[inventorySize];

		for (int i = 0; i < inventorySize; i++)
		{
			inventory[i] = other.inventory[i];
		}
	}
	//Copy Assignment Operator
	Queue& operator =(const Queue& other)
	{
		// << "Copy Assignment Operator" << endl;

		//check if we are assigning something to itself
		if (this == &other)
		{
			return *this;
		}

		//make sure the inventory is null
		if (inventory != nullptr)
		{
			delete[] inventory;
			inventory = nullptr;
		}

		inventorySize = other.inventorySize;
		inventory = new T[inventorySize];

		for (int i = 0; i < inventorySize; i++)
		{
			inventory[i] = other.inventory[i];
		}


		return *this;
	}

	//DECONSTRUCTOR
	~Queue()
	{
		delete[] inventory;
		inventorySize = 0;
		inventory = nullptr;
	}

	//PUSH
	void Push(T addition)
	{
		int position = 0;
		int lastIndex = GetSize();
		//cout << "entries : " << lastIndex << endl;
		//make sure the inventory is the correct size

		if (lastIndex == inventorySize - 1)
		{
			inventorySize *= 2;
			T* newInventory = new T[inventorySize]{ 0 };
			for (int i = 0; i <= lastIndex; i++)
			{
				newInventory[i] = inventory[i];
			}
			delete[] inventory;
			inventory = newInventory;
			newInventory = nullptr;
		}

		while (position < lastIndex && addition > inventory[position])
		{
			position++; 
		}

		//put the addition into the new position and shift the remaining items
		if (position == inventorySize - 2)
		{
			inventory[inventorySize - 2] = addition;
			inventory[inventorySize - 1] = -1;
			entries++;
			return;
		}
		for (int i = inventorySize-1; i >= position; i--)
		{
			inventory[i] = inventory[i - 1];
		}
		entries++;
		inventory[position] = addition;
	}

	//POP
	T Pop()
	{
		//return the first index in the array
		//and move the queue forward

		T ret = inventory[0];
		for (int i = 0; i < inventorySize-1; i++) 
		{
			inventory[i] = inventory[i + 1];
		}
		entries--;
		return ret;
	}

	//PRINT
	void Print()
	{
		cout << endl;
		int size = GetSize();
		for (int i = 0; i < size; i++)
		{
			cout << inventory[i] << ", ";
		}
		cout << endl;
	}

	//GETSIZE
	int GetSize()
	{
		//for (int i = 0; i < inventorySize; i++)
		//{
		//	//cout << "Getting size" << endl;
		//	if (inventory[i] == -1)
		//	{
		//		return i;
		//	}
		//}
		return entries;
	}
	//ISEMPTY
	bool IsEmpty()
	{
		//is there any information in the stack
		if (inventory[0] == -1)
		{
			return false;
		}
		return true;
	}
};