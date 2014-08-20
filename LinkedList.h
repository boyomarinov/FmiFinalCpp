#include <iostream>
using namespace std;

template <class T>
class LList
{
	public:
		LList();
		LList(const T&);
		~LList();
		LList(const LList&);
		LList& operator=(const LList&);

		// iterators
		Item<T>* Iter();
		void IterStart(Item<T>* = NULL);
		bool IterView(T&) const;

		// insertions
		void InsertAtStart(const T&);
		void InsertAtEnd(const T&);
		void InsertBefore(Item<T>*, const T&);
		void InsertAfter(Item<T>*, const T&);

		// deletions
		void DeleteBefore(Item<T>*, T&);
		void DeleteAfter(Item<T>*, T&);
		void DeleteElem(Item<T>*, T&);

		int Length() const;
		void Print() const;
		bool IsEmpty() const;
		void Reverse();
	private:
		Item<T> *start,
				*end,
				*current;
		void DeleteLList();
		void CopyLList(const LList&);
};

// ------- BIG FOUR -----------------------------
template <class T>
LList<T>::LList()
{
	start = end = NULL;
}

template <class T>
LList<T>::LList(const T& x)
{
	start = new Item<T>(x);
	end = start;
}

template <class T>
LList<T>::~LList()
{
	DeleteLList();
}

template <class T>
LList<T>::LList(const LList<T>& ll)
{
	CopyLList(ll);
}

template <class T>
LList& LList<T>::operator=(const LList<T>& ll)
{
	if(this != &ll)
	{
		DeleteLList();
		CopyLList(ll);
	}

	return *this;
}

// --------- ITERATORS --------------------------------
template <class T>
Item<T>* LList<T>::Iter()
{
	Item<T>* p = current;
	if(current)
	{
		current = current->next;
	}

	return p;
}

template <class T>
void LList<T>::IterStart(Item<T>* p)
{
	if(p)
	{
		current = p;
	}
	else
	{
		current = start;
	}
}

template <class T>
bool LList<T>::IterView(T&) const
{
	if(!current)
	{
		return false;
	}

	x = current->inf;

	return true;
}

// ----------- INSERTIONS ----------------------------
template <class T>
void LList<T>::InsertAtStart(const T& x)
{
	Item<T>* toInsert = new Item<T>(x);
	if(!end)
	{
		start = toInsert;
		end = start;
	}
	else
	{
		toInsert->next = start;
		start = toInsert;
	}
}

template <class T>
void LList<T>::InsertAtEnd(const T& x)
{
	Item<T>* toInsert = new Item<T>(x);
	if(!start)
	{
		end = toInsert;
		start = end;
	}
	else
	{
		end->next = toInsert; 
		end = toInsert;
	}
}

template <class T>
void LList<T>::InsertBefore(Item<T>* p, const T& x)
{
	Item<T>* q = new Item<T>(x);
	*q = *p;
	p->inf = x;
	p->next = q;
	if(p == end)
	{
		end == q;
	}
}

template <class T>
void LList<T>::InsertAfter(Item<T>* p, const T& x)
{
	Item<T>* q = new Item<T>(x);
	q->link = p->link;
	p->link = q;
	if(p == end)
	{
		end = q;
	}
}

// ---------- DELETIONS -----------------------
template <class T>
void DeleteBefore(Item<T>* p, T& x)
{
}

template <class T>
void DeleteAfter(Item<T>* p, T& x)
{
}

template <class T>
void DeleteElem(Item<T>* p, T& x)
{
}