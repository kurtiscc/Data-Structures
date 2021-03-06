#pragma once

#include <iostream>

using namespace std;
template <typename ItemType>

class LinkedList 
{

private:

	struct Node 
	{
		ItemType item;
		Node* next;
		Node* prev;

	Node() 


	 { prev = NULL;
	   next = NULL;
	   item = "";}
	};
		

	int count;
	Node* head;
	Node* tail;
	

public:

	LinkedList() :

	  count(0),
	  head(NULL),
	  tail(NULL)

	  { }
	

 	 ~LinkedList()
	  
	   { clear(); }

	  void ins_funct1(int& curr_index, int& index, Node*& temp)
	  {
		while(curr_index != index && curr_index >= 0)
				{
					temp = temp->next;
					curr_index++;
				}
	  }

	  void ins_funct2(int& curr_index, int& index, Node*& temp)
	  {
		while(curr_index != index && curr_index >= 0)
				{
					temp = temp->prev;
					curr_index--;
				}
	  }

	  void clear()
	  {
		  Node* temp;
		  while(head != NULL)
		  {
			  temp = head;
			  head = head->next;
			  delete temp; 
		  }
		count = 0;
		tail = NULL;
	  }

	  void insert(int index, const ItemType& name)
	  {
		  Node* temp;
		  int curr_index;
		  int check_size = count / 2;

		  if(count == 0)
		  {
			  temp = new Node; //creates a new node
			  temp->item = name; // go find the node temp points to and in this node set item to name.
			  head = temp; // head points to node.
			  tail = temp; // tail points to node.
			  count++;
		  }

		  else
		  {
			  if(index == 0)
			  {
				  temp = new Node; //creates a new node
				  temp->item = name;
				  temp->prev = NULL;
				  temp->next = head;
				  head->prev = temp;
				  head = temp;
				  curr_index = 0;
				  count++;
			  }

			  else if(index == count)
			  {

				  temp = new Node; //creates a new node
				  temp->item = name; // go find the node temp points to and in this node set item to name.
				  temp->prev = tail; // makes temp point to same thing tail points to.
				  tail->next = temp;
				  tail = tail->next;
				  temp->next = NULL;
				  //curr_index = count - 1;
				  count++;
			  }
			  
			  else if(index <= check_size)
			  {
				  temp = head;
				  curr_index = 0;
				  ins_funct1(curr_index, index, temp);
				  Node* n = new Node;
				  n->item = name;
				  temp->prev->next = n;
				  n->prev = temp->prev;
				  n->next = temp;
				  temp->prev = n;
				  count++;
			  }
			  
			  else if(index > check_size)
			  {
				  temp = tail;
				  curr_index =  (count-1);
				  ins_funct2(curr_index, index, temp);
				  Node* n = new Node;
				  n->item = name;
				  temp->prev->next = n;
				  n->prev = temp->prev;
				  n->next = temp;
				  temp->prev = n; 
				  count++;
			  }
			
		  }
		  
	  }

	  ItemType remove(int index)
	  {
		  Node* temp;
		  int curr_index;
		  int check_size = count / 2;

		  if(count == 0)
		  {
			  return "";
		  }

		  else
		  {
			  if(index == 0)
			  {
				  temp = head;
				  head = head->next;
				  if (head == NULL)
				  {
					tail = NULL;
				  }
				  else
				  {
					head->prev = NULL; // Set the head node pointer to null
				  }
				  ItemType name = temp->item;
				  delete temp;
				  count--;
				  curr_index = 0;
				  return name;
				  
			  }

			  else if(index == count-1)
			  {
				  temp = tail;
				  temp->prev->next = NULL;
				  tail = temp->prev;
				  ItemType name = temp->item;
				  delete temp;
				  count--;
				  return name;
			  }
			  
			  else if(index <= check_size)
			  {
				  temp = head;
				  curr_index = 0;
				  ins_funct1(curr_index, index, temp);
				  temp->prev->next = temp->next;
				  temp->next->prev = temp->prev;
				  ItemType name = temp->item;
				  delete temp;
				  count--;
				  return name;
			  }
			  
			  else if(index > check_size)
			  {
				  temp = tail;
				  curr_index =  (count - 1);
				  ins_funct2(curr_index, index, temp);
				  temp->prev->next = temp->next;
				  temp->next->prev = temp->prev;
				  ItemType name = temp->item;
				  delete temp;
				  count--;
				  return name;
			  }
		  }
	  }
	  
	  int find(ofstream& outFile, const ItemType& name)
	  {
		  Node* temp;
		  temp = head;
		  for(int i = 0; i < count; i++)
		  {
			 if(name == temp->item)
			 {
				 return i; 
			 }
			 temp = temp->next;
		  }
		  return -1;
	  }
	  
	  void print(ofstream& outFile)
	  {
		  if(count == 0)
		  {
 			outFile << "print" << endl;
		  }
		  else
		  {
			  int print_count = 0;
			  Node* temp;
			  temp = head;
			  outFile << "print" << endl;

			  while(temp != NULL)
			  {
				print_count++;
				outFile <<"node " << print_count - 1 << ": " << temp->item << " " << endl;
				temp = temp->next;
				
			  }
			  
		  }
	  }
	  

};
