#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcept.h"
#include "NotFoundException.h"
#include <memory>

class BinaryNodeTree : public BinaryTreeInterface<EmployeeInfo>
{
private:
   std::shared_ptr<BinaryNode<EmployeeInfo>> rootPtr;

protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   int getHeightHelper(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr) const;
   int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr) const;

   // Recursively adds a new node to the tree in a left/right fashion to keep tree balanced.
   auto balancedAdd(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr,
   std::shared_ptr<BinaryNode<EmployeeInfo>> newNodePtr);

   // Removes the target value from the tree.
   virtual auto removeValue(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr,
   const EmployeeInfo target, bool& isSuccessful);

   // Copies values up the tree to overwrite value in current node until
   // a leaf is reached; the leaf is then removed, since its value is stored in the parent.
   auto moveValuesUpTree(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr);

   // Recursively searches for target value.
   virtual auto findNode(std::shared_ptr<BinaryNode<EmployeeInfo>> treePtr,
   const EmployeeInfo& target, bool& isSuccessful) const;

   // Copies the tree rooted at treePtr and returns a pointer to the root of the copy.
   auto copyTree(const std::shared_ptr<BinaryNode<EmployeeInfo>> oldTreeRootPtr) const;

   // Recursively deletes all nodes from the tree.
   void destroyTree(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr);

   // Recursive traversal helper methods:
   void inorderTraverseHelper(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr,
                           void visit(EmployeeInfo&)) const;
                           
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinaryNodeTree();
   BinaryNodeTree(const EmployeeInfo& rootItem);
   BinaryNodeTree(const EmployeeInfo& rootItem,
   const std::shared_ptr<BinaryNodeTree>& leftTreePtr,
   const std::shared_ptr<BinaryNodeTree>& rightTreePtr);
   BinaryNodeTree(const std::shared_ptr<BinaryNodeTree>& tree);
   virtual ~BinaryNodeTree();

   //------------------------------------------------------------
   // Public BinaryTreeInterface Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;

   EmployeeInfo getRootData() const throw(PrecondViolatedExcept);
   void setRootData(const EmployeeInfo& newData);

   bool add(const EmployeeInfo& newData); // Adds an item to the tree
   bool remove(const EmployeeInfo& data); // Removes specified item from the tree

   EmployeeInfo getEntry(const EmployeeInfo& anEntry) const throw(NotFoundException);
   bool contains(const EmployeeInfo& anEntry) const;
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void BinaryNodeTree<EmployeeInfo>::inorderTraverse(void visit(EmployeeInfo&)) const;
   
   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree

#include "BinaryNodeTree.cpp"
#endif