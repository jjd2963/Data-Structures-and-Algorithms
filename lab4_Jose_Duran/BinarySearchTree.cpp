#include "BinarySearchTree.h"

// Private Methods
template<class EmployeeInfo>
std::shared_ptr<BinaryNode<EmployeeInfo>> BinarySearchTree<EmployeeInfo>::placeNode(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr, std::shared_ptr<BinaryNode<EmployeeInfo>> newNodePtr) {
    if (subTreePtr == nullptr) {
        return newNodePtr;
    } else if (newNodePtr->getEmployee().getEmployeeID() < subTreePtr->getEmployee().getEmployeeID()) {
        auto tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    } else if (newNodePtr->getEmployee().getEmployeeID() > subTreePtr->getEmployee().getEmployeeID()) {
        auto tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    } else {
        subTreePtr->setEmployee(newNodePtr->getEmployee());
    }
    return subTreePtr;
}

template<class EmployeeInfo>
std::shared_ptr<BinaryNode<EmployeeInfo>> BinarySearchTree<EmployeeInfo>::removeValue(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr, const int target, bool& isSuccessful) {
    if (subTreePtr == nullptr) {
        isSuccessful = false;
        return subTreePtr;
    } else if (subTreePtr->getEmployee().getEmployeeID() == target) {
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
    } else if (target < subTreePtr->getEmployee().getEmployeeID()) {
        isSuccessful = false;
        auto tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    } else {
        isSuccessful = false;
        auto tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

template<class EmployeeInfo>
std::shared_ptr<BinaryNode<EmployeeInfo>> BinarySearchTree<EmployeeInfo>::removeLeftmostNode(std::shared_ptr<BinaryNode<EmployeeInfo>> nodePtr, EmployeeInfo& inorderSuccessor)
{
    if (nodePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = nodePtr->getEmployee();
        return removeNode(nodePtr);
    } else {
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
        return nodePtr;
    }
}

template<class EmployeeInfo>
std::shared_ptr<BinaryNode<EmployeeInfo>> BinarySearchTree<EmployeeInfo>::removeNode(std::shared_ptr<BinaryNode<EmployeeInfo>> nodeToDeletePtr) {
    if (nodeToDeletePtr->isLeaf()) {
        nodeToDeletePtr = nullptr;
    } else if (nodeToDeletePtr->getLeftChildPtr() == nullptr || nodeToDeletePtr->getRightChildPtr() == nullptr) {
        auto nodeToConnectPtr = (nodeToDeletePtr->getLeftChildPtr() != nullptr ? nodeToDeletePtr->getLeftChildPtr() : nodeToDeletePtr->getRightChildPtr());
        nodeToDeletePtr = nodeToConnectPtr;
    } else {
        EmployeeInfo inorderSuccessor;
        auto tempPtr = removeLeftmostNode(nodeToDeletePtr->getRightChildPtr(), inorderSuccessor);
        nodeToDeletePtr->setEmployee(tempPtr->getEmployee());
    }
    return nodeToDeletePtr;
}

template<class EmployeeInfo>
std::shared_ptr<BinaryNode<EmployeeInfo>> BinarySearchTree<EmployeeInfo>::findNode(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr, const int target) const {
    if (subTreePtr == nullptr) {
        return nullptr;
    } else if (subTreePtr->getEmployee().getEmployeeID() == target) {
        return subTreePtr;
    } else if (target < subTreePtr->getEmployee().getEmployeeID()) {
        return findNode(subTreePtr->getLeftChildPtr(), target);
    } else {
        return findNode(subTreePtr->getRightChildPtr(), target);
    }
}

template<class EmployeeInfo>
void BinarySearchTree<EmployeeInfo>::inorderHelper(void visit(EmployeeInfo&), std::shared_ptr<BinaryNode<EmployeeInfo>> treePtr) const {
    if (treePtr) {
        inorderHelper(visit, treePtr->getLeftChildPtr());
        EmployeeInfo theItem = treePtr->getEmployee();
        visit(theItem);
        inorderHelper(visit, treePtr->getRightChildPtr());
    }
}

// Default constructor
template<class EmployeeInfo>
BinarySearchTree<EmployeeInfo>::BinarySearchTree() : rootPtr(nullptr) {}

// Constructor with a root item
template<class EmployeeInfo>
BinarySearchTree<EmployeeInfo>::BinarySearchTree(const EmployeeInfo& rootItem) {
    rootPtr = std::make_shared<BinaryNode<EmployeeInfo>>(rootItem, nullptr, nullptr);
}

// Copy constructor
template<class EmployeeInfo>
BinarySearchTree<EmployeeInfo>::BinarySearchTree(const BinarySearchTree& tree) {
    rootPtr = copyTree(tree.rootPtr);
}

// Destructor
template<class EmployeeInfo>
BinarySearchTree<EmployeeInfo>::~BinarySearchTree() {
    clear();
}

// Check if the tree is empty
template<class EmployeeInfo>
bool BinarySearchTree<EmployeeInfo>::isEmpty() const {
    return (rootPtr == nullptr);
}

// Get the data of the root node
template<class EmployeeInfo>
EmployeeInfo BinarySearchTree<EmployeeInfo>::getRootData() const {
    if (isEmpty()) {
        throw PrecondViolatedExcept("getRootData() called with an empty tree.");
    }
    return rootPtr->getEmployee();
}

// Set the data of the root node
template<class EmployeeInfo>
void BinarySearchTree<EmployeeInfo>::setRootData(const EmployeeInfo& newData) {
    if (!isEmpty()) {
        rootPtr->setItem(newData);
    } else {
        rootPtr = std::make_shared<BinaryNode<EmployeeInfo>>(newData, nullptr, nullptr);
    }
}

// Add a new node to the tree
template<class EmployeeInfo>
bool BinarySearchTree<EmployeeInfo>::add(const EmployeeInfo& newEntry) {
    if (contains(newEntry.getEmployeeID())) {
        return false; // ID already exists in the tree, so don't add it again
    }
    auto newNodePtr = std::make_shared<BinaryNode<EmployeeInfo>>(newEntry);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}

// Remove a node from the tree
template<class EmployeeInfo>
bool BinarySearchTree<EmployeeInfo>::remove(const int target) {
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    return isSuccessful;
}

template<class EmployeeInfo>
void BinarySearchTree<EmployeeInfo>::clear()
{
    rootPtr = nullptr;
}

// Get the data of a specific node in the tree
template<class EmployeeInfo>
EmployeeInfo BinarySearchTree<EmployeeInfo>::getEntry(const int anEntry) const {
    auto nodePtr = findNode(rootPtr, anEntry);
    if (nodePtr == nullptr) {
        throw NotFoundException("getEntry() could not find the entry.");
    }
    return nodePtr->getEmployee();
}

// Check if a node with a specific value exists in the tree
template<class EmployeeInfo>
bool BinarySearchTree<EmployeeInfo>::contains(const int anEntry) const {
    auto nodePtr = findNode(rootPtr, anEntry);
    return (nodePtr != nullptr);
}

// Traverse the tree in-order and call the visit function for each node
template<class EmployeeInfo>
void BinarySearchTree<EmployeeInfo>::inorderTraverse(void visit(EmployeeInfo&)) const {
    inorderHelper(visit, rootPtr);
}

void displayEmployeeInfo(EmployeeInfo& employeeInfo) {
    std::cout << "ID: " << employeeInfo.getEmployeeID() << ", Name: " << employeeInfo.getEmployeeName() << std::endl;
}