#pragma once

#include "queue.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template <typename ItemType>

class AVLTreeSet 
{

private:

	struct Node 
	{
		ItemType item;
		Node* left;
		Node* right;
		int height;

		Node(ItemType& item) 

		{ left = NULL;
		  right = NULL;
		  this->item = item;
		  height = 1;
		}

	};

	Node* root;
	int size;

public:

	AVLTreeSet() :

	  size(0),
	  root(NULL)

	  { }

	  ~AVLTreeSet()

	  { clear(); 
	  }

void two_children_check(Node* t)
{
  if(t->left == NULL && t->right == NULL)
	  {
		 delete t;
		 t = NULL;
	  }
}
	  

Node* balance(Node* t)
  {
	    if(get_height(t->left) - get_height(t->right) > 1)
		{
			if(get_height(t->left->right) > get_height(t->left->left))
			{
				t = double_rotate_right(t);
			}
			else
			{
				t = single_rotate_right(t);
			}
			
		}

		else if(get_height(t->right) - get_height(t->left) > 1)
		{
			if (get_height(t->right->left) > get_height(t->right->right))
			{
				t = double_rotate_left(t);
			}
			else
			{
				t = single_rotate_left(t);
			}
			
		}
		return t;
  }

  Node* single_rotate_right(Node* k2)
  {
	  Node* k1;

	  k1 = k2->left;
	  k2->left = k1->right;
	  k1->right = k2;

	  set_height(k2);
	  set_height(k1);

	  return k1;
  }

  Node* single_rotate_left(Node* k2)
  {
	  Node* k1;

	  k1 = k2->right;
	  k2->right = k1->left;
	  k1->left = k2;

	  set_height(k2);
	  set_height(k1);

	  return k1;
  }

  Node* double_rotate_left(Node* k3)
  {
	  k3->right = single_rotate_right(k3->right);

	  return single_rotate_left(k3);
  }

  Node* double_rotate_right(Node* k3)
  {
	  k3->left = single_rotate_left(k3->left);

	  return single_rotate_right(k3);
  }

  void set_height(Node* n)
  {
	  if(n != NULL)
	  n->height = max(get_height(n->left),get_height(n->right))+1;
  }

  int get_height(Node* n)
  {
	  if(n == NULL)
		  return 0;
	  else
		  return n->height;
  }

  ItemType findMin() const {
	  return findMin(root);
  }

  ItemType findMin(Node* t) const
  {
	  if(t->left == NULL)
		  return t->item;

	  else
		  return findMin(t->left);
  }
  Node* findMax(Node* t)
  {
	  if(t == NULL)
		  return NULL;
	  else if (t->right == NULL)
		  return t;
	  else
		  return findMax(t->right);
  }

void clear() 
{
	clear(root);
	root = NULL;
}
void clear(Node* t)
{
	if(t != NULL)
	{
		clear(t->left);
		clear(t->right);
		delete t;
		t = NULL;
	}
}

  void add( ItemType& item) 
  {
	root = add(root, item);
  }

  Node* add(Node* t,  ItemType& item)
  {

	  if(t == NULL)
	  {
		  size++;
		  return t = new Node(item);
	  }

	  else if(item < t->item)
	  {
		  t->left = add(t->left, item);
		  size++;
	  }

	  else if (item > t->item)
	  {
		  t->right = add(t->right, item);
		  size++;
	  }

		  set_height(t);
		  t = balance(t);

	  return t;
  }

  void remove(const ItemType& item) 
  {
	  root = remove(root, item);
  }

  Node* remove(Node* t, const ItemType& item)
  {
	  Node* n = t;

	  if(t == NULL)
		  return NULL;

	  else if(item < t->item)
		  t->left = remove(t->left, item);
	  
	  else if(item > t->item)
		  t->right = remove(t->right, item);

	  //two_children_check(t);

	  else if (t->left == NULL)
	  {
		  t = t->right;
		  delete n;
		  n = NULL;
	  }
	  
	  else if (t->right == NULL)
	  {
		  t = t->left;
		  delete n;
		  n = NULL;
	  }

	  else
	  {
		  t->item = findMin(t->right);
		  t->right = remove(t->right, t->item);
	  }

	  if( t != NULL)
	  {
		  set_height(t);
		  t = balance(t);
	  }

	  return t;
  }

  bool find(const ItemType& item) const
  {
	return find(root,item);
  }

  bool find(Node* t, const ItemType& item) const
  {
	  if (t == NULL)
		  return false;

	  else if (item < t->item)
		  return find(t->left, item);
	  
	  else if (item > t->item)
		  return find(t->right, item);
	  
	  else 
	  return true;
  }

void check_child(queue<Node*>& next, Node* temp)
{
	if(temp->left != NULL)
	{
	   next.push(temp->left);
	}

	if(temp->right != NULL)
	{
	   next.push(temp->right);
	}
}

void print(ofstream& outFile)
{
	Node* temp;
	queue<Node*> current;
	queue<Node*> next;
	int level = 0;
	int counter = 0;
	if(root == NULL)
	{
	    outFile << "print" << endl;
	}
	else if (root != NULL)
	{
		outFile << "print" << endl;
		current.push(root);
		outFile << "level " << level << ": ";
		while(current.getCount() != 0)
		{ 
		   
		   temp = current.pop();
		 if(counter > 7)
		   {
			   outFile << endl;
			   outFile << "level " << level << ": ";
			   counter = 0;
		   }
		
		   outFile << temp->item << "(" << get_height(temp) << ")" << " ";
		   counter++;
	
		   check_child(next, temp);
   		  

			if(current.getCount() == 0)
			{
				while(next.getCount() != 0)
				{
				    temp = next.pop();
				    current.push(temp);
				}
				level++;
				if(current.getCount() != 0)
				{
					outFile << endl << "level " << level << ": ";
					counter = 0;
				}
				else 
					outFile << endl;
			}
		}

	}
}
 
};





