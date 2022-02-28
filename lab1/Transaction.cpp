#include <iostream>

#include "Transaction.h"

using namespace std;


template <class T>
Transaction<T> &Transaction<T>::operator=(const Transaction<T> &obj)
{
	if (this != &obj)
	{
		delete currentState;
		currentState = new T(*(obj.currentState));
	}
	return *this;
}

template <class T>
T *Transaction<T>::operator->()
{
	return currentState;
}

template <class T>
void Transaction<T>::showState(State state)
{

	cout << "Object state ";

	if (!state)
		cout << "before transaction " << endl;
	else
		cout << "after transaction " << endl;

	if (prevState)
		cout << "prevState = " << prevState->getNumber() << endl;
	else
		cout << "prevState = NULL" << endl;

	cout << "currentState = " << currentState->getNumber() << endl;
}
template <class T>
int Transaction<T>::beginTransactions()
{

	delete prevState;
	prevState = currentState;
	currentState = new T(*prevState);
	if (!currentState)
		return 0;
	// currentState->setNumber(accountNumber);
	return 1;
}
template <class T>
void Transaction<T>::commit()
{

	delete prevState;
	prevState = NULL;
}
template <class T>
void Transaction<T>::deleteTransactions()
{

	if (prevState != NULL)
	{
		delete currentState;
		currentState = prevState;
		prevState = NULL;
	}
}
