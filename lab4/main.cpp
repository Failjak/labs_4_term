#include <iostream>
#include <vector>
#include <memory>

#include "common.cpp"

using namespace std;



// TODO 
// 1) open(), is_open(), close()
// 2) eof(), fail(), 
// 3) overload << and >> 
// 4) seekg(), seekp(), tellg()



void exitFunc();
Pharmacy * createPharmacy();


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

        case 5:
        {
            file_handler(pharmacy, "text.txt");
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