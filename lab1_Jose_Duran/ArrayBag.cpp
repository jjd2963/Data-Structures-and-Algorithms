// Program Status - Complete
// This program provides the implementation of ArrayBag functions.

#include "ArrayBag.h"
#include <iostream>
#include <cstddef>

using namespace std;

#define ARRAY_SZ 20 // Default array size

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
void ArrayBag<ItemType>::bubbleSort()
{
	int i, j;
   int arrSize = sizeof(items) / sizeof(items[0]); // Find current array size
   for (i = 0; i < arrSize - 1; i++) {
      for (j = 0; j < arrSize - i - 1; j++) {
         if (items[j] > items[j + 1])
         {
            swap(items[j], items[j + 1]);
         } // end if
      } // end for
   } // end for
} // end bubbleSort

template<class ItemType>
void ArrayBag<ItemType>::binarySearchIterative(ItemType target)
{
   int start = 0;
   int end = itemCount - 1;
   int mid;

   while (end - start > 1) {
      mid = (start + end) / 2;
      if (items[mid] < target) {
         start = mid + 1;
      } 
      else {
         end = mid;
      } // end if
   } // end while

   if (items[end] == target) {
      cout << "Target Found" << endl;
   } else if (items[start] == target) {
      cout << "Target Found" << endl;
   } else {
      cout << "Target Not Found" << endl;
   } // end if
}

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursiveHelper(ItemType target)
{
   return binarySearchRecursive(target, 0, ARRAY_SZ - 1);
} // end binarySearchRecursiveHelper

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursive(ItemType target, int start, int end)
{
   if (start == end && items[start] != target) {
      cout << "Value not found" << endl;
      return false;
   } // end if

   int middle = (start + end) / 2;

   if (items[middle] == target) {
      cout << "Value found" << endl;
      return true;
   } else if (items[middle] < target) {
      return binarySearchRecursive(target, middle + 1, end);
   } else {
      return binarySearchRecursive(target, start, middle - 1);
   }
} // end binarySearchRecursive


template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

