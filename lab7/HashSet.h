#pragma once
#include "LinkedList.h"

template <typename ItemType>

class HashSet 
{

private:

	  LinkedList<ItemType>* table;
	  int tableSize;
	  int size;

public:

	HashSet() :

	  table(NULL),
	  size(0),
	  tableSize(0)

	  {  }

	  ~HashSet()
	  {
		  clear();
	  }

unsigned int hashCode(const string& key, int tableSize)
{
	if(tableSize == 0)
		return 0;
	unsigned int hash = 0;

	for(int i = 0; i < key.length(); i++)
	{
		hash = hash * 31 + key.at(i);
	}

	unsigned int index = hash % tableSize;

	return index;
}


void clear()
{
   for(int i = 0; i < tableSize; i++)
   {
	   table[i].clear();
   }
   delete[] table;
	tableSize = 0;
	size = 0;
	table = NULL;
}

LinkedList<ItemType>* rehash_bigger()
{
	if(size == tableSize)
	{
		int oldSize = tableSize;
		tableSize = tableSize * 2 + 1;
		LinkedList<ItemType>* newTable = new LinkedList<ItemType> [tableSize];
		if(oldSize==0)
		{
			delete[] table;
			return newTable;
		}

	for(int i = 0; i < oldSize; i++)
	{
		for(int j = 0; j < table[i].get_count(); j++)
		{
			ItemType item = table[i].get(j);
			unsigned index = hashCode(item, tableSize);
			newTable[index].insert(item);
		}
	}
	delete[] table;
	return newTable;
		
	}
	return table;
}

LinkedList<ItemType>* rehash_smaller()
{
		if(size <= (tableSize -1) / 2)
		{
			int oldSize = tableSize;
			tableSize = (tableSize - 1) / 2;
			LinkedList<ItemType>* newTable = new LinkedList<ItemType> [tableSize];
			if(oldSize==0)
			{
				delete[] table;
				return newTable;
			}

		for(int i = 0; i < oldSize; i++)
		{
			for(int j = 0; j < table[i].get_count(); j++)
			{
				ItemType item = table[i].get(j);
				unsigned int index = hashCode(item, tableSize);
				newTable[index].insert(item);
			}
		}
		delete[] table;
		return newTable;
		
		}
	    return table;
}

void add(const ItemType& item) 
{
	if(find(item))
		return;
	    
		table = rehash_bigger();
		unsigned index = hashCode(item, tableSize);
		table[index].insert(item);
		size++;
}

void remove(const ItemType& item) 
{
	for(int i = 0; i < tableSize; i++)
	{
		for(int j = 0; j < table[i].get_count(); j++)
		{
			if(item == table[i].get(j))
			{
				table[i].remove(j);
				size--;
			}
		}
	}
	
	table = rehash_smaller();
}

bool find(const ItemType& item) 
{
	for(int i = 0; i < tableSize; i++)
	{
		for(int j = 0; j < table[i].get_count(); j++)
		{
			if(item == table[i].get(j) )
				return true;
		}
	}
	return false;

}

void print(ofstream& outFile)
{
	outFile << "print";
	for(int i = 0; i < tableSize; i++)
	{
		outFile << "\nhash " << i << ":";
		int counter = 0;
		for(int j = 0; j < table[i].get_count(); j++)
		{
			if(counter > 7)
			{
				outFile << "\nhash " << i << ":";
				counter = 0;
			}
			outFile << " " << table[i].get(j);
			counter++;
		}
	}
	outFile << endl;

}










/*
void print(ofstream& outFile)
{
	int hash = 0;
	int counter = 0;
	if(table == NULL)
		cout << "print" << endl;
	else if(table != NULL)
	{
		cout << "print" << endl;
		for(int i = 0; i < tableSize; i++)
		{
			cout << "hash " << hash << ": ";
			for(int j = 0; j < table[i].get_count(); j++)
			{
				string item = table[i].get(j);
				cout << item << endl;
				counter++;
			}
		    hash++;
		}
	}
}
*/

};
