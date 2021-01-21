#ifndef H_orderedArrayListType
#define H_orderedArrayListType
   
#include "arrayListType.h" 

class orderedArrayListType: public arrayListType
{
public:
    void insertAt(int location, int insertItem);
    void insertEnd(int insertItem);
    void replaceAt(int location, int repItem);
    int seqSearch(int searchItem) const;
    void remove(int removeItem);
	void insert(int location, int insertItem);

	friend std::ostream& operator << (std::ostream&, const orderedArrayListType&);

    orderedArrayListType(int size = 100);
      //Constructor
}; 


#endif
