#pragma once
#include <cstddef>

template <class T>
struct Status {
	T* ptr;
	int counter;
};

template <class T>
class SmartPointer
{
	Status<T>* smartPtr;

public:
	SmartPointer(T*);
	SmartPointer(const SmartPointer&);
	~SmartPointer();
	SmartPointer& operator=(const SmartPointer&);
	T* operator->() const;

	int getCounter() { return smartPtr->counter; }
};