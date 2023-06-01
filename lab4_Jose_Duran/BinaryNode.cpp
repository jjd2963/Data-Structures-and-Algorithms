
#include "BinaryNode.h" // Header file

template<class EmployeeInfo> 
BinaryNode<EmployeeInfo>::BinaryNode() : employee{}, leftChildPtr{nullptr}, rightChildPtr{nullptr} {} // end default constructor

template<class EmployeeInfo>
BinaryNode<EmployeeInfo>::BinaryNode(const EmployeeInfo& newEmployee) : employee{newEmployee}, leftChildPtr{nullptr}, rightChildPtr{nullptr} {} // end constructor

template<class EmployeeInfo>
BinaryNode<EmployeeInfo>::BinaryNode(const EmployeeInfo& newEmployee, std::shared_ptr<BinaryNode<EmployeeInfo>> leftPtr, std::shared_ptr<BinaryNode<EmployeeInfo>> rightPtr) :
employee{newEmployee}, leftChildPtr{leftPtr}, rightChildPtr{rightPtr} {} // end constructor

template<class EmployeeInfo>
void BinaryNode<EmployeeInfo>::setEmployee(const EmployeeInfo& newEmployee)
{
    employee = newEmployee; 
} // end setEmployee

template<class EmployeeInfo>
EmployeeInfo BinaryNode<EmployeeInfo>::getEmployee() const
{
    return employee;
} // end getEmployee

template<class EmployeeInfo>
bool BinaryNode<EmployeeInfo>::isLeaf() const
{
    return (leftChildPtr == nullptr && rightChildPtr == nullptr);
} // end isLeaf

template<class EmployeeInfo>
auto BinaryNode<EmployeeInfo>::getLeftChildPtr() const
{
    return leftChildPtr;
} // end getLeftChildPtr

template<class EmployeeInfo>
auto BinaryNode<EmployeeInfo>::getRightChildPtr() const
{
    return rightChildPtr;
} // end getRightChildPtr

template<class EmployeeInfo>
void BinaryNode<EmployeeInfo>::setLeftChildPtr(std::shared_ptr<BinaryNode<EmployeeInfo>> leftPtr)
{
    leftChildPtr = leftPtr;
} // end setLeftChildPtr

template<class EmployeeInfo>
void BinaryNode<EmployeeInfo>::setRightChildPtr(std::shared_ptr<BinaryNode<EmployeeInfo>> rightPtr)
{
    rightChildPtr = rightPtr;
} // end setRightChildPtr