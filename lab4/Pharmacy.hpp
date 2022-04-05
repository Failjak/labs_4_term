#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class NegativNum {};
class InsufficientFunds {};
class Order;

class Medicament
{
private:
    string title;
    string manual;
    float price;

public:
    Medicament() {};
    Medicament(string title, string manual, float price);
    Medicament(vector<string>);
    Medicament(const Medicament & obj) : title(obj.title), manual(obj.manual), price(obj.price) {};

    string getTitle() { return title; }
    string getManual() { return manual; }
    float getPrice() { return price; }

    void printInfo();
    string getInfo();

    friend istream& operator >>(istream& s, Medicament& d);
    friend ostream& operator <<(ostream& s, Medicament& d);
};

class People
{
protected:
    string surname;
    string name;

public:
    People(string surname="", string name="") : surname(surname), name(name) {};
    People(const People &obj) : surname(obj.surname), name(obj.name) {};

    string getName() { return name; }
    string getSurname() { return surname; }

    void setName(string name) { this->name = name; }
    void setSurname(string surname) { this->surname = surname; }

    string getFullName() { return surname + " " + name; }
};

class Pharmacist : public People
{
private:
    float salary;

public:
    Pharmacist(string surname, string name, float salary);
    Pharmacist(vector<string>);
    Pharmacist(const Pharmacist & obj) : People(obj.surname, obj.name), salary(obj.salary) {};

    void printInfo();
    string getInfo();
};


class User : public People
{
private:
    float balance;

public:
    User(string surname, string name, float balance) : People(surname, name), balance(balance) {};
    User(const User &);

    float getBalance() { return balance; }
 
};

class Build
{
private:
    string city;
    string street;
    string building;

public:
    Build(vector<string> address);
    Build(string city="", string street="", string building="") : city(city), street(street), building(building) {}; 
    Build(const Build &);

    string getCity() { return city; }
    string getStreet() { return street; }
    string getBuild() { return building; }

    void setCity(string city) { this->city = city; }
    void setStreet(string street) { this->street = street; }
    void setBuild(string build) {this->building = build; }

    void printAddres();
    string getAddress();
};

class Pharmacy : public Build
{
private:
    vector<Medicament> medicaments;
    vector<Pharmacist> pharmacists;

public:
    Pharmacy() {};
    Pharmacy(vector<Pharmacist> pharms, vector<string> address, vector<Medicament> meds) : 
        pharmacists(pharms), 
        medicaments(meds),
        Build(address) 
        {};
    // Pharmacy(const Pharmacy &);

    void printInfo();
    string getInfo();
    Pharmacist * choicePharm();
    Order * createOrder(User *);

    vector<Medicament> getMedicaments() {return medicaments;}
    vector<Pharmacist> getPharmacists() {return pharmacists;}

    void setMedicaments(vector<Medicament> new_meds) {medicaments = new_meds;}
};

class Order
{
private:
    vector<Medicament *> medicaments;
    User * user;
    bool status = false;

public:
    Order() : medicaments({}) {};
    Order(vector<Medicament *> medicaments) : medicaments(medicaments) {};
    Order(const Order &);

    void addMedicament(Medicament * med) { medicaments.push_back(med); }
    void printInfo();
    void setUser(User * user) { this->user = user; }
    void paid() { status = true; }
};