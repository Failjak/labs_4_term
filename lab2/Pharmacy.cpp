#include <iostream>

#include "Pharmacy.hpp"

using namespace std;


Build::Build(vector<string> address)
{   
    if (address.size() != 3)
        throw "Wrong address format (need 3 arguments)";
    city = address.at(0);
    street = address.at(1);
    building = address.at(2);
}

void Build::printAddres()
{
    cout << "City: " << getCity() << ", " << "Street: " << getStreet() << ", "  << "Building: " << getBuild() << "." << endl;
}

string Build::getAddress()
{
    string res = getCity() + ", " +  getStreet() + ", " + getBuild();
    return res;
}


void Pharmacist::printInfo()
{
    cout << getFullName() << endl;
}

Medicament::Medicament(string title, string manual, float price) : title(title), manual(manual)
{
    try {
        if (price < 0) {
            throw (price);
        }
        this->price = price;
    } catch (float myNum) {
        cout << "Price denied - price must be greater than 0" << endl;
        cout << title <<", price set to NULL" << endl;
        price = 0;
    }
}

// Medicament::Medicament(const Medicament & obj)
// {
//     title = obj.title;
//     manual = obj.manual;
//     price = obj.price;
// }

void Medicament::printInfo()
{
    cout << getTitle() << ", price = " << getPrice() << endl;
}


void Pharmacy::printInfo()
{
    cout << "Pharmace address: " << getAddress() << "\n";

    cout << "\nPharmacists:" << endl;
    for (auto phar : pharmacists)
    {
        cout << "   Pharmacist: ", phar.printInfo();
    }

    cout << "\nMedicaments:" << endl;
    for (auto med : medicaments)
    {
        cout << "   Medicament: ", med.printInfo();
    }
}

Order * Pharmacy::createOrder(User * user)
{   
    Order * order = new Order;

    cout << "Choice nessesary medicament (0 - exit)" << endl;
    int ind = 0;
    cout << "\nMedicaments:" << endl;
    for (auto med : medicaments)
    {
        cout << "   " << ++ind << "): ", med.printInfo();
    }

    int choice;
    cin >> choice;

    try{
        order->addMedicament(&medicaments.at(choice - 1));
        order->setUser(user);
    } catch(out_of_range) {
        cout << "!!! EXC !!!\nout_of_range exception, nothing to add" << endl;
        return new Order();
    }

    return order;
}

Pharmacist * Pharmacy::choicePharm()
{
    int ind = 0;

    cout << "\nPharmacists:" << endl;
    for (auto phar : pharmacists)
    {   
        cout << "   " << ++ind << "): ", phar.printInfo();
    }

    int choice;
    cout << "Your choice: ";
    cin >> choice;
    
    try{
        return &pharmacists.at(choice - 1);
    } catch(out_of_range) {
        cout << "!!! EXC !!!\nout_of_range exception, returned last pharmacist" << endl;
        return &pharmacists.at(ind - 1);
    }
}


Pharmacist::Pharmacist(string surname, string name, float salary) : People(surname, name)
{
    try {
        if (salary < 0) {
            throw NegativNum();
        }
    } catch (NegativNum) {
        cout << "Salary denied - salary must be greater than 0" << endl;
        cout << surname <<", salary set to NULL" << endl;
    }
    salary = 0;
}

void Order::printInfo()
{
    float price = 0;
    
    cout << "ORDER" << endl;

    cout << "Medicaments in order:" << endl;
    for (auto med : medicaments)
    {
        cout << "   ", med->printInfo();
        price += med->getPrice();

    }

    try {
        if (user->getBalance() < price) 
            throw InsufficientFunds();
        paid();
    } catch(InsufficientFunds) {
        cout << user->getFullName() << ", there are not enough funds in your account" << endl;
    }

    if (status == true)
        cout << "Product is ordered" << endl;
    else{
        cout << "Product not ordered" << endl;
    }
}