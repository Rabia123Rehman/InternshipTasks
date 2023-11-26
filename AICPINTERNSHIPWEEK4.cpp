// AICPINTERNSHIPWEEK4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

class Hexagon {
private:
    double side;

public:
    Hexagon(int lastDigit) {
        side = lastDigit;
    }

    double calcArea() {
        return (3 * sqrt(3.0) * side * side) / 2.0;
    }

    double calcPeri() {
        return 6 * side;
    }

    double calcAngleSum() {
        return 6 * 120.0;
    }

    void display() 
	{   
		cout << "                             ________                   " << endl;
		cout << "                            |HEXAGON |                  " << endl;
		cout << "                             --------                   " << endl;
        cout << "Hexagon Area: " << calcArea() << endl;
        cout << "Hexagon Perimeter: " << calcPeri() << endl;
        cout << "Sum of Hexagon Angles: " << calcAngleSum() << endl;
		cout<<"----------------------------------------------------------------"<<endl;
		cout<<"****************************************************************"<<endl;
    }
};

class Square {
private:
    double side;

public:
    Square(int lastDigit) {
        side = lastDigit + 1;
    }

    double calcAreaSquare() {
        return side * side;
    }

    double calcPeriSquare() {
        return 4 * side;
    }

    void display() 
	{
		cout << "                              _______                  " << endl;
		cout << "                             |SQUARE |                  " << endl;
		cout << "                              -------                   " << endl;
        cout << "Square Area: " << calcAreaSquare() << endl;
        cout << "Square Perimeter: " << calcPeriSquare() << endl;
    }
};

int main() {
    int lastDigit; 
	char choice;
	do 
	{
	cout << "                         __________________                   " << endl;
    cout << "                        |HEXAGON AND SQUARE|                  " << endl;
    cout << "                         ------------------                   " << endl;
    cout << "Enter 1 to display area, perimeter and sum of all the angles of hexagon"<<endl;
	cout << "Enter 2 to display the area and perimeter of the square"<<endl;
	cout << "Press any other key to exit"<<endl;

    //cin.ignore();  // Clear input buffer
	cout<<"****************************************************************"<<endl;
	cout<<"Enter your choice:";
    cin >> choice;
    switch (choice)
	
	{
    case '1': {
    cout << "Enter the last digit of your CNIC: ";
    cin >> lastDigit;
	cout<<"----------------------------------------------------------------"<<endl;
    Hexagon hex(lastDigit);
    hex.display();
    break;
    }
    case '2': {
        cout << "Enter the last digit of your CNIC: ";
        cin >> lastDigit;
        Square square(lastDigit);
        square.display();
        break;
    }
    default:
        cout << "Exiting program." << endl;
    } 
}
	while (choice == '1' || choice == '2');
	system("pause");
    return 0;
}

