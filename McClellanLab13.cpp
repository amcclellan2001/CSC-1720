/*Data: 2.85 6.74 28.93 61.22 10.00 45.34 61.78 5.75
Alex McClellan
Dr. Titus
CSC 1720
Lab 11: Template Array Based Lists
*/

#include <iostream>
 
#include "unorderedArrayListType.h"

using namespace std; 

int main() 
{
    unorderedArrayListType<double> numList(25); 

    double num;                                

	 //Data Entry
    cout << "Entering 8 numbers: " << endl;        
                               
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
 
	 //Searching for a number
    cout << "Searching for 6.74: " << endl;      

    if (numList.seqSearch(6.74) != -1)           
        cout << "6.74 found in numList." << endl;   
    else                                        
        cout << "6.74  is not in numList." << endl;  

	 //Using listSize
	
	 //Using maxListSize

	 //Using isFull

	 //Using the copy constructor

	 //Using clearList

	 //Using isEmpty


    return 0;                                   
}
