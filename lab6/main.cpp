#include <iostream>

#include "logistics.cpp"

using namespace std;

int main_menu();

int main()
{   
    LogisticsCompany * log = new LogisticsCompany();

    bool flag = true;
    while(flag)
    {
        switch (main_menu())
        {
        case 1:
        {
            string order;

            cout << "Enter new order ";
            cin >>  order;

            log->addOrder(order);
            break;
        }

        case 2:
        {
            log->printOrders();
            break;
        }

        case 3:
        {   
            int index;
            string new_order;

            cout << "Enter index: ";
            cin >> index;
            cout << "Enter new order: ";
            cin >> new_order;

            log->changeOrder(index, new_order);

            break;
        }

        case 4:
        {
            string transport;
            cout << "Enter trasport: ";
            cin >> transport;

            log->addTransport(transport);
            break;
        }
        
        case 5:
        {   
            log->printTransports();
            break;
        }
        
        case 6:
        {
            int index;
            string new_tr;

            cout << "Enter index: ";
            cin >> index;
            cout << "Enter new transport: ";
            cin >> new_tr;

            log->changeTransport(index, new_tr);
            break;
        }

        default:
            cout << "Wrong choice" << endl;
            flag = false;
            break;
        }
    }

    return 0;
}

int main_menu()
{
    cout 
        << "1 - add order (queue)\n"
        << "2 - print orders (queue)\n"
        << "3 - edit order (queue)\n"
        << "4 - add transport (stack)\n"
        << "5 - print transports (stack)\n"
        << "6 - edit transport (stack)\n"
        << endl;
    
    int choice;
    cin >> choice;

    return choice;
}