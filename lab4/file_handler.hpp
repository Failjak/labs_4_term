#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

void clear_file(string file_name)
{
    std::ofstream ofs;
    ofs.open(file_name, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}


void put_to_file(string file_name, vector<string> data)
{
    ofstream file;
    file.open(file_name, ios::app);

    file.seekp(0, ios::end);
    int endpos = file.tellp();
    int n = endpos / sizeof(string);
    cout << "In file there are - " + to_string(n) + " strings" << endl;

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
    ifstream file;
    file.open(file_name);

    file.seekg(0, ios::beg);
    int n = file.tellg();
 
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