#pragma once
using namespace std;


enum State { begin, middle };

template <class T>
class Transaction {

private:
	T* currentState;
	T* prevState;

public:

	Transaction() :prevState(NULL), currentState(new T) {};
	Transaction(const Transaction& obj) : 
		currentState(new T(*(obj.currentState))), 
		prevState(NULL) {};

	~Transaction() {
		delete currentState; delete prevState;
	}

	Transaction& operator=(const Transaction& obj);
	T* operator->();

	void showState(State state);
	int beginTransactions(int accountNumber);
	void commit();
	void deleteTransactions();

};