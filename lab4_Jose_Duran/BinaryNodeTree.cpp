#include "BinaryNodeTree.h"
#include <stdexcept>

template<class EmployeeInfo>
class BinaryNodeTree : public BinaryTreeInterface<EmployeeInfo>
{
private:
    std::shared_ptr<BinaryNode<EmployeeInfo>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    int getHeightHelper(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr) const
    {
        if (subTreePtr == nullptr)
            return 0;
        else
            return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                                getHeightHelper(subTreePtr->getRightChildPtr()));
    }

    int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr) const
    {
        if (subTreePtr == nullptr)
            return 0;
        else
            return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) +
                   getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }

    auto balancedAdd(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr,
                     std::shared_ptr<BinaryNode<EmployeeInfo>> newNodePtr)
    {
        if (subTreePtr == nullptr)
            return newNodePtr;
        else
        {
            auto leftPtr = subTreePtr->getLeftChildPtr();
            auto rightPtr = subTreePtr->getRightChildPtr();
            if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
            {
                rightPtr = balancedAdd(rightPtr, newNodePtr);
                subTreePtr->setRightChildPtr(rightPtr);
            }
            else
            {
                leftPtr = balancedAdd(leftPtr, newNodePtr);
                subTreePtr->setLeftChildPtr(leftPtr);
            }

            return subTreePtr;
        }
    }

    // Removes the target value from the tree.
    virtual auto removeValue(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr,
                             const EmployeeInfo target, bool& isSuccessful)
    {
        if (subTreePtr == nullptr)
        {
            isSuccessful = false;
            return subTreePtr;
        } // end if
        else if (subTreePtr->getItem() == target)
        {
            subTreePtr = moveValuesUpTree(subTreePtr);
            isSuccessful = true;
            return subTreePtr;
        } //end else if
        else if (subTreePtr->getItem() > target)
            // recursively call removeValue while passing leftchild
            subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful));
        else
            // recursively call removeValue while passing rightchild
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful));
        return subTreePtr;
    }

    auto moveValuesUpTree(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr) {
        // If the sub tree is a leaf, return nullptr to indicate that the leaf should be removed
        if (subTreePtr->isLeaf()) {
            return nullptr;
        }
        // Recursively move values up the tree for both the left and right subtrees
        subTreePtr->setLeftChildPtr(moveValuesUpTree(subTreePtr->getLeftChildPtr()));
        subTreePtr->setRightChildPtr(moveValuesUpTree(subTreePtr->getRightChildPtr()));
        // Update the value of the current node to be the sum of the values of its left and right children
        subTreePtr->setItem(subTreePtr->getLeftChildPtr()->getItem() + subTreePtr->getRightChildPtr()->getItem());
        // Return the updated sub tree pointer
        return subTreePtr;
    }

    auto findNode(std::shared_ptr<BinaryNode<EmployeeInfo>> treePtr, const EmployeeInfo& target, bool& isSuccessful) const {
        // If the tree pointer is null, the target value is not in the tree, return nullptr and isSuccessful set to false
        if (!treePtr) {
            isSuccessful = false;
            return nullptr;
        }
        // If the current node contains the target value, return a pointer to the current node and isSuccessful set to true
        if (treePtr->getItem() == target) {
            isSuccessful = true;
            return treePtr;
        }
        // Recursively search for the target value in the left and right subtrees
        if (treePtr->getItem() > target) {
            return findNode(treePtr->getLeftChildPtr(), target, isSuccessful);
        } else {
            return findNode(treePtr->getRightChildPtr(), target, isSuccessful);
        }
    }

    auto copyTree(const std::shared_ptr<BinaryNode<EmployeeInfo>> oldTreeRootPtr) const {
        // If the old tree root pointer is null, return null
        if (!oldTreeRootPtr) {
            return nullptr;
        }
        // Create a new node with the same value as the old tree root
        auto newTreeRootPtr = std::make_shared<BinaryNode<EmployeeInfo>>(oldTreeRootPtr->getItem());
        // Recursively copy the left and right subtrees of the old tree and set them as the left and right subtrees of the new tree root
        newTreeRootPtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
        newTreeRootPtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
        // Return a pointer to the new tree root
        return newTreeRootPtr;
    }

    void destroyTree(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr) {
        // If the sub tree pointer is not null, recursively delete its left and right subtrees and then delete the current node
        if (subTreePtr) {
            destroyTree(subTreePtr->getLeftChildPtr());
            destroyTree(subTreePtr->getRightChildPtr());
            subTreePtr.reset();
        }
    }

    void inorderTraverseHelper(std::shared_ptr<BinaryNode<EmployeeInfo>> subTreePtr, void visit(EmployeeInfo&)) const {
        if (subTreePtr != nullptr) {
            inorderTraverseHelper(subTreePtr->getLeftChildPtr(), visit);
            EmployeeInfo currentItem = subTreePtr->getItem();
            visit(currentItem);
            inorderTraverseHelper(subTreePtr->getRightChildPtr(), visit);
        }
    }

    BinaryNodeTree::BinaryNodeTree() : rootPtr(nullptr)
    {
    }

    BinaryNodeTree::BinaryNodeTree(const EmployeeInfo& rootItem)
    : rootPtr(std::make_shared<BinaryNode<EmployeeInfo>>(rootItem, nullptr, nullptr))
    {
    }

    BinaryNodeTree::BinaryNodeTree(const EmployeeInfo& rootItem,
                                const std::shared_ptr<BinaryNodeTree>& leftTreePtr,
                                const std::shared_ptr<BinaryNodeTree>& rightTreePtr)
    {
        rootPtr = std::make_shared<BinaryNode<EmployeeInfo>>(rootItem,
                                                            copyTree(leftTreePtr->rootPtr),
                                                            copyTree(rightTreePtr->rootPtr));
    }

    BinaryNodeTree::BinaryNodeTree(const std::shared_ptr<BinaryNodeTree>& tree)
    {
        rootPtr = copyTree(tree->rootPtr);
    }

    BinaryNodeTree::~BinaryNodeTree()
    {
        destroyTree(rootPtr);
    }

    // Check if the tree is empty
    bool BinaryNodeTree<EmployeeInfo>::isEmpty() const {
        return (rootPtr == nullptr);
    }

    // Get the root data of the tree
    EmployeeInfo BinaryNodeTree<EmployeeInfo>::getRootData() const throw(PrecondViolatedExcept) {
        if (isEmpty())
            throw PrecondViolatedExcept("getRootData() called with empty tree.");
        return rootPtr->getItem();
    }

    // Set the root data of the tree
    void BinaryNodeTree<EmployeeInfo>::setRootData(const EmployeeInfo& newData) {
        if (isEmpty())
            rootPtr = std::make_shared<BinaryNode<EmployeeInfo>>(newData);
        else
            rootPtr->setItem(newData);
    }

    // Add a new item to the tree
    bool BinaryNodeTree<EmployeeInfo>::add(const EmployeeInfo& newData) {
        auto newNodePtr = std::make_shared<BinaryNode<EmployeeInfo>>(newData);
        rootPtr = placeNode(rootPtr, newNodePtr);
        return true;
    }

    // Remove an item from the tree
    bool BinaryNodeTree<EmployeeInfo>::remove(const EmployeeInfo& data) {
        bool isSuccessful = false;
        rootPtr = removeValue(rootPtr, data, isSuccessful);
        return isSuccessful;
    }

    // Get an entry from the tree
    EmployeeInfo BinaryNodeTree<EmployeeInfo>::getEntry(const EmployeeInfo& anEntry) const throw(NotFoundException) {
        bool isSuccessful = false;
        auto binaryNodePtr = findNode(rootPtr, anEntry, isSuccessful);
        if (isSuccessful)
            return binaryNodePtr->getItem();
        else
            throw NotFoundException("Entry not found in tree.");
    }

    // Check if an entry exists in the tree
    bool BinaryNodeTree<EmployeeInfo>::contains(const EmployeeInfo& anEntry) const {
        bool isSuccessful = false;
        findNode(rootPtr, anEntry, isSuccessful);
        return isSuccessful;
    }  

    void BinaryNodeTree<EmployeeInfo>::inorderTraverse(void visit(EmployeeInfo&)) const
    {
        inorderTraverseHelper(rootPtr, visit);
    }

    BinaryNodeTree<EmployeeInfo>& BinaryNodeTree<EmployeeInfo>::operator=(const BinaryNodeTree& rightHandSide)
    {
        if (this != &rightHandSide) // avoid self-assignment
        {
            destroyTree(rootPtr);
            rootPtr = copyTree(rightHandSide.rootPtr);
        }
        return *this;
    }