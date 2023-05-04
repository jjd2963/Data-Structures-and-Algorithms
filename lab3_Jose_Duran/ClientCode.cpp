// Program Status - Complete
// Program Creator - Jose Duran
// This program creates a linked list of nodes with 2 strings and 
// alphabetically sorts the data as it is added into the list based on category.
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedCategories.h"

using namespace std;

int main()
{
    fstream myFile; // delcare file variable
    LinkedList list; // declare Linkedlist object list
    string filename, category, line; // declare string variables

    // asks user to enter a file name
    cout << "Enter a file name: ";
    cin >> filename;
    myFile.open(filename);
    
    if (!myFile) { // Failed
        cout << "No such file.";
    } // end if
    else { // Successful
        cout << "File has opened succesfully!\n";
        while(getline(myFile, category)) // end of file check.
        {
            getline(myFile, line); //a ssign second line to line
            list.add(category, line); // call to add node
        } // end while

        vector<string> vec = list.toVector(); // declare vector object vec

        cout << "\nBoring: " << endl; // Display Boring category
        for (int i = 0; i < vec.size(); i += 2) 
        {
            if (vec[i] == "Boring") // Display only strings in Boring category
            {
                cout << "\t" << vec[i+1] << endl;
            } // end if
        } // end for

        cout << "\nInteresting: " << endl; // Display Interesting category
        for (int i = 0; i < vec.size(); i += 2) 
        {
            if (vec[i] == "Interesting") // Display only strings in Interesting category
            {
                cout << "\t" << vec[i+1] << endl;
            } // end if
        } // end for

        cout << "\nName: " << endl; // Display Name category
        for (int i = 0; i < vec.size(); i += 2) 
        {
            if (vec[i] == "Name") // Display only strings in Name category
            {
                cout << "\t" << vec[i+1] << endl;
            } // end if
        } // end for
        
        cout << "\nNonsense: " << endl; // Display Nonsense category
        for (int i = 0; i < vec.size(); i += 2) 
        {
            if (vec[i] == "Nonsense") // Display only strings in Nonsense category
            {
                cout << "\t" << vec[i+1] << endl;
            } // end if
        } // end for
    } // end else

    return 0;
} // end main