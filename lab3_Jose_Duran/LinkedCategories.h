#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "NodeCategories.h"
#include <vector>

class LinkedList
{
private:
	Node* headPtr; // Pointer to first node in the chain
	int numItems; // Variable to show number of items

public:
	LinkedList();                                   		// Default constructor
    LinkedList(const LinkedList& aList);					// Copy constructor 
	virtual ~LinkedList();                          		// Destructor
	int getCurrentSize() const;								// Accessor
	bool add(const string& aCategory, const string& aLine);	// Add a node
	vector<string> toVector() const;						// toVector

}; // end LinkedList

#include "LinkedCategories.cpp" // Implementation file
#endif
