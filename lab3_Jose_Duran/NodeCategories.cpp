#include "NodeCategories.h" // Header file

Node::Node() : next(nullptr)
{
} // end default constructor

Node::Node(const string& aCategory, const string& aLine) : 
         category(aCategory), line(aLine), next(nullptr)
{
} // end constructor

Node::Node(const string& aCategory, const string& aLine, Node* nextNodePtr) :
         category(aCategory), line(aLine), next(nextNodePtr)
{
} // end constructor

Node::~Node()
{
} // end destructor

void Node::setCategory(const string& aCategory)
{
   category = aCategory;
} // end setCategory

void Node::setLine(const string& aLine)
{
   line = aLine;
} // end setLine

void Node::setNext(Node* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

string Node::getCategory() const
{
   return category;
} // end getCategory

string Node::getLine() const
{
   return line;
} // end getLine

class Node* Node::getNext() const
{
   return next;
} // end getNext
