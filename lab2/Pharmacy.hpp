#include <string>
#include <vector>

using namespace std;


class Medicament
{
private:
    string title;
    string manual;
    float price;

public:
    Medicament();
    Medicament(string title, float price, string manual) : title(title), manual(manual) {};
    Medicament(const Medicament &);

    string getTitle() { return title; }
    string getManual() { return manual; }
};

class Provider
{

};

class Pharmacist
{
private:
    string surname;
    string name;
    float salary;

public:
    Pharmacist();
    Pharmacist(const Pharmacist &);
};


class Build
{
private:
    string city;
    string street;
    string building;

public:
    Build();
    Build(const Build &);
};

class Pharmacy : publid Build
{
private:
    vector<Medicament> medicaments;
    vector<Pharmacist> pharmacists;

public:
    Pharmacy();
    Pharmacy(const Pharmacy &);

};