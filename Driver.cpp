/*
* David Haines
* 362: Data Structures and Algorithms
* Project 3: Trees
* Driver cpp file
*/


//include binary search tree and avl tree; node is included in each and doesn't need to be called in driver
#include "BinTree.h"
#include "AvlTree.h"

//other includes
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iostream>


//function prototypes
void loadFile(int []);
void menu(BinTree *bst, AvlTree *avl, int []);


///---Menu Function---///
void menu(BinTree *bst, AvlTree *avl, int arr[])
{
	//exit loop variable
	int keepGoing = 0;
	
	//menu loop
	while (keepGoing == 0)
	{
		std::string input = "";
		
		std::cout << "" << std::endl;
		std::cout << "Please choose what you would like to do:" << std::endl;
		std::cout << "1) Load tree data file" << std::endl;
		std::cout << "2) Build and print Binary Search Tree" << std::endl;
		std::cout << "3) Build and print AVL Tree" << std::endl;
		std::cout << "4) Destroy tree(s) and exit program" << std::endl;
		std::cout << "" << std::endl;
		std::cin >> input;
		
		if (input == "1")
		{
			//load file function to fill array from csv
			loadFile(arr);
		}
		else if (input == "2")
		{
			//make sure file was loaded first
			if (arr != NULL)
			{
				//fill Binary Search Tree
				bst->fill(arr);
			
				//print Binary Search Tree
				bst->printTree();
			}
			else 
			{
				std::cout << std::endl;
				std::cout << "No file loaded. Please load the file first, or ensure it exists." << std::endl;
				std::cout << std::endl;
			}
		}
		else if (input == "3")
		{
			//make sure file was loaded first
			if (arr != NULL)
			{
				//fill Binary Search Tree
				avl->fill(arr);
			
				//print Binary Search Tree
				avl->printTree();
			}
			else 
			{
				std::cout << std::endl;
				std::cout << "No file loaded. Please load the file first, or ensure it exists." << std::endl;
				std::cout << std::endl;
			}
		}
		else if (input == "4")
		{
			//break loop and exit program
			std::cout << std::endl;
			std::cout << "Understood, exiting now." << std::endl;
			std::cout << std::endl;
			
			//bst->clear();
			//avl->clear();
			
			keepGoing = 1;
		}
		else
		{
			//invalid input catch
			std::cout << std::endl;
			std::cout << "Invalid input. Please try again. Enter a number (1 - 4)." << std::endl;
			std::cout << std::endl;
		}
	}
	
	std::cout << std::endl;
	std::cout << "Thank you for using the program. Goodbye." << std::endl;
	std::cout << std::endl;
	
	return;
}

///---Load File Function---///
 void loadFile(int arr[])
 {	
	//Extracted line variable
	std::string line = "";
	//create int that will be the converted input string
	int number;
	//create string that holds individual number in csv file
	std::string strInt = "";
	
	
	//Stringstream instance for reading in and delimiting and another for str to int conversion
	std::stringstream ss;
	std::stringstream converter;
	
	
	//Input Stream Variable (opens file, too)
	std::ifstream inputFile("treenode.txt");
	
	
	//see if it is open; if so, read in numbers and place in array
	if (inputFile.is_open())
	{		
		
		//--while loop to get each line--//
		while (std::getline(inputFile, line))
		{
			//clear ss object and ready it for use
			ss.clear();
			ss.str("");
			
			//set ss object to take in current line
			ss.str(line);
			
			//declare numbers array index variable
			int i = 0;
			
			//--second while loop to parse through comma delimited values--//
			/*
			*Takes in ss value (read-in line), sepearates field based on commas in line,
			*loops through all fields, sets strInt to field value, convert and put in array,
			*then moves to next field
			*/
			while (std::getline(ss, strInt, ','))
			{
				//clear converter from last field value
				converter.clear();
				converter.str("");
			
				//convert string to decimal/int: take in the string variable for each csv field, put out into int variable
				converter << strInt;
				converter >> number;
				
				//set the output number to array element with index i and increment i
				arr[i] = number;
				i++;
			}
		}
		
		//close the input stream
		inputFile.close();
		
		//print array with array concatenation function	
		std::cout << "" << std::endl;
		std::cout << "File imported." << std::endl;
		std::cout << "" << std::endl;		
	}
	else
	{
		//if file can't be opened, print message to user.
		std::cout << "" << std::endl;
		std::cout << "Unable to open file." << std::endl;
		std::cout << "" << std::endl;
	}
	
	return;
 }
 
 
 ///---Main---///
 int main()
 {
	//create input array 
	int arr[50];
	
	//create new instances of binary search tree and avl tree
	BinTree * bst = new BinTree();
	AvlTree * avl = new AvlTree()
	
	//call menu
	menu(bst, avl, arr); //avl, arr);
	
	//delete instances and return 0;
	delete bst;
	delete avl;
	return 0;
 }