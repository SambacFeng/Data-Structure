
#include <iostream>
#include "bst.h"   // Defines BinarySearchTree class
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

	int MAX = 100;
	BinSearchTree<int> mybst;

	srand((unsigned)time(0));

	int item;
	cout << "The inserted numbers: \n";
	for (int i = 0; i < 10; i++)
	{ 
		item = rand() % MAX;
		cout << item << " ";
		mybst.insert(item);
	}
	cout << endl << endl;

	cout << endl << "The height: " << mybst.height() << endl;

} // binsearchtreeexample