#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "file_managment.hpp"

using namespace std;


void FileManagment::clear_file(string file_name)
{
    std::ofstream ofs;
    ofs.open(file_name, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}


void FileManagment::put_to_file(string file_name, vector<string> data)
{
    ofstream file;
    file.open(file_name, ios::app);

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


vector<string> FileManagment::get_from_file(string file_name)
{
    ifstream file;
    file.open(file_name);

    if (!file) 
    {
        cout << "Cant open the file: " << file_name << endl;
        cout << "File fail - " << file.fail() << endl;

        return {};
    }

    vector<string> data;
    string d;

    while(true)
    {
        if (file.eof()) break;
        getline(file, d);
        data.push_back(d);
    }

    file.close();

    return data;
}