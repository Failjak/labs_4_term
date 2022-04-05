#pragma once

#include <algorithm>
#include <vector>
#include <iostream>

#include "Pharmacy.hpp"
#include "Pharmacy.cpp"
#include "menu.hpp"
#include "file_handler.hpp"

using namespace std;

void put_pharm_to_file(string, Pharmacy *);
void sort_hendler(Pharmacy *);
void search_hendler(Pharmacy *);
void search_hendler_file(string file_name, Pharmacy * pharmacy);


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
        sort_hendler(pharmacy);
    }

    case 3: // SEARCH
    {
        search_hendler(pharmacy);
    }

    case 0:
        return;
    
    default:
        cout << "Wrong choice" << endl;
        return;
    }
}


void file_handler(Pharmacy * pharmacy, string file_name)
{
    bool flag = true;
    while(flag)
    {
        switch (file_menu())
        {

        case 1: // append data to file
        {
            put_pharm_to_file(file_name, pharmacy);
            break;
        }

        case 2: // delete data from file
        {
            int i = 0;
            auto medicaments = pharmacy->getMedicaments();

            cout << "Choose which medicaments to remove:\n";

            for (auto med : medicaments)
                cout << ++i << ") ", med.printInfo();

            int choice;
            cin >> choice;

            medicaments.erase(next(medicaments.begin(), choice-1));
            pharmacy->setMedicaments(medicaments);

            clear_file(file_name);
            put_pharm_to_file(file_name, pharmacy);

            break;
        }

        case 3: // edit info in file
        {   
            edit_pharmacy(pharmacy);
            
            clear_file(file_name);
            put_pharm_to_file(file_name, pharmacy);

            break;
        }

        case 4: // look at the file
        {
            vector<string> data = get_from_file(file_name);   

            for (auto d : data)
            {
                cout << d << endl;
            }
            break;
        }

        case 5: // search at the file
        {
            search_hendler_file(file_name, pharmacy);
            break;
        }


        case 6:
        {
            clear_file(file_name);
            break;
        }

        case 0:
            flag = false;
            break;
        
        default:
            break;
        }
    }
}


void put_pharm_to_file(string file_name, Pharmacy * pharmacy)
{
    vector<string> med_data;
    vector<string> pharm_data;

    put_to_file(file_name, {"Pharmacy:", pharmacy->getInfo()});

    med_data.push_back("Medicaments:");
    for (auto med : pharmacy->getMedicaments())
        med_data.push_back(med.getInfo());
    put_to_file(file_name, med_data);

    pharm_data.push_back("Pharmacists:");
    for (auto ph : pharmacy->getPharmacists())
        pharm_data.push_back(ph.getInfo());
    put_to_file(file_name, pharm_data);
}


void sort_hendler(Pharmacy * pharmacy)
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

void search_hendler(Pharmacy * pharmacy)
{
    switch (search_menu())
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

void search_hendler_file(string file_name, Pharmacy * pharmacy)
{
    search_hendler(pharmacy);
    return;
}