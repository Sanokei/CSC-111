/*
Write a program that uses a structure to store the following data about a customer account:

     Customer name
     Customer address
     City
     State
     ZIP code
     Telephone
     Account balance
     Date of last payment

The program should use an array of at least 20 structures. It should let the user enter data into the array, change the contents of any element, and display all the data stored in the array. The program should have a menu-driven user interface.

Prompts And Output Labels. Your main menu should be the following:
     1. Enter new account information
     2. Change account information
     3. Display all account information
     4. Exit the program
The user is expected to enter 1 or 2 or 3 or 4.
The main menu is displayed at the start of the program and after the handling of choices 1, 2 and 3.

If 1 is entered for the main menu, the program prompts for each of the data listed above, in the order listed above, using the above data descriptions (e.g. "ZIP code") as prompts (followed in each case by a colon). After reading in and processing the data, the program prints
     You have entered information for customer number X
where X is the customer number: 0 for the first customer and increasing by 1 for each subsequent customer that is entered.

If 2 is entered for the main menu, the program prompts for the customer number:
     Customer number:
Upon entering a valid customer number the program displays all the data for the particular customer that has been saved:
     Customer name: ...
     Customer address: ...
     City: ...
     State: ...
     ZIP code: ...
     Telephone: ...
     Account balance: ...
     Date of last payment: ...

The program then skips one or two lines and prompts for a change, using the same prompts as in choice 1 above for all the data items associated with a customer.

If 3 is entered for the main menu, the program displays all the data for each customer that has been saved, using the display format in choice 2 above. After the display of each customer the program prompts "Press enter to continue..." and waits for the user to hit return.

If 4 is entered for the main menu, the program terminates.

Input Validation .When the data for a new account is entered, be sure the user enters data for all the fields. No negative account balances should be entered.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "name.cpp"
using namespace std;

int SIZE = 0;

struct Account
{
	string name;
	string address;
	string city;
	string state;
	string zip;
	string telephone;
	string balance;
	string lastPayment;
};

void enterData(Account[], int);
void displayData(Account[], int);
void changeData(Account[], int);

void menu(){
    cout << "1. Enter new account information" << endl;
    cout << "2. Change account information" << endl;
    cout << "3. Display all account information" << endl;
    cout << "4. Exit the program" << endl;
}

int main()
{
	Account account[99];
	int choice;
	bool loop = true;

	do
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			enterData(account, SIZE);
			break;
		case 2:
			changeData(account, SIZE);
			break;
		case 3:
			displayData(account, SIZE);
			break;
		case 4:
			loop = false;
			break;
		default:
			cout << "Invalid choice. Please enter again." << endl;
			break;
		}
	} while (loop);
    name();
	system("pause");
	return 0;
}

void enterData(Account account[], int size)
{
	int count = 0;
	bool loop = true;

	do
	{
		cout << "Enter the information for customer number " << count << ":" << endl;
		cout << "Name: ";
        cin.ignore();
		getline(cin, account[count].name);
		cout << "Address: ";
		getline(cin, account[count].address);
		cout << "City: ";
		getline(cin, account[count].city);
		cout << "State: ";
		getline(cin, account[count].state);
		cout << "ZIP code: ";
		getline(cin, account[count].zip);
		cout << "Telephone: ";
		getline(cin, account[count].telephone);
		cout << "Account balance: ";
		cin >> account[count].balance;
		cin.ignore();
		cout << "Date of last payment: ";
		getline(cin, account[count].lastPayment);
		count++;
		cout << "Do you want to enter more information? (Y/N): ";
        char input;
		cin >> input;
        loop = (tolower(input) == 'y');
		cin.ignore();
	} while (loop == true && count < size);
    SIZE += count;
}


void displayData(Account account[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Customer number: " << i << endl;
		cout << "Customer name: " << account[i].name << endl;
		cout << "Customer address: " << account[i].address << endl;
		cout << "City: " << account[i].city << endl;
		cout << "State: " << account[i].state << endl;
		cout << "ZIP code: " << account[i].zip << endl;
		cout << "Telephone: " << account[i].telephone << endl;
		cout << "Account balance: " << account[i].balance << endl;
		cout << "Date of last payment: " << account[i].lastPayment << endl;
		cout << "Press enter to continue..." << endl;
		cin.ignore();
		cin.get();
	}
    if(size == 0)
        cout << "No information entered." << endl;
}

void changeData(Account account[], int size)
{
	int choice;
	int count = 0;
	bool loop = true;

	do
	{
		cout << "Enter the customer number: ";
		cin >> choice;
		if (choice >= 0 && choice < size)
		{
			cout << "Customer number: " << choice << endl;
			cout << "Customer name: " << account[choice].name << endl;
			cout << "Customer address: " << account[choice].address << endl;
			cout << "City: " << account[choice].city << endl;
			cout << "State: " << account[choice].state << endl;
			cout << "ZIP code: " << account[choice].zip << endl;
			cout << "Telephone: " << account[choice].telephone << endl;
			cout << "Account balance: " << account[choice].balance << endl;
            cout << "Date of last payment: " << account[choice].lastPayment << endl;
            cout << "What do you want to change? (1) Name, (2) Address, (3) City, (4) State, (5) ZIP code, (6) Telephone, (7) Account balance, (8) Date of last payment, (9) All: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter the new name: ";
                cin.ignore();
                getline(cin, account[choice].name);
                break;
            case 2:

                cout << "Enter the new address: ";
                getline(cin, account[choice].address);
                break;
            case 3:
                cout << "Enter the new city: ";
                getline(cin, account[choice].city);
                break;
            case 4:
                cout << "Enter the new state: ";
                getline(cin, account[choice].state);
                break;
            case 5:
                cout << "Enter the new ZIP code: ";
                getline(cin, account[choice].zip);
                break;
            case 6:
                cout << "Enter the new telephone: ";
                getline(cin, account[choice].telephone);
                break;
            default:
                cout << "Nothing Changed"<< endl;
                break;
            }
            count++;
            cout << "Do you want to change more information? (Y/N): ";
            cin >> loop;
            cin.ignore();
        }
        else
        {
            cout << "Invalid customer number. Please enter again." << endl;
        }
    } while (loop == true && count < size);
}



