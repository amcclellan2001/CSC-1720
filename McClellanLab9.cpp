/*
Alex McClellan
Dr. Titus
CSC 1720
Lab 9: Array Based Lists
File Location: home/students/amcclellan/csc1720/McClellanLab9
*/

#include<iostream>
#include "arrayListType.h"
#include "unorderedArrayListType.h"

using namespace std;

int main()
{
	//Variables and List
	unorderedArrayListType list1(20);
	unorderedArrayListType list2(10);
	
	//Setting up the Array
	cout << "List 1: Setup" << endl;

	list1.insertFirst(2);
	list1.insertFirst(0);
	list1.insertFirst(8);
	list1.insertFirst(6);
	list1.insertFirst(1);
	list1.insertFirst(5);
	list1.insertFirst(3);
	list1.insertFirst(9);
	list1.insertFirst(7);
	list1.insertFirst(10);

	list1.insertAt(3, 3);
	
	cout << "List = ";
	list1.print();
	cout << endl << endl;

	//Testing removeAt
	cout << "List 1: removeAt" << endl;	

	list1.removeAt(5);
	
	cout << "List = ";
	list1.print();
	cout << endl << endl;	
		
	//Testing insertFirst
	cout << "List 2: Setup" << endl;

	list2.insertFirst(0);
	list2.insertFirst(5);
	list2.insertFirst(5);
	list2.insertFirst(2);
	list2.insertFirst(30);
	list2.insertFirst(12);
	list2.insertFirst(6);
	list2.insertFirst(3);

	cout << "List = ";
	list2.print();
	cout << endl << endl;

	//Testing removeAll
	cout << "List 2: removeAll" << endl;
	
	list2.removeAll(5);

	cout << "List = ";
	list2.print();
	cout << endl;
	
	return 0;
}
