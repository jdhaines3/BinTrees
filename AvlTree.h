/*
* David Haines
* 362: Data Structures and Algorithms
* Project 3: Trees
* AVL Tree header file
*/

#ifndef AVLTREE_H
#define AVLTREE_H

class AvlTree
{
	private:
		struct Node {
			//depth for number of spaces to print on line
			int depth;
			int number;
			
			//pointers for left and right children
			Node *left, *right;
			
			//constructor for node with student number and class number
			Node(int number, int depth);
		};
		
		//iterator 
		Node *root;
		
	public:
		AvlTree();
		
		~AvlTree();
		
		void fill(int []);
		void insert(data, Node *newNode);
		
		void balance(Node *orig, Node *child);
		
		void printTree();
		void print(Node *p);
		
		void leftRot(Node *n, Node *k);
		void rightRot(Node *n, Node *k);
		
		void doubleLeft(Node *n, Node *k);
		void doubleRight(Node *n, Node *k);
};
#endif