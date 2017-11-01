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
	this->number = num;
	this->depth = dpth;
	this->left = NULL;
	this->right = NULL;
}

BinTree::BinTree()
{
}

void BinTree::fill(int arr[])
{
	int index = 0;
	
	for (index; index < 50; index++)
	{
		int j = arr[index];
		
		this->insert(j, this->root);		
	}
}

void BinTree::insert(int data, Node *p)
{
	if (this->root == NULL)
	{
		BinTree::Node * temp = new Node(data, 0);
		this->root = temp;
	}
	else if (p->number == data)
	{
	}
	else if (data < p->number)
	{
		if (p->left == NULL)
		{
			BinTree::Node * newNode = new Node(data, p->depth + 1);
			p->left = newNode;
		}
		else 
		{	
			this->insert(data, p->left);
		}
	}
	else if (data > p->number)
	{
		if (p->right == NULL)
		{
			BinTree::Node * nNode = new Node(data, p->depth + 1);
			p->right = nNode;
		}
		else
		{	
			this->insert(data, p->right);
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

void BinTree::print(Node *j)
{
	int num = j->number;
	
	if (j == NULL)
	{
		return;
	}
	
	if (j->right != NULL)
	{
		print(j->right);
	}
	
	std::string space = "";
	int sp = j->depth;
		
	for (int i = 0; i < (sp * 2); i++)
	{
		space = space + "  ";
	}
		
	std::cout << space << num << std::endl;
	
	if (j->left != NULL)
	{
		print(j->left);
	}
}

BinTree::~BinTree()
{
}

		
		
