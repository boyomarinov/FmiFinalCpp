#include <iostream>
#include "Item.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(){
	#pragma region Stack
	cout << "STACK\n";
	Stack<int>* st = new Stack<int>();
	st->Push(1);

	int popped;
	if(st->Pop(popped))
	{
		cout << popped << "\n";
	}
	else 
	{
		cout << "Some error" << "\n";
	}

	st->Push(2);
	st->Push(3);
	st->Push(4);

	st->Print();
	cout << "\n";
	#pragma endregion Stack

	#pragma region Queue
	double val;
	Queue<double>* q = new Queue<double>();
	q->Enqueue(1.1);
	q->Enqueue(2.2);
	q->Enqueue(3.3);
	q->Dequeue(val);
	q->Print();
	#pragma endregion Queue
	
	return 0;
}