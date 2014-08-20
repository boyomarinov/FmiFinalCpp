#include <iostream>
//#ifndef ITEM_H
//#define ITEM_H
//#endif
using namespace std;

template <class T>
class Queue
{
	public:
		Queue();
		Queue(const T&);
		~Queue();
		Queue(const Queue&);
		Queue& operator=(const Queue&);
		void Enqueue(const T&);
		bool Dequeue(T&);
		bool Peek(T&) const;
		bool IsEmpty() const;
		void Print() const;
	private:
		Item<T> *front, *rear;
		void copyQueue(const Queue&);
		void deleteQueue();
};

template <class T>
Queue<T>::Queue()
{
	front = rear = NULL;
};

template <class T>
Queue<T>::Queue(const T& x)
{
	front = new Item<T>(x);
	rear = front;
};

template <class T>
Queue<T>::~Queue()
{
	deleteQueue();
};

template <class T>
Queue<T>::Queue(const Queue<T>& q)
{
	copyQueue(q);
};

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)
{
	if(this != &q)
	{
		deleteQueue();
		copyQueue(q);
	}

	return *this;
};

template <class T>
void Queue<T>::Enqueue(const T& x) 
{
	Item<T>* toAdd = new Item<T>(x);
	if(front)
	{
		rear->next = toAdd;
		rear = toAdd;
	}
	else
	{
		front = rear = toAdd;
	}
};

template <class T>
bool Queue<T>::Dequeue(T& x)
{
	Item<T>* p = front;
	if(!front)
	{
		return false;
	}

	if(front == rear)
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	delete p;

	return true;
};

template <class T>
bool Queue<T>::Peek(T& x) const
{
	if(!front)
	{
		return false;
	}

	x = front->inf;

	return true;
};

template <class T>
bool Queue<T>::IsEmpty() const
{
	return front == NULL;
}

template <class T>
void Queue<T>::Print() const
{
	Item<T>* p = front;
	while(p)
	{
		cout << p->inf << "  ";
		p = p->next;
	}
	cout << "\n";
};

template <class T>
void Queue<T>::copyQueue(const Queue<T>& q)
{
	front = rear = NULL;
	if(q->front)
	{
		Item<T>* p = q->front;
		while(p)
		{
			Enqueue(p);
			p = p->next;
		}
	}
};

template <class T>
void Queue<T>::deleteQueue()
{
	T x;
	while(Dequeue(x));
};