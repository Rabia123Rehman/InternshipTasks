#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string caseItems[] = {"A1", "A2"};
const string caseDescriptions[] = {"Compact", "Tower"};
const double casePrices[] = {75.00, 150.00};
const string ramItems[] = {"B1", "B2", "B3"};
const string ramDescriptions[] = {"8 GB", "16 GB", "32 GB"};
const double ramPrices[] = {79.99, 149.99, 299.99};
const string hddItems[] = {"C1", "C2", "C3"};
const string hddDescriptions[] = {"1 TB HDD", "2 TB HDD", "4 TB HDD"};
const double hddPrices[] = {49.99, 89.99, 129.99};
const string additionalCategories[] = {"D - Solid State Drive", "E - Second Hard Disk Drive", "F - Optical Drive", "G - Operating System"};
const string additionalItems[][2] = {
    {"D1", "240 GB SSD"},
    {"D2", "480 GB SSD"},
    {"E1", "1 TB HDD"},
    {"E2", "2 TB HDD"},
    {"E3", "4 TB HDD"},
    {"F1", "DVD/Blu-Ray Player"},
    {"F2", "DVD/Blu-Ray Re-writer"},
    {"G1", "Standard Version"},
    {"G2", "Professional Version"}
};

const double additionalPrices[] = {59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00};

void displayItems(const string items[], const string descriptions[], const double prices[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << items[i] << " - " << descriptions[i] << " ($" << prices[i] << ")" << endl;
    }
}

double getPriceByCode(const string code, const string items[], const double prices[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (code == items[i])
        {
            return prices[i];
        }
    }
    return 0.0;
}

int main()
{
    cout << "***************************************************************" << endl;
    cout << "*                 ___________________________________         *" << endl;
    cout << "*                |Welcome to the Online Computer Shop|        *" << endl;
    cout << "*                 -----------------------------------         *" << endl;
    cout << "***************************************************************" << endl;

    string EnterCase, EnterRam, EnterHDD;
    double totalPrice = 200.00;
    vector<string> additionalItemCodes;
    vector<double> additionalItemPrices;

    // Choose a case
    while (true)
    {
        cout << "                         |CASE SELECTION|                  " << endl;
        cout << "Select one case from the following options:" << endl;
        displayItems(caseItems, caseDescriptions, casePrices, 2);
        cout << "Enter the item code of your choice: ";
        cin >> EnterCase;

        double casePrice = getPriceByCode(EnterCase, caseItems, casePrices, 2);
        if (casePrice > 0)
        {
            totalPrice += casePrice;
            break;
        }
        cout << "Invalid case selection. Please try again." << endl;
        system("pause");
    }

    // Choose RAM
    while (true)
    {
        cout << "                         |RAM SELECTION|                  " << endl;
        cout << "Select one RAM from the following options:" << endl;
        displayItems(ramItems, ramDescriptions, ramPrices, 3);
        cout << "Enter the item code of your choice: ";
        cin >> EnterRam;

        double ramPrice = getPriceByCode(EnterRam, ramItems, ramPrices, 3);
        if (ramPrice > 0)
        {
            totalPrice += ramPrice;
            break;
        }
        cout << "Invalid RAM selection. Please try again." << endl;
        system("pause");
    }

    // Choose Main Hard Disk Drive
    while (true)
    {
        cout << "                         |HDD SELECTION|                  " << endl;
        cout << "Select one Main Hard Disk Drive from the following options:" << endl;
        displayItems(hddItems, hddDescriptions, hddPrices, 3);
        cout << "Enter the item code of your choice: ";
        cin >> EnterHDD;

        double hddPrice = getPriceByCode(EnterHDD, hddItems, hddPrices, 3);
        if (hddPrice > 0)
        {
            totalPrice += hddPrice;
            break;
        }
        cout << "Invalid Main Hard Disk Drive selection. Please try again." << endl;
        system("pause");
    }

    // Additional item selection
	//TASK 2 
    cout << "Do you want to purchase additional items? (Y/N): ";
string additionalChoice;
cin >> additionalChoice;
while (additionalChoice == "Y" || additionalChoice == "y")
{
    cout << "                         |ADDITIONAL ITEMS|                  " << endl;
    cout << "Select one or more additional items from the following options (or 'Q' to quit adding additional items):" << endl;
    // Display additional categories and items
    for (int i = 0; i < sizeof(additionalItems) / sizeof(additionalItems[0]); i++)
    {
        cout << additionalItems[i][0] << " - " << additionalCategories[i / 2] << " - " << additionalItems[i][1] << " ($" << additionalPrices[i] << ")" << endl;
    }

    string addItemCode;
    cin >> addItemCode;

    if (addItemCode == "Q" || addItemCode == "q")
    {
        break;
    }
    bool validAdditionalItem = false;
    double additionalPrice = 0.0;
    for (int i = 0; i < sizeof(additionalItems) / sizeof(additionalItems[0]); i++)
    {
        if (addItemCode == additionalItems[i][0])
        {
            validAdditionalItem = true;
            additionalPrice = additionalPrices[i];
            break;
        }
    }
    if (validAdditionalItem)
    {
        additionalItemCodes.push_back(addItemCode);
        additionalItemPrices.push_back(additionalPrice);
        totalPrice += additionalPrice;
        cout << "Added " << addItemCode << " to your order." << endl;
        cout << "Do you want to purchase more additional items? (Y/N): ";
        cin >> additionalChoice;
    }
    else
    {
        cout << "Invalid additional item selection. Please try again." << endl;
        system("pause");
    }
}

    // Output the chosen items and the total price
    cout<<"                         ____________ "<<endl;
    cout<< "                        |CHOSEN ITEMS|                  " << endl;
	cout<<"                         -------------"<<endl;
    cout<< "You have chosen the following items:" << endl;
    cout<< "Case: " << EnterCase << " - " << caseDescriptions[EnterCase == "A1" ? 0 : 1] << endl;
    cout<< "RAM: " << EnterRam << " - " << ramDescriptions[EnterRam == "B1" ? 0 : (EnterRam == "B2" ? 1 : 2)] << endl;
    cout<< "Main Hard Disk Drive: " << EnterHDD << " - " << hddDescriptions[EnterHDD == "C1" ? 0 : (EnterHDD == "C2" ? 1 : 2)] << endl;
   //TASK 2 
	if (!additionalItemCodes.empty())
{
    cout << "Additional Items: ";
    for (size_t i = 0; i < additionalItemCodes.size(); i++)
    {
        for (int j = 0; j < sizeof(additionalItems) / sizeof(additionalItems[0]); j++)
        {
            if (additionalItemCodes[i] == additionalItems[j][0])
            {
                cout << additionalCategories[j / 2] << " - " << additionalItems[j][1];
                break;
            }
        }
        if (i < additionalItemCodes.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}
cout << "Total Price: $" << totalPrice << endl;
system("pause");
return 0;
}
