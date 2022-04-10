#include <iostream>
#include <vector>
#include <map>

#include "model.hpp"
#include "model.cpp"

using namespace std;

int menu();

int main()
{   
    BookList * books = new BookList();

    bool flag = true;
    while(flag)
    {
        switch (menu())
        {
        case 1:
        {      
            string topic, value;
            char c;

            cout << "Enter topic: ";
            cin.get(c);

            while ( std::cin.get(c) && c != '\n' )
                topic += c;  

            cout << "Enter value: ";
            while ( std::cin.get(c) && c != '\n' )
                value += c;      

            books->append(topic, value);
            cout << "successfully appended" << endl;
            break;
        }

        case 2:
        {   
            books->print();

            int choice;
            cout << "select the topic you would like to delete: ";
            cin >> choice;

            books->remove(choice);
            cout << "successfully deleted" << endl;
            break;
        }

        case 3:
        {   
            string topic;
            cout << "select the topic you would like to edit: ";
            cin >> topic;
            
            string line;
            vector<string> values;
            cout << "enter the values to be rewriitten for this topic: ";
            while (cin >> line)
            {   
                if (line == "end")
                    break;
                values.push_back(line);
            }

            books->edit(topic, values);

            break;
        }

        case 4:
        {   
            cout << endl;
            books->print();
            cout << endl;
            break;
        }

        case 5:
        {
            break;
        }

        case 6:
        {
            break;
        }

        case 7:
        {
            break;
        }

        default:
            cout << "Wrond choice" << endl;
            break;
        }
    }

    return 0;
}


int menu()
{   
    cout 
        << "1 - Append\n"
        << "2 - Delelte\n"
        << "3 - Edit\n"
        << "4 - Print\n"
        << "5 - Put to file\n"
        << "6 - Search\n"
        << "7 - Sort\n"
        << "0 - Exit" 
        << endl;

    int choice;
    cin >> choice;
    return choice;
}