#include <iostream>

#include "MobileApp.hpp"
#include "SmartPointer.hpp"
#include "Transaction.hpp"


int main()
{

	Documentation doc1 = Documentation({ "This is app,", "helps people do something!" });
	Stack stack1 = Stack({ "DRF", "PostgreSQL", "Docker", "Python QIWI", "React", "AWS textract" });
	Developer dev1 = Developer("Gushtyn");
	Developer dev2 = Developer("Art");
	TeamLead lead1 = TeamLead("Evgen", { dev1, dev2 });
	SmartPointer<Application> greatApp = new Application(doc1, stack1, { dev1, dev2 }, {lead1});

	Transaction<SmartPointer<Application>> greatAppTransact;

	greatAppTransact.beginTransactions();
	Documentation new_doc = Documentation({ "There's not an app,", "!!!" });

	return 0;
}

