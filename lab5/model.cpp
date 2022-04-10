#include <vector>
#include <map>
#include <string>

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