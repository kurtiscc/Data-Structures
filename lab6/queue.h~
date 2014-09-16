#pragma once

using namespace std;

template <typename ItemType>

class queue
{
	private:

	struct qNode 
	{
		ItemType item;
		qNode* next;

	qNode(ItemType& item) 

	 { next = NULL;
	   this->item = item;}
	};
		
	int count;
	qNode* head;
	qNode* tail;
	
public:

	queue() :

	  count(0),
	  head(NULL),
	  tail(NULL)

	  { }
	
 	 ~queue()
	  
	   { clear(); }

	void push(ItemType& name)
	{
		qNode* temp;
		if(count == 0)
		{
			temp = new qNode(name);
			head = temp;
			tail = temp;
			count++;
		}
		else
		{
			temp = new qNode(name);
			tail->next = temp;
			tail = temp;
			count++;
		}
	}

	ItemType pop()
	{
		qNode* temp;
		temp = head;
		head = head->next;
		ItemType name = temp->item;
		delete temp;
		count--;
		//cout << "queue " << getCount() << endl;
		return name;
	}

	void clear()
	  {
		  qNode* temp;
		  while(head != NULL)
		  {
			  temp = head;
			  head = head->next;
			  delete temp; 
		  }
		count = 0;
		tail = NULL;
	  }

	int getCount()
	{
		return count;
	}

};
