#include <vector>
#include <map>
#include <string>
#include <bits/stdc++.h>

#include "model.hpp"

using namespace std;


BookList::BookList(map<string, vector<string>> book_list)
{
    this->book_list = book_list;
}

BookList::BookList(const BookList & obj)
{   
    book_list = obj.book_list;
}

void BookList::append(string topic, string title)
{
    map<string, vector<string>>::iterator it;
    it = book_list.find(topic);

    if (it != book_list.end()) {
        book_list[topic].push_back(title);
    }
    else {
        book_list[topic] = {title, };
    }
}

void BookList::remove(int index)
{
    if (index > book_list.size() or index < 1)
        throw "Index is not valid";

    book_list.erase(next(book_list.begin(), index - 1));
}   

void BookList::edit(string topic, vector<string> elem)
{   
    book_list.at(topic) = elem;
}

void BookList::edit(string topic, string elem)
{   
    book_list.at(topic) = {elem, };
}

void BookList::print()
{   
    int i = 0;
    for(auto topic : book_list)
    {
        cout << ++i << ") " + topic.first << endl;
        for (string book : topic.second)
            cout << "\t" << book << endl;
    }
}


vector<string> BookList::findTopic(string topic)
{
    map<string, vector<string>>::iterator it;
    it = book_list.find(topic);

    if (it != book_list.end()) {
        return book_list[topic];
    }   
    return {};
}

string BookList::findTitle(string title)
{
    // # TODO need to iterate by map and find this title
}

// comparators
bool topicCmp(pair<string, vector<string>>& a, pair<string, vector<string>>& b)
{
    return a.first < b.first;
}

bool titleCmp(string a, string b)
{
    return a < b;
}
// comparators

void BookList::sortTopic()
{
  
    vector<pair<string, vector<string>>> A;
  
    for (auto& it : book_list) {
        A.push_back(it);
    }
  
    sort(A.begin(), A.end(), topicCmp);
}

void BookList::sortTitle(string topic)
{
  
    map<string, vector<string>>::iterator it;
    it = book_list.find(topic);

    if (it != book_list.end()) {
        sort(book_list[topic].begin(), book_list[topic].end(), titleCmp);
    }  
  
}


void BookList::put_to_file(string file_name)
{
    for(auto topic : book_list)
    {
        vector<string> data_to_file;

        data_to_file.push_back(topic.first);
        for (auto title: topic.second)
            data_to_file.push_back(title);

        FileManagment::put_to_file(file_name, data_to_file);       
    }
}
