#ifndef NODE_
#define NODE_

#include <string>
using namespace std;

class Node
{
private:
   string   category; // A string for category
   string   line; // A string for line
   Node*    next; // Pointer to next node
   
public:
   Node();
   Node(const string& aCategory, const string& aLine);
   Node(const string& aCategory, const string& aLine, Node* nextNodePtr);
   virtual ~Node();
   void setCategory(const string& aCategory);
   void setLine(const string& aLine);
   void setNext(Node* nextNodePtr);
   string getCategory() const;
   string getLine() const;
   Node* getNext() const ;
}; // end Node

#include "NodeCategories.cpp" // Implementation file
#endif