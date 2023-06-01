#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include "BinaryNode.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

template<class EmployeeInfo>
class BinarySearchTree {
private:
    std::shared_ptr<BinaryNode<EmployeeInfo>> rootPtr;

    std::shared_ptr<BinaryNode<EmployeeInfo>> placeNode(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr, std::shared_ptr<BinaryNode<EmployeeInfo>> newNodePtr);
    std::shared_ptr<BinaryNode<EmployeeInfo>> removeValue(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr, const int target, bool& isSuccessful);
    std::shared_ptr<BinaryNode<EmployeeInfo>> removeNode(std::shared_ptr<BinaryNode<EmployeeInfo>> nodeToDeletePtr);
    std::shared_ptr<BinaryNode<EmployeeInfo>> findNode(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr, const int target) const;
    void inorderHelper(void visit(EmployeeInfo&), std::shared_ptr<BinaryNode<EmployeeInfo>> treePtr) const;
    std::shared_ptr<BinaryNode<EmployeeInfo>> removeLeftmostNode(std::shared_ptr<BinaryNode<EmployeeInfo>> nodePtr, EmployeeInfo& inorderSuccessor);

public:
    BinarySearchTree();
    BinarySearchTree(const EmployeeInfo& rootItem);
    BinarySearchTree(const BinarySearchTree& tree);
    virtual ~BinarySearchTree();

    bool isEmpty() const;
    EmployeeInfo getRootData() const noexcept(false);
    void setRootData(const EmployeeInfo& newData);
    bool add(const EmployeeInfo& newEntry);
    bool remove(const int target);
    void clear();
    EmployeeInfo getEntry(const int anEntry) const noexcept(false);
    bool contains(const int anEntry) const;

    void inorderTraverse(void visit(EmployeeInfo&)) const;

    void displayEmployeeInfo(EmployeeInfo& employeeInfo);

};

#include "BinarySearchTree.cpp"
#endif