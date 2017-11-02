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
	this->root = NULL;
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
	else if (data < p->number)
	{
		if (p->left == NULL)
		{
			AvlTree::Node * newNode = new Node(data, p->depth + 1);
			p->left = newNode;
			this->balance(p, p->left);
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
			this->balance(p, p->right);
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
	
	if (p == this->root)
	{
		this->balance(NULL, this->root);
	}
}

int AvlTree::getHeight(Node *n) 
{
	int ht;
	if (n == NULL) 
	{
		ht = 0;
	}
	else if (n != NULL) 
	{
		ht = 1;
		AvlTree::Node *lft = n->left;
		AvlTree::Node *rt = n->right;
		
		int lHeight;
		lHeight = this->getHeight(lft);
		int rHeight;
		rHeight = this->getHeight(rt);
		
		if (lHeight > rHeight) 
		{
			ht = ht + lHeight;
		}
		else if (rHeight > lHeight) 
		{
			ht = ht + rHeight;
		}
		else 
		{
			ht = ht + rHeight;
		}
	}
	return ht;
}

void AvlTree::balance(Node *par, Node *chld)
{
	AvlTree::Node *tmp;
	if((this->getHeight(chld->left) - this->getHeight(chld->right)) > 1) 
	{
		tmp = chld->left;
		if (this->getHeight(tmp->left) >= this->getHeight(tmp->right)) 
		{
			this->leftRot(par, chld);
		}
		else 
		{
			this->doubleLeft(par, chld);
		}
	}
	else if ((this->getHeight(chld->right) - this->getHeight(chld->left)) > 1) 
	{
		tmp = chld->right;
		if (this->getHeight(tmp->right) >= this->getHeight(tmp->left)) 
		{
			this->rightRot(par, chld);
		}
		else 
		{
			this->doubleRight(par, chld);
		}
	}
}

void AvlTree::leftRot(Node *par, Node *chld)
{
	AvlTree::Node * temp;
	temp = chld->left;
	chld->left = temp->right;
	temp->right = chld;
	
	if (par == NULL)
	{
		this->root = temp;
	}
	else
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
	AvlTree::Node * temp;
	temp = chld->right;
	chld->right = temp->left;
	temp->left = chld;
	
	if (par == NULL)
	{
		this->root = temp;
	}
	else
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
	this->print(this->root, 0);
}

void AvlTree::print(Node *j, int space)
{
	
	if (j == NULL)
	{
		return;
	}
	
	space += 5;
	if (j->right != NULL)
	{
		this->print(j->right, space);
	}
	
	std::cout << std::endl;
	
	for (int i = 5; i < space; i++)
	{
		std::cout << " ";
	}	
	std::cout << j->number << std::endl;
	
	if (j->left != NULL)
	{
		this->print(j->left, space);
	}
}

AvlTree::~AvlTree()
{
}