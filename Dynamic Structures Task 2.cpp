#include <iostream>
#include<conio.h>
struct elem{
	int key;
	elem *next;
} *left = NULL, *right = NULL;


void push_l(int n)
{
	elem *p;
	p = left;
	left = new elem;
	left->key = n;
	left->next = p;
	if (right == NULL)
		right = left;
}

void push_r(int n)
{
	elem *p;
	p = right;
	right = new elem;
	right->key = n;
	right->next = NULL;
	if (left == NULL)
		left = right;
	else
		p->next = right;
}

int pop_l(int &n)
{
	elem *p;
	if (left)
	{
		n = left->key;
		p = left;
		left = left->next;
		if (left == NULL)
			right = NULL;
		delete p;
		return 1;
	}
	else return 0;
}

int pop_r(int &n)
{
	elem *p;
	if (right)
	{
		n = right->key;
		if (left == right)
		{
			delete right;
			left = right = NULL;
		}

		else
		{
			p = left;
			while (p->next != right)
				p = p->next;
			n = right->key;
			p->next = NULL;
			delete right;
			right = p;
		}
		return 1;
	}
	else return 0;
}

int main()
{
	int ch;
	do{
		int num;
		cout << "\n   MENU \n";
		cout << "1 - Input left \n";
		cout << "2 - Input right \n";
		cout << "3 - Output left \n";
		cout << "4 - Output right \n";
		cout << "5 - Exit \n";
		cout << "6-  Trie 4etnite \n";
		cout << "\n\nVavedete svoq izbor: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
		case 2:
			cout << "\nVavedete 4islo: ";
			cin >> num;
			if (ch == 1)
				push_l(num);
			else
				push_r(num);
			break;
		case 3:
		{
			if (left == NULL)
				cout << "The deck is empty!!\n";
			while (pop_l(num))
				cout << num << "  ";
			break;
		}
		case 4:
		{
			if (right == NULL)
				cout << "The deck is empty!!\n";
			while (pop_r(num))
				cout << num << "   ";
			break;
		}
		case 6: iztrivane(); break;
		}
	} while (ch != 5);
	system("pause");
	return 0;
}