#pragma once // heder yek bar ejra beshe 
#include<string>
using namespace std;
template<class Type>
class Stack;
template<class Type>
class StackNode
{
	friend class Stack<Type>;
private:
	Type data;
	StackNode<Type> *next;
public:
	StackNode()
	{
		next = nullptr;
	}
};
template<class Type>
class Stack
{
private:
	StackNode<Type> *Head; 
public:
	Stack() { Head = new StackNode<Type>; Head->next = Head; }// list halgh
	~Stack() { Type t; while (Head->next != Head)pop(t); delete Head; }// delate mikone ta head next ba head mosavi beshe 
	void push(Type);
	bool pop(Type &);
	bool Top(Type &);
	bool empty() { if (Head->next == Head)return true; return false; }//true => khali false => pore
};
template<class Type>
void Stack<Type>::push(Type a)
{
	StackNode<Type> *Temp = new StackNode<Type>;
	Temp->data = a;
	Temp->next = Head->next;
	Head->next = Temp;
}

template<class Type>
bool  Stack<Type>::pop(Type &x)
{
	if (Head->next == Head) // poshte khali bashe 
		return false;
	StackNode<Type> *Temp = new StackNode<Type>;
	Temp = Head->next; // heade-> next ====>>>> Top 
	Head->next = Temp->next;
	x = Temp->data;
	delete Temp;
	return true;
}

template<class Type>
bool Stack<Type>::Top(Type &x)
{
	if (Head->next == Head)
		return false;
	x = Head->next->data;
	return true;
}
