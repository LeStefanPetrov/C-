#include <iostream>
#include <locale>

struct elem{
	int key;
	elem *next;
} *p, *left = NULL, *right = NULL, *bonus1 = NULL, *bonus2 = NULL;

void push_l(int n, elem *&left, elem*&right)
{
	p = left;
	left = new elem;
	left->key = n;
	left->next = p;
	if (right == NULL)
		right = left;

}

void push_r(int n, elem *&left, elem*&right)
{
	p = right;
	right = new elem;
	right->key = n;
	right->next = NULL;
	if (left == NULL)
		left = right;
	else
		p->next = right;
}

int pop_l(int &n, elem *&left, elem *&right)
{
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

int pop_r(int &n, elem *&left, elem *&right)
{
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
void case5(int &n, elem *left, elem *right, elem *bonus1, elem*bonus2)
{
	int a;
	if (left == NULL){
		std::cout << "Дека е празен!!\n";
	}
	else{
		std::cout << "Въведете число: ";
		std::cin >> a;
		while (pop_l(n, left, right))
			if (n%a != 0){
				push_l(n, bonus1, bonus2);
				while (pop_l(n, bonus1, bonus2))
					std::cout << n << " ";
			}
	}
}
int main()
{
	setlocale(LC_ALL, "bulgarian");
	int ch;
	do{
		int num, br = 0;
		std::cout << "\n   Меню \n";
		std::cout << "1 - Въвеждане отляво \n";
		std::cout << "2 - Въвеждане отдясно \n";
		std::cout << "3 - Извеждане отляво \n";
		std::cout << "4 - Извеждане отдясно \n";
		std::cout << "5 - Извеждане на числата, които не са кратни на числото 'а'   \n";
		std::cout << "6 - Изход \n";
		std::cout << "\n\nВъведете своя избор: ";
		std::cin >> ch;

		switch (ch)
		{
		case 1:
		case 2:
			std::cout << "\nВъведете число: ";
			std::cin >> num;
			if (ch == 1){
				push_l(num, left, right);
			}
			else{
				push_r(num, left, right);
			}
			break;
		case 3:
		{
			if (left == NULL)
				std::cout << "Дека е празен!!\n";
			while (pop_l(num, left, right))
				std::cout << num << "  ";
			break;
		}
		case 4:
		{
			if (right == NULL)
				std::cout << "Дека е празен!!\n";
			while (pop_r(num, left, right))
				std::cout << num << "   ";
			break;
		}
		case 5: case5(num, left, right, bonus1, bonus2);
			break;
		}
	} while (ch != 6);
	return 0;
}