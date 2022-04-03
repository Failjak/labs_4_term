#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;


void put_to_file(string file_name, vector<string> data)
{
    ofstream file;
    file.open(file_name);

    if (file.is_open())
    {
        for(string d : data)
        {
            file << d << endl;
        }

    }
    file.close();

    return;
}


vector<string> get_from_file(string file_name)
{
    vector<string> data;
    
    ifstream file;
    file.open(file_name);

    if (file.is_open())
    {
        string d;
        while(file >> d)
        {
            data.push_back(d);
        }

    }
    file.close();

    return data;
}