#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "Pharmacy.hpp"
#include "Pharmacy.cpp"

using namespace std;


void exitFunc();
Pharmacy * createPharmacy();

int main_menu();
int order_menu();
int search_menu();
int sort_menu();
int choice_edit_field();

void get_pharmacy_list(Pharmacy *);
void edit_pharmacy(Pharmacy *);


int main()
{
    Pharmacy * pharmacy = createPharmacy();
    User user("Batk", "Semen", 12);

    bool flag = true;
    while(flag)
    {
        switch (main_menu())
        {
        case 1:
            pharmacy->printInfo();
            break;
        
        case 2:
        {
            system("clear");
            Pharmacist * pharm = pharmacy->choicePharm();
            pharm->printInfo();
            Order * order = pharmacy->createOrder(&user);
            order->printInfo();
            break;
        }
        
        case 3:
        {
            get_pharmacy_list(pharmacy);
            break;
        }

        case 4:
        {
             edit_pharmacy(pharmacy);
             break;
        }

        case 0:
            cout << "Exit" << endl;
            flag = false;
            break;

        default:
            cout << "Wrong choice" << endl;
            break;
        }
    }

    return 0;
}


void edit_pharmacy(Pharmacy * pharmacy)
{
    switch (choice_edit_field())
    {

    case 1:
    {
        string new_value;
        cout << "Enter a new value for the City: ";
        cin >> new_value;

        pharmacy->setCity(new_value);
        break;
    }

    case 2:
    {
        string new_value;
        cout << "Enter a new value for the Street: ";
        cin >> new_value;

        pharmacy->setStreet(new_value);
        break;
    }

    case 3:
    {
        string new_value;
        cout << "Enter a new value for the Building: ";
        cin >> new_value;

        pharmacy->setBuild(new_value);
        break;
    }

    case 0:
        break;
    
    default:
        cout << "Wrond chocie" << endl;
        break;
    }
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

/// COMPARATORS
bool compareMedicaments(Medicament m1, Medicament m2)
{
    return (m1.getTitle() < m2.getTitle());
}

bool comparePharmacists(Pharmacist p1, Pharmacist p2)
{   
    return (p1.getSurname() < p2.getSurname());
}
/// COMPARATORS


void get_pharmacy_list(Pharmacy * pharmacy) 
{
    cout 
        << "1 - just List\n"
        << "2 - Sort\n"
        << "3 - Search\n" 
        << "0 - Exit\n"
        << endl;
    
    int choice;
    while (1) 
    {
        cin >> choice;

        if (cin.good()) {
           break;
        }
            cin.clear();
            cout << "Wrong choice" << endl;
            cin.ignore(10, '\n');
    }

    switch (choice)
    {

    case 1:
    {   
        pharmacy->printInfo();
        break;
    }

    
    case 2: // SORT
    {
        switch (sort_menu())
        {
    
        case 1: // medicaments
        {
            vector<Medicament> meds = pharmacy->getMedicaments();

            sort(meds.begin(), meds.end(), compareMedicaments);

            cout << "After sorting" << endl;
            int i = 0;
            for (auto x : meds)
                cout << ++i << ")", x.printInfo();
            
            break;
        }    

        case 2: // pharmacists
        {
            vector<Pharmacist> pharms = pharmacy->getPharmacists();

            sort(pharms.begin(), pharms.end(), comparePharmacists);

            cout << "After sorting" << endl;
            int i = 0;
            for (auto x : pharms)
                cout << ++i << ")" << x.getFullName() << endl;
            
            break;
        }   

        case 0:
            break;
        
        default:
            cout << "Wrong choice (in sort)" << endl;
            return;
        }
    }

    case 3: // SEARCH
    {
        int search_choice = search_menu();
        switch (search_choice)
        {
        
        case 1: // medicaments
        {   
            string title;
            cout << "Enter title to search in Medicaments: ";
            cin >> title;

            for (auto x : pharmacy->getMedicaments())
                if (x.getTitle() == title)
                {
                    cout << "Found equal value:" << endl;
                    x.printInfo();
                }

            break;
        }    

        case 2: // pharmacists
        {
            string surname;
            cout << "Enter surname to search in Pharmacists: ";
            cin >> surname;

            for (auto x : pharmacy->getPharmacists())
                if (x.getSurname() == surname)
                {
                    cout << "Found equal value:" << endl;
                    x.printInfo();
                }

            break;
        } 

        case 0:
            break;

        default:
            cout << "Wrong choice" << endl;
            break;
        }
    }

    case 0:
        return;
    
    default:
        cout << "Wrong choice" << endl;
        return;
    }
}


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

Pharmacy * createPharmacy()
{   
    vector<Pharmacist> pharms = {
        Pharmacist("Gushtyn", "Nikita", -500),
        Pharmacist("Ageev", "Alex", 700)
    };

    Medicament * medicments;

    try {
        while (true) {
            medicments = new Medicament[100000000000000];
        }
    } catch (bad_alloc exept) {
        cout << "Возникло исключение " << exept.what() << endl;
    }

    vector<Medicament> medicaments = {
        Medicament("Xarelto", "At the risk of blood clots in the vessels", 20.0), 
        Medicament("Ibuprofen", "For pain, fever, rheumatism, colds", 12.4),
        Medicament("Detralex", "With varicose veins", 10.3),
        Medicament("Mexidol", "With strokes, neuroses, alcoholism", 7.5),
        Medicament("Miramistin", "When it is necessary to disinfect the skin or mucous membranes", -2.5),
    };

    Pharmacy * pharm(new Pharmacy(pharms, {"Minsk", "Pervomaiskaya", "35/2"}, medicaments));

    return pharm;
};

void exitFunc() {
    cout << "Функция завершения" << endl;
    exit(-1);
}