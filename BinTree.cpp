/*
* David Haines
* 362: Data Structures and Algorithms
* Project 3: Trees
* Binary Search Tree cpp file
*/

#include <iostream>
#include <string>
#include "BinTree.h"

BinTree::Node::Node(int num, int dpth)
{
	this->number = number;
	this->depth = dpth;
}

BinTree::BinTree()
{
	this->root = NULL;
	this->itr = NULL;
}

void BinTree::fill(int arr[])
{
	int index = 0;
	
	for (index; index < 50; index++)
	{
		int j = arr[index];
		
		insert(j);
		this->itr = root;
	}
}

void BinTree::insert(int data)
{
	if (this->root == NULL)
	{
		Node * temp = new Node(data, 0);
		this->root = temp;
	}
	else if (this->itr->number == data)
	{
	}
	else if (data < this->itr->number)
	{
		if (this->itr->left == NULL)
		{
			Node * newNode = new Node(data, this->itr->depth + 1);
		}
		else 
		{
			this->itr = this->itr->left;
			
			insert(data);
		}
	}
	else if (data > this->itr->number)
	{
		if (this->itr->right == NULL)
		{
			Node * newNode = new Node(data, this->itr->depth + 1);
		}
		else
		{
			this->itr = this->itr->right;
			
			insert(data);
		}
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}

void BinTree::clear()
{
}

void BinTree::printTree()
{
	print(this->root);
}

void BinTree::print(BinTree::Node *p)
{
	if (p->right != NULL)
	{
		print(p->right);
	}
	
	std::string space = "";
	int sp = p->depth;
		
	for (int i = 0; i < (sp * 2); i++)
	{
		space = space + " ";
	}
		
	std::cout << space << p->number << std::cout;
	
	if (p->left != NULL)
	{
		print(p->left);
	}
}

	
		
		
