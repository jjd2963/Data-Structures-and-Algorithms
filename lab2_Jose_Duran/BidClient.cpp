// Program Status - Complete
// This program determines the winning bid in a text file
// using a linked list stack. 

#include <iostream>
#include <string>
#include <fstream>
#include "LinkedStack.h"

using namespace std;

int main() {
    // defined objects.
    fstream myFile;
    LinkedStack<int> stack;

    // defined variables.
    string filename, item;
    int bid;

    // asks user to enter a file name
    cout << "Enter a file name: ";
    cin >> filename;
    myFile.open(filename);

    if (!myFile) { // Failed
        cout << "No such file.";
    } // end if
    else { // Successful
        getline(myFile, item); // Read first line which contains item.

        while(!myFile.eof()) // end of file check.
        {
            myFile >> bid; // read line and assign to bid.
            
            // add bid to the top of the stack if stack is empty or bid is greater than top of stack.
            if(stack.isEmpty() || stack.peek() < bid){
                stack.push(bid); 
            } // end if
        } // end while

        myFile.close();

        // displays winnning bid.
        if(!stack.isEmpty()){
            cout << "The winning bid for " << item << " is ";
            cout << stack.peek() << endl;
        } // end if
        else{
            cout << "No bid was made.";
        } // end else
    } // end else
    return 0;
}