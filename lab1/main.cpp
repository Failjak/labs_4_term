#include <iostream>
#include <vector>
#include <string>

#include "SmartPointer.cpp"
#include "Transaction.cpp"
#include "Library.cpp"

using namespace std;

int menu();
int confirm();

int main()
{
	Transaction<Library> library;
	library.beginTransactions();

	while(true)
	{
		switch (menu())
		{
		case 1:
		{
			library.beginTransactions();
			
			string location;
			cout << "Enter location to this library: ";
			cin >> location;

			library->setLocation(location);
			library.commit();
			break;
		}
		default:
		cout << "Wrnog choice" << endl;
			break;
		}
	}

	return 0;
}

int menu()
{
	int choice;

	cout << "1 - Add employee to library." << endl;
	cout << "2 - Change library location." << endl;
	cout << "3 - Get list of employees." << endl;
	cout << "4 - Get library location." << endl;
	cout << "0 - Exit" << endl;
	cout << "your choice: ";
	cin >> choice;

	return choice;
}

int confirm()
{
	int choice;

	cout << "1 - Confirm transaction." << endl;
	cout << "2 - Cancle transaction." << endl;
	cout << "your choice: ";

	cin >> choice;

	return choice;
}