#include <iostream>
#include <vector>
#include <memory>

#include "Pharmacy.hpp"
#include "Pharmacy.cpp"

using namespace std;


void exitFunc();
Pharmacy * createPharmacy();
int main_menu();
int order_menu();


int main()
{
    unique_ptr<Pharmacy> pharmacy(createPharmacy());
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

int main_menu()
{
    cout << "1 - See info about the pharmacy" << endl;
    cout << "2 - Make an order" << endl;
    cout << "0 - Выход" << endl;

    int choice;
    cin >> choice;

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