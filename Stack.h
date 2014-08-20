#include <iostream>
//#ifndef ITEM_H
//#define ITEM_H
//#endif
using namespace std;

template <class T>
class Item;
template <class T>
class Stack {
public:
	Stack();
	Stack(const T&);
	~Stack();
	Stack(const Stack &);
	Stack& operator=(const Stack &);
	void Push(const T&);
	bool Pop(T&);
	bool Top(T&) const;
	bool Empty() const;
	void Print() const;
private:
	Item<T> *start;
	void DeleteStack();
	void CopyStack(const Stack &);
};

template <class T>
Stack<T>::Stack()
{
	this->start = NULL;
};

template <class T>
Stack<T>::Stack(const T& x)
{
	this->start = new Item<T>(x);
};

template <class T>
Stack<T>::~Stack(){
	DeleteStack();
};

template <class T>
Stack<T>::Stack(const Stack& s){
	CopyStack(s):
};

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &s)
{
	if(this != &s)
	{
		DeleteStack();
		CopyStack(s);
	}

	return *this;
};

template <class T>
void Stack<T>::Push(const T& x)
{
	Item<T>* p = new Item<T>(x);
	p->next = start;
	start = p;
};


template <class T>
bool Stack<T>::Pop(T& x)
{
	if(start == NULL)
	{
		return false;
	}

	Item<T>* p = start;
	x = start->inf;
	start = start->next;
	delete p;

	return true;
};

template <class T>
bool Stack<T>::Top(T& x) const
{
	if(start == NULL)
	{
		return false;
	}

	x = start->inf;

	return true;
};

template <class T>
bool Stack<T>::Empty() const
{
	return this->start == NULL;
};

template <class T>
void Stack<T>::Print() const 
{
	Item<T>* iter = start;
	while(iter != NULL)
	{
		cout << iter->inf << "  ";
		iter = iter->next;
	}
	cout << "\n";
};

template <class T>
void Stack<T>::DeleteStack()
{
	Item<T>* temp;
	while(temp->next != NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
};

template <class T>
void Stack<T>::CopyStack(const Stack& s)
{
	Item<T> *iter, *first, *second;
	iter = s.start;
	start = new Item<T>(iter->inf);
	first = start;
	iter = iter->next;
	while(iter)
	{
		second = new Item<T>(iter->inf);
		first->next = second;
		first = second;
		iter = iter->next;
	}
};