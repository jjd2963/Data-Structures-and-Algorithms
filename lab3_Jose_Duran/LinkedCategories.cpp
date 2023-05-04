#include "LinkedCategories.h" // Header file

LinkedList::LinkedList() : headPtr(nullptr)
{
}   // end default constructor

LinkedList::LinkedList(const LinkedList& aList)
{
    Node* origChainPtr = aList.headPtr;

    headPtr = new Node();
    headPtr->setCategory(origChainPtr->getCategory());
    headPtr->setLine(origChainPtr->getLine());

    Node* newChainPtr = headPtr;

    origChainPtr = origChainPtr->getNext();

    while (origChainPtr != nullptr)
    {
        // Get next category and line from original chain
        string nextCategory = origChainPtr->getCategory();
        string nextLine = origChainPtr->getLine();
        
        // Create a new node containing the next category and line
        Node* newNodePtr = new Node(nextCategory, nextLine);
         
        // Link new node to end of new chain
        newChainPtr->setNext(newNodePtr);
         
        // Advance pointer to new last node
        newChainPtr = newChainPtr->getNext();
         
        // Advance original-chain pointer
        origChainPtr = origChainPtr->getNext();
    }  // end while

    newChainPtr->setNext(nullptr);      // Flag end of chain
} // end copy constructor

LinkedList::~LinkedList()
{
    while (headPtr != nullptr)
    {
        Node* nodeToDeletePtr = headPtr; // set node to delete pointer to headptr
        headPtr = headPtr->getNext();

        // remove the node by setting pointers to null and deleting
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
    } // end while

    numItems = 0;
} // end destructor

int LinkedList::getCurrentSize() const
{
    return numItems;
} // end accessor

bool LinkedList::add(const string& aCategory, const string& aLine)
{
    Node* newNodePtr = new Node(); 
    newNodePtr->setCategory(aCategory);
    newNodePtr->setLine(aLine);

    if (headPtr == nullptr)
    {
        newNodePtr->setNext(headPtr); // add node at headptr
		headPtr = newNodePtr; 
    } // end if
    else if (aCategory <= headPtr->getCategory())
    {
        if (aLine <= headPtr->getLine())
        {
            // set node before headptr
            newNodePtr->setNext(headPtr);
		    headPtr = newNodePtr;
        } // end if
        else
        {
            Node* prevPtr = headPtr; // set pointer for previous node as headptr
		    while (prevPtr->getNext() != nullptr &&
		        prevPtr->getNext()->getLine() < aLine)
		    {
                prevPtr = prevPtr->getNext(); 
            } // end while
            // set node after prev pointer
            newNodePtr->setNext(prevPtr->getNext());
		    prevPtr->setNext(newNodePtr);
        } // end else
    } // end else if
    else
    {
        Node* prevPtr = headPtr; // set pointer for previous node as headptr
		while (prevPtr->getNext() != nullptr &&
		    prevPtr->getNext()->getCategory() < aCategory)
		{
            prevPtr = prevPtr->getNext();
        } // end while
        while (prevPtr->getNext() != nullptr &&
		    prevPtr->getNext()->getLine() < aLine)
		{
            prevPtr = prevPtr->getNext();
        } // end while

        // set node after prev pointer
        newNodePtr->setNext(prevPtr->getNext());
		prevPtr->setNext(newNodePtr);
    } // end else
    return true;
} // end add a node

vector<string> LinkedList::toVector() const
{
    vector<string> listContents; // declare vector object listContents
    Node* curPtr = headPtr; // set pointer to headptr
    
    while (curPtr != nullptr)
    {
        listContents.push_back(curPtr->getCategory()); // push cateogry into vector
        listContents.push_back(curPtr->getLine()); // push line into vector
        curPtr = curPtr->getNext(); // traverse to next node

    } // end while
    return listContents;
} // end toVector