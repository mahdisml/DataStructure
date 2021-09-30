#pragma once
#include<string>
using namespace std;
template<class Type>
class List;
template<class Type>
class ListNode
{
	friend class List<Type>;
private:
	Type data;
	char t;
	ListNode<Type> *next;
public:
	ListNode()
	{
		next = nullptr;
	}
};
template<class Type>
class List
{
private:
	ListNode<Type> *Head;
public:
	List() { Head = new ListNode<Type>; Head->next = Head; }
	~List()
	{
		while (Head->next != Head)
		{
			ListNode<Type> *Temp = new ListNode<Type>;
			Temp = Head->next;
			Head->next = Temp->next;
			delete Temp;
		}
		delete Head;
	}
	void push(Type, char);
	bool empty()
	{
		if (Head->next == Head)
			return true;
		return false;
	}
	bool Find(char, Type &);
	void Clear();
};
template<class Type>
void List<Type>::push(Type a, char t)
{
	ListNode<Type> *Temp = new ListNode<Type>;
	Temp->data = a;
	Temp->t = t;
	Temp->next = Head->next;
	Head->next = Temp;
}
template<class Type>
bool List<Type>::Find(char a, Type &b)
{
	if (Head->next == Head)
	{
		return false;
	}
	ListNode<Type> *Temp = new ListNode<Type>;
	Temp = Head;
	while (Temp->next != Head)
	{
		Temp = Temp->next;
		if (Temp->t == a)
		{
			b = Temp->data;
			return true;
		}
	}
	return false;
}
template<class Type>
void List<Type>::Clear()
{
	while (Head->next != Head)
	{
		ListNode<Type> *Temp = new ListNode<Type>;
		Temp = Head->next;
		Head->next = Temp->next;
		delete Temp;
	}
}