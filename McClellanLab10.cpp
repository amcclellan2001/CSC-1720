/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 10: Array Based Lists
File Location: home/students/amcclellan/Lab10
*/

#include<iostream>
#include "orderedArrayListType.h"

using namespace std;

int main()
{
	int loc;
	orderedArrayListType list1;

	//Setting up the Lists
	cout << "Setting up List 1" << endl;	

	list1.insert(0, 5);
	list1.insert(0, 4);
	list1.insert(0, 3);
	list1.insert(0, 2);
	list1.insert(0, 1);
	
	list1.print();
	cout << endl;

	//Testing insertAt
	cout << "Testing List 1 with insertAt" << endl;
	
	list1.insertAt(6, 6);
	list1.insertAt(7, 7);
	
	cout <<  "Added 6 and 7 to the list" << endl;
	
	list1.print();
	cout << endl;

	//Testing insertEnd
	cout << "Testing List 1 with insertEnd" << endl;
	
	list1.insertEnd(11);
	list1.insertEnd(14);

	cout << "Added 11 and 14 to the list" << endl;
	
	list1.print();
	cout << endl;

	//Testing seqSearch
	cout << "Testing List 1 with seqSearch" << endl;
	
	cout << "Searching for 11's position" << endl;

	list1.seqSearch(11);

	cout << loc << endl << endl;

	//Testing remove
	cout << "Testing List 1 with remove" << endl;
	
	list1.remove(4);

	cout << "Removing 4 from the list" << endl;
	
	list1.print();
	cout << endl;

	//Using a copy constructor to copy List 1 to List 2
	cout << "Testing the copy constructor with List 1 to List 2" << endl;
	
	orderedArrayListType list2;

	list2 = list1;
	
	cout << "Printing List 2" << endl;
	
	list2.print();
	cout << endl;

	cout << "Adding to List 1 to test if they are separate" << endl;
	
	list1.insert(10, 17);
	
	cout << "List 1" << endl;
	list1.print();
	cout << endl;
	
	cout << "List 2" << endl;
	list2.print();
	cout << endl;

	//Overloading the Assingment Operator
	cout << "Overloading the assignment operator with List 1 to List 2" << endl;
	
	list1 = list2;
	
	cout << "List 1" << endl;
	list1.print();
	cout << endl;

	cout << "List 2" << endl;
	list2.print();
	cout << endl;

	//Using a friend function to overload stream insertion operator
	cout << "Overloading the stream insertion operator (<<)" << endl;	
	
	cout << list2 << endl;
;
}

