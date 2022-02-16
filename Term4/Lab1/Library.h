#pragma once
#include <string>
#include <vector>


class Student 
{
private:
	string surname;
	string name;
	string birth_date;

public:
	Student();
	Student(std::string surname, std::string name, std::string bd) : surname(surname), name(name), birth_date(bd) {};
	Student(const Student &);

	std::string getSurname() { return surname; }
	std::string getName() { return name; }
	std::string getBirthDate() { return birth_date; }

	void setSurname(std::string s) { surname = s; }
	void setName(std::string n) { name = n; }
	void setBirthDate(std::string bd) { birth_date = bd; }
};

class Subscriber: public Student
{
private:
	static int st_id;

	int id;

public:
	Subscriber(): id(st_id++);
	Subscriber(const Subscriber&);
};


class Subscription
{
private:
	std::string sub_id;
	int subscriber_id;
	std::vector<int> books_id;

public:
	Subscription();
	Subscription(Subscription &obj);
};


class LibraryEmploye
{
private:
	std::string surname;

public:
	LibraryEmploye();
	LibraryEmploye(LibraryEmploye &obj);
};


class Book
{
private:
	static int st_id;

	int id;
	std::string title;
	std::string author;
	std::string publisher;

public:
	Book(): id(st_id++);
	Book(Book &obj);

	void setTitle(std::string new_title) { title = new_title; }
	void setLastName(std::string new_last_name) { author = new_last_name; }
	void setPublisher(std::string new_publisher) { publisher = new_publisher; }

	std::string  getTitle() { return title; }
	std::string  getAuthor() { return author; }
	std::string  getPublisher() { return publisher; }
};