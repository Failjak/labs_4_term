#include <iostream>
#include <cstddef>
#include <memory>

#include "MobileApp.hpp"
#include "MobileApp.cpp"
#include "SmartPointer.hpp"
#include "SmartPointer.cpp"
#include "Transaction.hpp"
#include "Transaction.cpp"

using namespace std;

int main()
{

	Documentation doc1({ "This is app,", "helps people do something!" });
	shared_ptr<Stack> stack1(new Stack({ "DRF", "PostgreSQL", "Docker", "Python QIWI", "React", "AWS textract" }));
	shared_ptr<Developer> dev1(new Developer("Gushtyn"));
	shared_ptr<Developer> dev2(new Developer("Art"));
	shared_ptr<TeamLead> lead1(new TeamLead("Evgen", { *dev1, *dev2 }));
	Transaction<Application> greatApp;

	greatApp->setDoc(doc1);
	greatApp->setDevelopers(vector<Developer>{*dev1, *dev2});
	greatApp->setStack(*stack1);


	cout << "BEFORE DOCS TRANSACTION" << endl;
	greatApp->printInfo();

	greatApp.beginTransactions();
	greatApp->setDoc(Documentation({ "There's not an app,", "!!!" }));
	greatApp.deleteTransactions();

	cout << "AFTER deleted DOCS TRANSACTION" << endl;
	greatApp->printInfo();
	
	cout << "BEFORE STACK TRANSACTION" << endl;
	greatApp->printInfo();

	greatApp.beginTransactions();
	greatApp->setStack(Stack({"just", "nothing"}));
	greatApp.commit();

	cout << "AFTER commit STACK TRANSACTION" << endl;
	greatApp->printInfo();

	return 0;
}

