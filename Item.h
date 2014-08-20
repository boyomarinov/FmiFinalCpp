#include <iostream>
using namespace std;

template <class T> class Stack;
template <class T> class Queue;
template <class T>
class Item
{
	private:
		friend class Stack<T>;
		friend class Queue<T>;
		Item(const T& x = 0){
			this->inf = x;
			this->next = NULL;
		}
		T inf;
		Item *next;
};