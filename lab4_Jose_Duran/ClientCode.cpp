// Program Status - Complete
// Program Creator - Jose Duran
// This program creates a binary search tree that stores employee id and name
// while allowing the user to enter a new employee, remove an existing employee, or display the tree.
#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

void showMenu();

int main() 
{
    // Create a binary tree object
    BinarySearchTree<EmployeeInfo> employeeTree;

    bool Quit = false; // Quit Menu defaulted to false
    char move = 'a'; // Menu input
    // Variable declarations
    int id;
    string name;

    // add EmployeeInfo objects with given information
    employeeTree.add(EmployeeInfo(6702, "James B W Bevis"));
    employeeTree.add(EmployeeInfo(1255, "Romney Wordsworth"));
    employeeTree.add(EmployeeInfo(1071, "Revis Jacara"));
    employeeTree.add(EmployeeInfo(2390, "Clegg Forbes"));
    employeeTree.add(EmployeeInfo(1558, "Kalin Tros"));
    employeeTree.add(EmployeeInfo(7406, "Archibald Beechcroft"));
    employeeTree.add(EmployeeInfo(7562, "Penthor Mul"));
    employeeTree.add(EmployeeInfo(3004, "Bartlet Finchley"));
    employeeTree.add(EmployeeInfo(4922, "Latham Bine"));
    employeeTree.add(EmployeeInfo(8483, "Jeff Myrtlebank"));

    while (!Quit) {
        // Asks the user to choose menu option
        showMenu();
        cin >> move;

        switch (move) {
            case '1':
            {
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee name: ";
                cin.ignore(); // ignore any remaining newline characters in the buffer
                getline(cin, name);

                EmployeeInfo newEntry(id, name);
                bool success = employeeTree.add(newEntry);

                if (success) { // Successful
                    cout << "Employee added successfully!\n";
                } // end if
                else { // Failed
                    cout << "Failed to add employee.\n";
                } // end else
                break;
            } // end case 1
            case '2':
            {
               cout << "Enter employee ID: ";
                cin >> id;

                // invoke remove function
                bool success = employeeTree.remove(id);

                if (success) { // Successful
                    cout << "Employee removed successfully!\n";
                } // end if
                else { // Failed
                    cout << "Failed to remove employee.\n";
                } // end else
                break;
            } // end case 2
            case '3':
            {
                cout << "Employees in order of ID number:" << endl;
                employeeTree.inorderTraverse(displayEmployeeInfo);
                break;
            } // end case 3
            case '4':
            {
                Quit = true;
				break;
            } // end case 4
        }
    }
    return 0;
}

void showMenu() {
	cout << "\nHi there! What would you like to do?\n";
		cout << "1 - Add a new employee\n";
		cout << "2 - Remove an employee\n";
		cout << "3 - Display the Tree\n";
		cout << "4 - Quit" << endl;
} // end showMenu