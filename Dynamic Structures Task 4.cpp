#include <iostream>
using namespace std;
struct elem{
	int key; elem *left, *right;
} *root = NULL;

int menu();
void add(int n, elem* &t);
void inorder(elem *t);
void rotate(elem *t);


int main(){
	int n = 0, num;
	do
	{
		n = menu();
		switch (n)
		{
		case(1) :
		{
			cout << "\nEnter value of item to be placed in a binary tree: ";
			cin >> num;
			add(num, root);
			break;
		}
		case (2) :
		{
			cout << "\nAll elements in a binary tree\n";
			inorder(root);
			break;
		}
		case (3) :
		{
			rotate(root);
			break;
		}
		}
	} while (n != 4);
}

int menu(){
	int izbor = 0;
	do{
		cout << "\n\n";
		cout << "   Main menu\n\n";
		cout << " 1. Add element \n";
		cout << " 2. Print all \n";
		cout << " 3. Rotate all \n";
		cout << " 4. Exit \n";
		cout << "Enter your choise (1-5): ";
		cin >> izbor;
	} while (izbor<1 || izbor>5);
	return izbor;
}

void add(int n, elem* &t){
	if (t == NULL)
	{
		t = new elem;
		t->key = n;
		t->left = t->right = NULL;
	}
	else
	{
		if (t->key<n)
			add(n, t->right);
		else
			add(n, t->left);
	}
}

void inorder(elem *t){
	if (t){
		inorder(t->left);
		cout << t->key << " ";
		inorder(t->right);
	}
}

void rotate(elem *t){
	if (t == NULL)
		return 0;
	else{
		elem*temp;
		rotate(t->left);
		rotate(t->right);
		temp = t->left;
		t->left = t->right;
		t->right = temp;
	}
};