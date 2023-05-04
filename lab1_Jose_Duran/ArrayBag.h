#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 20; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag
   
	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;   

public:
	/********************************************************/
    /* Function:   ArrayBag
    /* Inputs:     N/A
    /* Outputs:    N/A
    /* Purpose:    Defaults the count of bag items to 0 and
    /*             max capacity of the bag to 20
    /********************************************************/
	ArrayBag();

	/********************************************************/
    /* Function:   bubbleSort
    /* Inputs:     N/A
    /* Outputs:    N/A
    /* Purpose:    Holds the sorting algorithm
    /********************************************************/
	void bubbleSort();

	/********************************************************/
    /* Function:   binarySearchIterative
    /* Inputs:     N/A
    /* Outputs:    N/A
    /* Purpose:    Conducts a binary search for the	item using iteration.
    /********************************************************/
	void binarySearchIterative(ItemType target);

    /********************************************************/
    /* Function:   binarySearchRecursiveHelper
    /* Inputs:     N/A
    /* Outputs:    N/A
    /* Purpose:    Calls the recursive search function so client code doesn't provide paramaters.
    /********************************************************/
    bool binarySearchRecursiveHelper(ItemType target);

	/********************************************************/
    /* Function:   binarySearchRecursive
    /* Inputs:     N/A
    /* Outputs:    N/A
    /* Purpose:    Conducts a binary search for the	item using recursion.
    /********************************************************/
	bool binarySearchRecursive(ItemType target, int start, int end);

	/********************************************************/
    /* Function:   getCurrentSize
    /* Inputs:     N/A
    /* Outputs:    integer count of current size
    /* Purpose:    Holds the sorting algorithm
    /********************************************************/
	int getCurrentSize() const;

	/********************************************************/
    /* Function:   isEmpty
    /* Inputs:     ItemType item
    /* Outputs:    True/False
    /* Purpose:    Returns bool if array is/isn't empty
    /********************************************************/
	bool isEmpty() const;

	/********************************************************/
    /* Function:   add
    /* Inputs:     ItemType item
    /* Outputs:    True/False
    /* Purpose:    Adds an item to the array.
    /********************************************************/
	bool add(const ItemType& newEntry);

	/********************************************************/
    /* Function:   remove
    /* Inputs:     ItemType item
    /* Outputs:    True/False
    /* Purpose:    Removes am item from the array.
    /********************************************************/
	bool remove(const ItemType& anEntry);

	/********************************************************/
    /* Function:   clear
    /* Inputs:     N/A
    /* Outputs:    N/A
    /* Purpose:    Deletes every item off of the array.
    /********************************************************/
	void clear();

	/********************************************************/
    /* Function:   contains
    /* Inputs:     ItemType item
    /* Outputs:    True/False
    /* Purpose:    Returns bool if item is/isn't in the array.
    /********************************************************/
	bool contains(const ItemType& anEntry) const;

	/********************************************************/
    /* Function:   getFrequencyOf
    /* Inputs:     ItemType item
    /* Outputs:    integer count of items
    /* Purpose:    Counts the times an item is listed.
    /********************************************************/
	int getFrequencyOf(const ItemType& anEntry) const;

	/********************************************************/
    /* Function:   toVector
    /* Inputs:     N/A
    /* Outputs:    Vector
    /* Purpose:    Converts array into a vector.
    /********************************************************/
    std::vector<ItemType> toVector() const;
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
