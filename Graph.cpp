#include <iostream>
#include <string.h>
using namespace std;
//basic graph operations
const int n = 15;

struct link{ char key; link*next; }*gr[n],*q=NULL;

void init(link *gr[n]){
	for (int i = 0; i < n; i++)
		gr[i] = NULL;
}

int search_node(link*gr[n], char c){
	int flag = 0;
	for (int i = 0; i < n; i++)
		if (gr[i])
			if (gr[i]->key == c) flag = 1;
	return flag;
}

int search_arc(link *gr[5], char c1, char c2){
	int flag = 0;
	if (search_node(gr, c1) && search_node(gr,c2))
	{
		int i = 0;

		while (gr[i]->key != c1) i++;
		link *p = gr[i];
		while (p->key != c2&&p->next != NULL)
			p = p->next;
		if (p->key = c2) flag = 1;
	}
	return flag;
}

void add_node(link *gr[n], char c){
	if (search_node(gr, c))
		cout << endl << "Existing node!" << endl;
	else{
		int j = 0;
		while (gr[j] && (j < n)) j++;
		if (gr[j] == NULL)
		{
			gr[j] = new link;
			gr[j]->key = c;
			gr[j]->next = NULL;
		}
		else
			cout << endl << "Overflow!" << endl;

	}
}

void add_arc(link *gr[n], char c1, char c2){
	int i = 0;
	link *p;
	if (search_arc(gr, c1, c2)){
		cout << endl << "Existing arc!";
	}
	else{
		if (!(search_node(gr, c1)))
			add_node(gr, c1);
		if (!(search_node(gr, c2)))
			add_node(gr, c2);
		while (gr[i]->key != c1)
			i++;
		p = new link;
		p->key = c2;
		p->next = gr[i]->next;
		gr[i]->next = p;
	}
}

void del_node(link *gr[n], char c)
{
	if (search_node(gr, c))
	{
		int i = 0;
		while (gr[i]->key != c)
			i++;
		link *p, *q=NULL;
		while (gr[i] != NULL)
		{
			p = gr[i];
			gr[i] = p->next;
			delete p;

		}
		for (i = 0; i < n; i++)
			if (gr[i])
			{
				p = gr[i];
				while ((p->key != c) && (p->next != NULL))
				{
					q = p;
					p = p->next;
				}
				if (p->key == c){
					q->next = p->next;
					delete p;
				}
			}
	}
	else cout << "The node is not in the graph!";

}

void del_arc(link *gr[n], char c1, char c2){
	if (search_arc(gr, c1, c2)){
		int i = 0;
		while (gr[i]->key != c1)
			i++;
		link*p = gr[i], *q=NULL;
		while (p->key != c2)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
	}
	else
		cout << endl << "The arc is not in the graph";
}

void list_node(link *gr[n]){
	cout << endl;
	for (int i = 0; i < n; i++)
		if (gr[i])
			cout << gr[i]->key;
}

void main(){
	char c, k;
	int m;
	do{
		cout << "\n\n   Main menu  \n\n";
		cout << "1----Init" << endl;
		cout << "2----Add node" << endl;
		cout << "3----Add arc" << endl;
		cout << "4----Delete Node" << endl;
		cout << "5----Delete Arc" << endl;
		cout << "6----Search Node" << endl;
		cout << "7----Seach Arc" << endl;
		cout << "8----Print all" << endl;
		cout << "9----END" << endl;
		cout << "Enter:" << endl;
		cin >> m;
		switch (m)
		{
		case 1:{
			init(gr); break;
		}
		case 2: {
			cout << endl << "Enter node(char):";
			cin >> c;
			add_node(gr, c);
			break;
		}
		case 3: {
			cout << endl << "Enter first node(char):";
			cin >> c;
			cout << "Enter second node(char):";
			cin >> k;
			add_arc(gr, c, k);
			break;
		}
		case 4: {
			cout << endl << "Enter node(char):";
			cin >> c;
			del_node(gr, c);
			break;
		}
		case 5:{
			cout << endl << "Enter first node(char):";
			cin >> c;
			cout << endl << "Enter second node(char):";
			cin >> k;
			del_arc(gr, c, k);
			break;
		}
		case 6:{
			cout << endl << "Enter node(char): ";
			cin >> k;
			if (search_node(gr, k))
				cout << endl << "Search result: OK!";
			else
				cout << endl << "Seach result : NO!";
			break;
		}
		case 7:{
			cout << "Enter first node (char):";
			cin >> c;
			cout << "Enter second node(char):";
			cin >> k;
			if (search_arc(gr, c, k))
				cout << endl << "Search result : OK!";
			else
				cout << endl << "Search result : NO!";
			break;
		}
		case 8:
		{list_node(gr); }
		}
	} while (m != 9);
	system("pause");
}