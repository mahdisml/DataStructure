#include"List.h"
#include"Stack.h"
#include<iostream>
#include<string>
#include<cmath>
#include"Infix.h"
using namespace std;
class Porje
{
private:
	List<double> data;
	string InFix;
public:
	friend istream &operator >>(istream &input , Porje &a) 
	{
		string dade;
		input >> dade;
		a.InFix = dade;
		return input;
	}
	void operator =(string a){ InFix = a; }
	string setPostFix() //infix 
	{
		Infix a; a = InFix;  return a.PostFix();
	}
	string setPerFix()
	{
		Infix a; a = InFix;  return a.PerFix();
	}
	double Answer_PostFix()
	{
		Infix A;
		double d, d1;
		Stack<double> temp;
		A = InFix; // infix mizare to class Infix 
		string postfix = A.PostFix();
		int size = postfix.size();
		for (int i = 0; i < size; i++)
		{
			if (postfix[i] != '*'&&postfix[i] != '/'&&postfix[i] != '-'&&postfix[i] != '+'&&postfix[i] != '^')
			{
				if (data.Find(postfix[i], d))
					temp.push(d);
				else
				{
					cout << "Enter Number " << postfix[i] << " =";
					cin >> d;
					data.push(d, postfix[i]);
					temp.push(d);
				}
			}
			else
			{
				temp.pop(d);
				temp.pop(d1);
				if (postfix[i] == '+')
					temp.push(d + d1);
				else if (postfix[i] == '-')
					temp.push(d1 - d);
				else if (postfix[i] == '*')
					temp.push(d1*d);
				else if (postfix[i] == '/')
					temp.push(d1 / d);
				else if (postfix[i] == '^')
					temp.push(pow(d1, d));
			}
		}
		temp.Top(d);
		return d;
	}
	double Answer_PerFix()
	{
		Infix A;
		double d, d1;
		Stack<double> temp;
		A = InFix;
		string perfix = A.PerFix();
		int size = perfix.size();
		for (int i = size - 1; i > -1; i--) // az akhar Shoroo mikone 
		{
			if (perfix[i] != '*'&&perfix[i] != '/'&&perfix[i] != '-'&&perfix[i] != '+'&&perfix[i] != '^')
			{
				if (data.Find(perfix[i], d))
					temp.push(d);
				else
				{
					cout << "Enter Number " << perfix[i] << " =";
					cin >> d;
					data.push(d, perfix[i]);
					temp.push(d);
				}
			}
			else
			{
				temp.pop(d);
				temp.pop(d1);
				if (perfix[i] == '+')
					temp.push(d + d1);
				else if (perfix[i] == '-')
					temp.push(d1 - d);
				else if (perfix[i] == '*')
					temp.push(d1*d);
				else if (perfix[i] == '/')
					temp.push(d1 / d);
				else if (perfix[i] == '^')
					temp.push(pow(d1, d));
			}
		}
		temp.Top(d);
		return d;
	}
	void Clear()
	{
		data.Clear();
	}
};