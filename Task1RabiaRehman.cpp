// Task1RabiaRehman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//Task1 part(a)
const string caseItems[] = {"A1", "A2"};
const string caseDescriptions[] = {"Compact", "Tower"};
const double casePrices[] = {75.00, 150.00};
const string ramItems[] = {"B1", "B2", "B3"};
const string ramDescriptions[] = {"8 GB", "16 GB", "32 GB"};
const double ramPrices[] = {79.99, 149.99, 299.99};
const string hddItems[] = {"C1", "C2", "C3"};
const string hddDescriptions[] = {"1 TB HDD", "2 TB HDD", "4 TB HDD"};
const double hddPrices[] = {49.99, 89.99, 129.99};

void displayItems(const string items[], const string descriptions[], const double prices[], int size) 
{
    for (int i = 0; i < size; i++)
	{
        cout << items[i] << " - " << descriptions[i] << " ($" << prices[i] << ")" << endl;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"***************************************************************"<<endl;
	cout<<"*                 ___________________________________         *"<<endl;
	cout<<"*                |Welcome to the Online Computer Shop|        *"<<endl;
	cout<<"*                 -----------------------------------         *"<<endl;
	cout<<"***************************************************************"<<endl;
	string EnterCase, EnterRam, EnterHDD;
	double totalPrice = 200.00;
    // Task1 part(b) choose one 
	
	while (true)
	{
	cout<<"                         |CASE SELECTION|                  "<<endl;
    cout << "Select one case from the following options:" << endl;
    displayItems(caseItems, caseDescriptions, casePrices, 2);
    cout << "Enter the item code of your choice: ";
    cin >> EnterCase;

    bool validCase = false;
    for (int i = 0; i < 2; i++) 
	{
        if (EnterCase == caseItems[i]) {
            validCase = true;
            totalPrice += casePrices[i];
            break;
        }
    }
    if (validCase) 
	{
    break;
    }
	 cout << "Invalid case selection. Please try again." << endl;
	 system("pause");
	}

	while (true)
	{
	cout<<"                         |RAM SELECTION|                  "<<endl;
    cout << "Select one RAM from the following options:" << endl;
    displayItems(ramItems, ramDescriptions, ramPrices, 3);
    cout << "Enter the item code of your choice: ";
    cin >> EnterRam;

    bool validRam = false;
    for (int i = 0; i < 3; i++) {
        if (EnterRam == ramItems[i]) {
            validRam = true;
            totalPrice += ramPrices[i];
            break;
        }
    }

    if (validRam) {
       break;
    }
	 cout << "Invalid RAM selection. Please try again." << endl;
	 system("pause");
	}

	while(true)
	{
	cout<<"                         |HDD SELECTION|                  "<<endl;
    cout << "Select one Main Hard Disk Drive from the following options:" << endl;
    displayItems(hddItems, hddDescriptions, hddPrices, 3);
    cout << "Enter the item code of your choice: ";
    cin >> EnterHDD;
    bool validHDD = false;
    for (int i = 0; i < 3; i++) {
        if (EnterHDD == hddItems[i]) {
            validHDD = true;
            totalPrice += hddPrices[i];
            break;
        }
    }

    if (validHDD)
	{
     break;
    }
	 cout << "Invalid Main Hard Disk Drive selection. Please try again." << endl;
	 system("pause");
	}

    //Task1 part(d) Output the chosen items and the total price
	cout<<"                         |CHOOSEN ITEMS|                  "<<endl;
    cout << "You have chosen the following items:" << endl;
    cout << "Case: " << EnterCase << " - " << caseDescriptions[EnterCase  == "A1" ? 0 : 1] << endl;
    cout << "RAM: " << EnterRam << " - " << ramDescriptions[EnterRam  == "B1" ? 0 : (EnterRam == "B2" ? 1 : 2)] << endl;
    cout << "Main Hard Disk Drive: " <<EnterHDD << " - " << hddDescriptions[EnterHDD == "C1" ? 0 : (EnterHDD == "C2" ? 1 : 2)] << endl;
	cout<<"                         |TOTAL PRICE|                  "<<endl;
    cout << "Total Price: $" << totalPrice << endl;

	// Task2 part(a)  Additional item selection
        cout << "Do you want to purchase additional items? (Y/N): ";
        string additionalChoice;
        cin >> additionalChoice;

        if (additionalChoice == "Y" || additionalChoice == "y")
		{
            cout << "                         |ADDITIONAL ITEMS|                  " << endl;
			//CASE
	while (true)
	{
            cout << "Select one or more additional items from the following options:" << endl;
            displayItems(caseItems, caseDescriptions, casePrices, 2); 
            cout << "Enter the item code of your choice (or 'Q' to quit adding additional items): ";

            string addItemCode;
            cin >> addItemCode;
            for (int i = 0; i < 2; i++) 
			{
                if (addItemCode == caseItems[i])
				{
                    totalPrice += casePrices[i];
                    cout << "Added " << caseDescriptions[i] << " to your order." << endl;
                    break;
                }
            }
			if (addItemCode == "Q" || addItemCode == "q") 
			{
                break; 
            }
			else 
		    {
            break; 
            }
			
    bool validCase = false;
    for (int i = 0; i < 2; i++) 
	{
        if (EnterCase == caseItems[i]) {
            validCase = true;
            totalPrice += casePrices[i];
            break;
        }
    }
	if (validCase) 
	{
    break;
    }

	 cout << "Invalid case selection. Please try again." << endl;
	 system("pause");
	}
			//RAM
			cout<<"                         |RAM SELECTION|                  "<<endl;
			cout << "Select one RAM from the following options:" << endl;
			displayItems(ramItems, ramDescriptions, ramPrices, 3);
			cout << "Enter the item code of your choice (or 'Q' to quit adding additional items): ";
			string addItemRam;
            cin >> addItemRam;
			for (int i = 0; i < 3; i++)
			 {
			if (EnterRam == ramItems[i]) 
			{
				totalPrice += ramPrices[i];
				cout << "Added " << ramDescriptions[i] << " to your order." << endl;
				break;
            }
            }

           
        
    }
	system("pause");
	return 0;
}

