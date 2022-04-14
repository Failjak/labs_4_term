#pragma once

#include <vector>
#include <map>
#include <string>

#include "file_managment.hpp"

using namespace std;


class BookList : public FileManagment
{
private:
    map<string, vector<string>> book_list;

public:
    BookList() {};
    BookList(map<string, vector<string>>);
    BookList(const BookList &);

    void append(string, string);
    void remove(int);
    void edit(string, vector<string>);
    void edit(string, string);

    void print();
    map<string, vector<string>> getBookList() { return book_list; }

    vector<string> findTopic(string); // return all titles from the topic
    string findTitle(string); //return topic

    void sortTopic(); // sort by topics
    void sortTitle(string); // sort in this topic

    void put_to_file(std::string file_name);
};