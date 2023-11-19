// AICPWEEK3TASK1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Define the source matrix
int source_matrix[3][3] = {
    {550, 650, 750},
    {1800, 2250, 2550},
    {4200, 4600, 4800}
};

// Function to display the bill for slab 1 and slab 2
void displayBillSlab1AndSlab2() {
	cout << "                         _______________                   " << endl;
    cout << "                        |Bill for Slab 1|                  " << endl;
    cout << "                         ---------------                   " << endl;
    cout << "Bill for slab 1 is" << endl;
    for (int unit = 0; unit < 3; ++unit) 
	{
        cout << source_matrix[0][unit] << " ";
    }
    cout << endl;
	cout << "                         _______________                   " << endl;
    cout << "                        |Bill for Slab 2|                  " << endl;
    cout << "                         ---------------                   " << endl;
    cout << "Bill for slab 2 is" << endl;
    for (int unit = 0; unit < 3; ++unit) {
        cout << source_matrix[1][unit] << " ";
    }
    cout << endl;
}

// Function to display the bill for slab 3
void displayBillSlab3() {
	cout << "                         _______________                   " << endl;
    cout << "                        |Bill for Slab 3|                  " << endl;
    cout << "                         ---------------                   " << endl;
    cout << "Bill for slab 3 is" << endl;
    for (int unit = 0; unit < 3; ++unit) {
        cout << source_matrix[2][unit] << " ";
    }
    cout << endl;
}

// Main menu
void mainMenu(string studentId) 
{
    cout << "My student ID is " << studentId << endl;
    cout << "Enter your choice:" << endl;
    cout << "Press 1 to display the bill of slab 1 and slab 2." << endl;
    cout << "Press 2 to display the bill of slab 3." << endl;
    cout << "Press any other key to exit." << endl;
}

int main() {
	cout << "***************************************************************************************"<<endl;
    cout << "*                 __________________________________________________________           *"<<endl;
    cout << "*                |Welcome to calculation of Units of electricity consumption|          *"<<endl;
	cout << "*                 ----------------------------------------------------------           *"<< endl;
    cout << "****************************************************************************************" << endl;
    string studentId;
    cout << "Enter student ID: ";
    cin >> studentId;

    char choice;

    do {
        mainMenu(studentId);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                displayBillSlab1AndSlab2();
                break;
            case '2':
                displayBillSlab3();
                break;
            default:
	cout << "                    _____________________________                   " << endl;
    cout << "                   |Exiting the program. Goodbye!|                  " << endl;
    cout << "                    -----------------------------                   " << endl;
    break;
        }
    } while (choice == '1' || choice == '2');
	system("pause");
    return 0;
}
