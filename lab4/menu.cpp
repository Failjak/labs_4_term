#include <iostream>

using namespace std;


int main_menu()
{   


    cout.setf(ios::right);
    cout.width(20);

    cout << "MAIN MENU" << endl;
    cout.unsetf(ios::right);

    cout 
        << "1 - See info about the pharmacy\n"
        << "2 - Make an order\n"
        << "3 - Get list of the orders\n"
        << "4 - Edit info about the order\n"
        << "5 - Work with file\n"
        << "0 - Выход\n" 
        << endl;
    
    int choice;

    while (1) {

    cin >> choice;

    if (cin.good()) {
        break;
    }
        cin.clear();
        cout << "Wrong choice" << endl;
        cin.ignore(10, '\n');
    }

    return choice;
}


int search_menu()
{
    cout << "Search in ..." << endl;

    cout << "1 - Medicaments" << endl;
    cout << "2 - Pharmacists" << endl;

    int choice;
    while (1) {
    cin >> choice;

    if (cin.good()) {
        break;
    }
        cin.clear();
        cout << "Wrong choice" << endl;
        cin.ignore(10, '\n');
    }

    return choice;
}

int sort_menu()
{
    cout << "Sort by ..." << endl;

    cout << "1 - Medicaments" << endl;
    cout << "2 - Pharmacists" << endl;

    int choice;
    while (1) {
    cin >> choice;

    if (cin.good()) {
        break;
    }
        cin.clear();
        cout << "Wrong choice" << endl;
        cin.ignore(10, '\n');
    }

    return choice;
}


int file_menu()
{
    cout.setf(ios::right);
    cout.width(20);

    cout << " File Menu" << endl;
    cout.unsetf(ios::right);

    cout 
        << "1 - Append to file\n"
        << "2 - Delete from file\n"
        << "3 - Edit info in a file\n"
        << "4 - Look at the data\n"
        << "5 - Data search"
        << endl;

    int choice;
    while (1) {
    cin >> choice;

    if (cin.good()) {
        break;
    }
        cin.clear();
        cout << "Wrong choice" << endl;
        cin.ignore(10, '\n');
    }

    return choice;
}

int choice_edit_field()
{
    cout << "Select the filed to edit." << endl;

    cout << "1 - City" << endl;
    cout << "2 - Street" << endl;
    cout << "3 - Building" << endl;

    int choice;
    while (1) {
    cin >> choice;

    if (cin.good()) {
        break;
    }
        cin.clear();
        cout << "Wrong choice" << endl;
        cin.ignore(10, '\n');
    }

    return choice;
}