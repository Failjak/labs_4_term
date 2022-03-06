#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;


class Documentation
{
private:
	vector<string> documentation;

public:
	Documentation(vector<string> doc) : documentation(doc) {};
	Documentation(const Documentation& obj) : documentation(obj.documentation) {};

	vector<string> getDoc() { return documentation; }
	void printDoc();
};

class Stack
{
private:
	vector<string> technologies;

public:
	Stack(vector<string> techs = {}) : technologies(techs) {};
	Stack(const Stack & obj) : technologies(obj.technologies) {};

	void appendTechnology(string tech) { technologies.push_back(tech); }
	vector<string> getTechnologies() { return technologies; }
};


class Developer 
{
private:
	string surname;
	vector<string> tasks;

public:
	Developer(string surname, vector<string> tasks = {}) : surname(surname), tasks(tasks) {};
	Developer(const Developer & obj) : surname(obj.surname), tasks(obj.tasks) {};

};

class TeamLead
{
private:
	string surname;
	vector<Developer> developers;

public:
	TeamLead(string surname, vector<Developer> devs) : surname(surname), developers(devs) {};
	TeamLead(const TeamLead & obj) : surname(obj.surname), developers(obj.developers) {};

	void appendDeveloper(Developer dev) { developers.push_back(dev); }
	void appendTaskToDeveloper();
};


template<class T>
class CheckPermission 
{
private:
	map<string, char> permissions = {
	{ "Developer", '0' },
	{ "TeamLead", '1' },
	};

public:
	static void changePermisssions(map<string, char> custom_permissions = {})
	{ 
			if (!custom_permissions.empty())
				permissions(custom_permissions); 
	}


	static int isStaff();
};


class Application
{
private:
	Documentation docs;
	Stack stack;
	vector<Developer> developers;
	vector<TeamLead> leads;

public:
	Application(Documentation docs, Stack stack, vector<Developer> developers, vector<TeamLead> leads) : docs(docs), stack(stack), developers(developers), leads(leads) {};
	Application(const Application&);
	
	void setDoc(Documentation doc) : docs(docs) {};
};


template<class T>
inline int CheckPermission<T>::isStaff()
{
	string name = typeid(T).name();
	cout << name << endl;
	return permissions[name];
}
