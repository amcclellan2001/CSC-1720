
#include <iostream>
#include "orderedArrayListType.h" 

using namespace std; 
 
void orderedArrayListType::insert(int location, int insertItem)
{
	bool found = false;

	if (length == 0)
		list[length++] = insertItem;

	else if (length == maxSize)
	{
	cout << "Cannot insert in a full list. Adding to maxSize." << endl;
	maxSize++;
	}

	for (int i = length; i > location; i--)
		list[i] = list[i-1];
		
	length++;
	list[location] = insertItem;
		
}

void orderedArrayListType::insertAt(int location, int insertItem)
{
	insert(location, insertItem);
}

void orderedArrayListType::insertEnd(int insertItem)
{
	int location = length;

	insert(location, insertItem);
}

int orderedArrayListType::seqSearch(int searchItem) const
{
    int loc;
    bool found = false;

    loc = 0;

    while (loc < length && !found)
        if (list[loc] == searchItem)
				found = true;

        else
            loc++;

    if (found = true)
    { 
    return loc;
	 cout << loc << endl;
	 }


    else
        return -1;
} //end seqSearch


void orderedArrayListType::remove(int removeItem)
{
    int loc;

    if (length == 0)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
} //end remove

void orderedArrayListType::replaceAt(int location, int repItem)
{
    if (location < 0 || location >= length)
        cout << "The location of the item to be "
             << "replaced is out of range." << endl;
    else
        list[location] = repItem;
} //end replaceAt

orderedArrayListType::orderedArrayListType(int size)
                       : arrayListType(size)
{
}  //end constructor

std::ostream&  operator << (std::ostream&, const orderedArrayListType&)
{
}; //Overloader
