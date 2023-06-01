#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>
#include "EmployeeInfo.h" // Header File for class EmployeeInfo

template<class EmployeeInfo>
class BinaryNode
{
private:
   EmployeeInfo employee; // Employee information
   std::shared_ptr<BinaryNode> leftChildPtr; // Pointer to left child
   std::shared_ptr<BinaryNode> rightChildPtr; // Pointer to right child
   
public:
   BinaryNode();
   BinaryNode(const EmployeeInfo& newEmployee);
   BinaryNode(const EmployeeInfo& newEmployee,
              std::shared_ptr<BinaryNode> leftPtr,
              std::shared_ptr<BinaryNode> rightPtr);
   
   void setEmployee(const EmployeeInfo& newEmployee);
   EmployeeInfo getEmployee() const;
   
   bool isLeaf() const;
   
   auto getLeftChildPtr() const;
   auto getRightChildPtr() const;
   
   void setLeftChildPtr(std::shared_ptr<BinaryNode> leftPtr);
   void setRightChildPtr(std::shared_ptr<BinaryNode> rightPtr);
}; // end BinaryNode 

#include "BinaryNode.cpp" // Implemenation File
#endif  