#include <iostream>

#include "MobileApp.hpp"


void Documentation::printDoc()
{
	cout << "DOCUMENTATION:" << endl;

	for (auto doc : documentation)
		cout << doc << endl;
}

void TeamLead::appendTaskToDeveloper()
{
}

Application::Application(const Application & obj)
{
	title = obj.title;
	docs = obj.docs;
	stack = obj.stack;
	developers = obj.developers;
	leads = obj.leads;
}

void Application::printInfo()
{
	cout << "---------------" << endl;
	docs.printDoc();

	cout << "Developers:" << endl;
	for (auto dev : this->developers)
		cout << "\t" << dev.getSurname() << endl;

	cout << "Stack: ";
	for (auto tech : this->stack.getTechnologies())
		cout << tech << ", ";

	cout << endl;
}


template<class T>
int CheckPermission<T>::isStaff()
{
	string name = typeid(T).name();
	cout << name << endl;
	return permissions[name];
}