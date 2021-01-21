/*Data: 2.85 6.74 28.93 61.22 10.00 45.34 61.78 5.75
Alex McClellan
Dr. Titus
CSC 1720
Lab 11: Template Array Based Lists
*/

#include <iostream>
#include<string>
 
#include "unorderedArrayListType.h"

using namespace std; 

int main() 
{
    unorderedArrayListType<double> numList(25); 

    double num;                                

	 //Data Entry
    cout << "Entering 8 numbers" << endl;        
                               
    numList.insertEnd(2.85);
	 numList.insertEnd(6.74);
	 numList.insertEnd(28.93);
	 numList.insertEnd(61.22);
	 numList.insertEnd(10.00);
	 numList.insertEnd(45.34);
	 numList.insertEnd(61.78);
	 numList.insertEnd(5.75);                 
 
    cout << "numList: ";               
    numList.print();                           
    cout << endl;                               

	 //Deleting a number
    cout << "Deleting 28.93" << endl; 

    numList.remove(28.93);                        
    cout << "After removing 28.93: " << endl;
    cout << "NumList: ";                       
    numList.print();                            
    cout << endl;                              
 
	 //Using insertAt
	 cout << "Using insertAt" << endl;

	 numList.print();
	 cout << endl;

	 cout << "Adding 4.32" << endl;
	 
    numList.insertAt(2, 4.32);
	
	 numList.print();
	 cout << endl << endl;

	 //Searching for a number
    cout << "Searching for 6.74" << endl;      

    if (numList.seqSearch(6.74) != -1)           
        cout << "6.74 found in numList." << endl << endl;   
    else                                        
        cout << "6.74  is not in numList." << endl << endl;  

	 //Using listSize
	 cout << "Using listSize" << endl;

	 numList.listSize();
	 cout << endl;
	
	 //Using maxListSize
	 cout << "Using maxListSize" << endl;

	 numList.maxListSize();
	 cout << endl;

	 //Using isFull
	 cout << "Using isFull" << endl;

	 numList.isFull();
	 cout << endl;

	 //Using the copy constructor
	 cout << "Using the copy constructor" << endl;
	
	 unorderedArrayListType<double> otherList = numList; 

	 cout << "List 1: " << endl;
	 numList.print();
	 cout << endl;

	 cout << "Adding to and printing List 2: " << endl;
	 
	 otherList.insertEnd(11.75);
	 otherList.print();
	 cout << endl;

	 //Using clearList and isEmpty
	 cout << "Clearing List 2" << endl;

	 otherList.clearList();

	 cout << "Checking if List 2 is empty" << endl;
	
	 otherList.isEmpty();
	 otherList.print();	
 	 cout << endl;

	 //Creating and using a list of integers
	 cout << "Creating a list of integers" << endl;

	 unorderedArrayListType<int> intList(25); 

	 intList.insertEnd(7);
	 intList.insertEnd(3);
	 intList.insertEnd(4);
	 intList.insertEnd(19);
	 intList.insertEnd(2);

	 intList.print();
	 cout << endl;

	 //Creating and using a list of strings
	 cout << "Creating a list of strings" << endl;

	 unorderedArrayListType<string> stringList(25);	
	 
	 stringList.insertEnd("Alex");
	 stringList.insertEnd("David");
	 stringList.insertEnd("George");
	 stringList.insertEnd("Ethan");
	 stringList.insertEnd("Bob");

	 stringList.print();
	 cout << endl;

    return 0;                                   
}
