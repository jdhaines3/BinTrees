/*
* David Haines
* 362: Data Structures and Algorithms
* Project 3: Trees
* AVL Tree cpp file
*/

#include <iostream>
#include <string>
#include "AvlTree.h"

AvlTree::Node::Node(int num, int dpth)
{
	this->number = num;
	this->depth = dpth;
	this->left = NULL;
	this->right = NULL;
}

AvlTree::AvlTree()
{
}

void AvlTree::fill(int arr[])
{
	int index = 0;
	
	for (index; index < 50; index++)
	{
		int j = arr[index];
		
		this->insert(j, this->root);		
	}
}


void AvlTree::insert(int data, Node *p)
{
	if (this->root == NULL)
	{
		AvlTree::Node * temp = new Node(data, 0);
		this->root = temp;
	}
	else if (p->number == data)
	{
	}
	else if (data < p->number)
	{
		if (p->left == NULL)
		{
			AvlTree::Node * newNode = new Node(data, p->depth + 1);
			p->left = newNode;
			this->balance(p, newNode);
		}
		else 
		{	
			this->insert(data, p->left);
			this->balance(p, p->left);
		}
	}
	else if (data > p->number)
	{
		if (p->right == NULL)
		{
			AvlTree::Node * nNode = new Node(data, p->depth + 1);
			p->right = nNode;
			this->balance(p, nNode);
		}
		else
		{	
			this->insert(data, p->right);
			this->balance(p, p->right);
		}
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}


void AvlTree::balance(Node *par, Node *chld)
{
	Node* temp;
	if((chld->left->depth - chld->right->depth) > 1) 
	{
		temp = chld->left;
		if (temp->left->depth >= temp->right->depth) 
		{
			leftRot(par, chld);
		}
		else 
		{
			doubleLeft(par, child);
		}
	}
	else if ((chld->right->depth - chld->left->depth) > 1) 
	{
		temp = chld->right;
		if (temp->right->depth >= temp->left->depth) 
		{
			rightRot(par, chld);
		}
		else 
		{
			doubleRight(par, chld);
		}
	}
}

void AvlTree::leftRot(Node *par, Node *chld)
{
	Node * temp = chld->left;
	chld->left = temp->right;
	temp->right = chld;
	
	if (par == NULL)
	{
		this->root = temp;
	}
	else if (par != NULL)
	{
		if (par->left == chld)
		{
			par->left = temp;
		}
		else if (par->right == chld)
		{
			par->right = temp;
		}
	}
}

void AvlTree::rightRot(Node *par, Node *chld)
{
	Node * temp = chld->right;
	chld->right = temp->left;
	temp->left = chld;
	
	if (par == NULL)
	{
		this->root = temp;
	}
	else if (par != NULL)
	{
		if (par->left == chld)
		{
			par->left = temp;
		}
		else if (par->right == chld)
		{
			par->right = temp;
		}
	}
}

void AvlTree::doubleLeft(Node *par, Node *chld)
{
	this->rightRot(chld, chld->left);
	this->leftRot(par, chld);
}

void AvlTree::doubleRight(Node *par, Node *chld)
{
	this->leftRot(chld, chld->right);
	this->rightRot(par, chld);
}

void AvlTree::printTree()
{
	print(this->root);
}

void AvlTree::print(Node *j)
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
		space = space + "   ";
	}
		
	std::cout << space << num << std::endl;
	
	if (j->left != NULL)
	{
		print(j->left);
	}
}

AvlTree::~AvlTree()
{
}