// Program Status - Complete
// This program uses client code to access the
// ArrayBag class through a Client Interface.

#include <iostream>
#include <string>
#include "ArrayBag.h"

void displayBag(ArrayBag<int>& bag);
void showMenu();

int main()
{
	// This is one way you can get values in the bag. 
	// You could also read the values from a file.
	// You pick - but you should load up the bag with values.
	ArrayBag<int> bag;

	// defined variables.
	bool Quit = false; // Quit Menu defaulted to false
	bool sorted = false; // Sorted defaulted to false
	char move = 'a'; // Menu input
	int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
		
	cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 20; i++)
	{
		bag.add(items[i]);
	}  // end for

	while(!Quit) {
		showMenu();
		cin >> move;
		
		switch (move) {
			case '1':
			{
				vector<int> vec = bag.toVector();
				for (size_t i = 0; i < vec.size(); i++) {
					cout << vec[i] << " ";
				}
				break;
			} // end case 1
			case '2':
			{
				int newValue;

				cout << "Enter new value: ";
				cin >> newValue;
				
				if(bag.add(newValue))
				{ 
					// Succesful
					cout << "New value added!" << endl; 
					sorted = false;
				}
				else { 
					// Failed
					if (bag.contains(newValue)){
						cout << "Cannot add repeating values." << endl;
					}
					else {
						cout << "No more room!" << endl;
					} // end if
				} // end if
				break;
			} // end case 2
			case '3':
			{
				int removeValue;
				cout << "Enter value to remove: ";
				cin >> removeValue;

				if (bag.remove(removeValue)) {
					// Successful
					cout << "Value has been removed!" << endl;
					sorted = false;
				} 
				else {
					// Failed
					cout << "Value was not removed." << endl;
				} // end if
				break;
			} // end case 3
			case '4':
			{
				bag.bubbleSort();
				cout << "Sort complete!" << endl;
				sorted = true;
				break;
			} // end case 4
			case '5':
			{
				int searchValue;
				if (sorted) {
					// Successful
					cout << "Value to search: ";
					cin >> searchValue;

					bag.binarySearchIterative(searchValue);
				}
				else {
					// Failed
					cout << "Sort before searching!" << endl;
				} // end if
				break;
			} // end case 5
			case '6':
			{
				int searchValue;
				if (sorted) {
					// Succesful
					cout << "Value to search: ";
					cin >> searchValue;

					bag.binarySearchRecursiveHelper(searchValue);
				}
				else {
					// Failed
					cout << "Sort before searching!" << endl;
				} // end if
				break;
			} // end case 6
			case '7':
			{
				Quit = true;
				break;
			} // end case 7
			default:
			{
				cout << "Bad input, Try again " << endl;
				break;
			} // end default
		} // end switch
	} // end while
   return 0;
}  // end main

void showMenu() {
	cout << "\nHi there! What would you like to do?\n";
		cout << "1 - Display the contents of the bag\n";
		cout << "2 - Add values to the bag\n";
		cout << "3 - Remove values from the bag\n";
		cout << "4 - Sort the bag\n";
		cout << "5 - Search for an item Iteratively\n";
		cout << "6 - Search for an item Recursively\n";
		cout << "7 - Quit" << endl;
} // end showMenu