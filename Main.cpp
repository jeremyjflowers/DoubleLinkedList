#include "Main.h"
#include "List.h"

class Main
{
	List<int>* exampleList = new List<int>();

	exampleList.pushFront(1);
	exampleList.pushFront(3);
	exampleList.pushFront(2);
	exampleList.pushFront(5);
	exampleList.pushFront(4);
	exampleList.print();
	exampleList.sort();
	exampleList.print();

	system("pause");
};