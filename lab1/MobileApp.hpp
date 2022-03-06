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
	Documentation(vector<string> doc = {}) : documentation(doc) {};
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

	string getSurname() {return surname;}
};

class TeamLead
{
private:
	string surname;
	vector<Developer> developers;

public:
	TeamLead() {};
	TeamLead(string surname, vector<Developer> devs) : surname(surname), developers(devs) {};
	TeamLead(const TeamLead & obj) : surname(obj.surname), developers(obj.developers) {};

	void appendDeveloper(Developer dev) { developers.push_back(dev); }
	void appendTaskToDeveloper();

	string getSurname() {return surname;}
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
	void changePermisssions(map<string, char> custom_permissions = {})
	{ 
			if (!custom_permissions.empty())
				permissions = custom_permissions; 
	}
	int isStaff();
};


class Application
{
private:
	string title;

	Documentation docs;
	Stack stack;
	vector<Developer> developers;
	vector<TeamLead> leads;

public:
	Application() {};
	Application(string title, Documentation docs, Stack stack, vector<Developer> developers, vector<TeamLead> leads) : title(title), docs(docs), stack(stack), developers(developers), leads(leads) {};
	Application(const Application&);
	
	void setDoc(Documentation doc) { docs = doc; }
	Documentation getDoc() { return docs; }

	void setDevelopers(vector<Developer> devs) { developers = devs; }
	void setLeads(vector<TeamLead> leads) { this->leads = leads; }
	void setStack(Stack stack) { this->stack = stack; }
	Stack getStack() { return stack; } 

	void printInfo();
};
