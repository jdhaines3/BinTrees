/*
* David Haines
* 362: Data Structures and Algorithms
* Project 3: Trees
* Binary Search Tree header file
*/

#ifndef BINTREE_H
#define BINTREE_H

class BinTree
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
		Node *itr;
		Node *root;
		
		
	public:
		BinTree();
				
		~BinTree();
		
		void fill(int []);
		
		void insert(int i);
		
		void clear();
		
		void printTree();
		
		void print(Node *p);
		
};

#endif
		