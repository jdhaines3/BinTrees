#
#David Haines
#362: Data Structures and Algorithms
#Project 3: Multilist
#Driver cpp file
#

Tree.exe: AvlTree.o BinTree.o Driver.o
	g++ AvlTree.o BinTree.o Driver.o -o Tree.exe
	
Driver.o: Driver.cpp
	g++ -c Driver.cpp
	
BinTree.o: BinTree.cpp
	g++ -c BinTree.cpp
	
AvlTree.o: AvlTree.cpp
	g++ -c AvlTree.cpp
	
clean:
	rm -f *.o
	rm -f Tree.exe
	
run:
	./Tree.exe