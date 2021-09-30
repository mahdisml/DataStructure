#pragma once
#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;
class Infix
{
private:
	string InFix;
public:
	void operator =(string a){ InFix = a; }
	string PostFix()
	{
		Stack<char> temp;
		char t;
		string ans; // javabemoone 
		int size = InFix.size();
		for (int i = 0; i < size; i++)
		{
			if (InFix[i] == '(')
				temp.push(InFix[i]);
			else if (InFix[i] == '^')
				temp.push(InFix[i]);
			else if (InFix[i] == '/' || InFix[i] == '*')
			{
				while (temp.Top(t)) //boolean mige top dare ya nadare 
				{
					if (t == '^' || t == '*' || t == '/')
						ans = ans + t;
					else
						break;
					temp.pop(t); //miad karakter pop(delate) mikone 
				}
				temp.push(InFix[i]);
			}
			else if (InFix[i] == '-' || InFix[i] == '+')
			{
				while (temp.Top(t))
				{
					if (t == '^' || t == '/' || t == '*' || t == '-' || t == '+')
						ans = ans + t;
					else
						break;
					temp.pop(t); // miad t ha ro pop (delate) mikone
				}
				temp.push(InFix[i]);
			}
			else if (InFix[i] == ')')
			{
				while (temp.Top(t)) // enghad pop mikone b parantex baz berese
				{
					if (t != '(') // age parantez baz nabood
						ans = ans + t;
					else
						break;
					temp.pop(t);
				}
				temp.pop(t); // parantez baz pop mikone 
			}
			else
				ans = ans + InFix[i];
		}
		while (temp.pop(t))
			ans = ans + t;
		return ans;
	}
	// dar perfix b jaii inke algar b samt ras ezafe kone b samt chap ezafe mikone 
	string PerFix()
	{
		Stack<char> temp;
		char t;
		string ans;
		int size = InFix.size();
		for (int i = 0; i < size; i++)
		{
			if (InFix[i] == '(')
				temp.push(InFix[i]);
			else if (InFix[i] == '^')
				temp.push(InFix[i]);
			else if (InFix[i] == '/'|| InFix[i] == '*')
			{
				while (temp.Top(t))
				{
					if (t == '^' || t == '*' || t == '/')
						ans = t + ans;
					else
						break;
					temp.pop(t);
				}
				temp.push(InFix[i]);
			}
			else if (InFix[i] == '-' || InFix[i] == '+')
			{
				while (temp.Top(t))
				{
					if (t == '^' || t == '/' || t == '*' || t == '-' || t == '+')
						ans = t + ans;
					else
						break;
					temp.pop(t);
				}
				temp.push(InFix[i]);
			}
			else if (InFix[i] == ')')
			{
				while (temp.Top(t))
				{
					if (t != '(')
						ans = t + ans; 
					else
						break;
					temp.pop(t);
				}
				temp.pop(t);// mal parantez baz
			}
			else
				ans = InFix[i]+ans;
		}
		while (temp.pop(t))
			ans = t + ans;
		return ans;
	}
};
