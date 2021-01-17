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

void case5(int &n, elem *left, elem *right, elem *bonus1, elem*bonus2)
{
	int a;
	if (left == NULL){
		std::cout << "Дека е празен!!\n";
	}
	else{
		std::cout << "\nИзтриване на елементите кратни на 'К'." << std::endl;
		std::cout << "К= ";
		std::cin >> a;
		std::cout << std::endl << "Елементите, които не са кратни на К са: ";
		while (pop_l(n, left, right))
			if (n%a != 0){
				push_l(n, bonus1, bonus2);
				while (pop_l(n, bonus1, bonus2))
					std::cout << n << " ";
			}
	}
}

void main()
{
	int num, br = 0;
	setlocale(LC_ALL, "bulgarian");
	do{
		std::cout << "Колко числа искате да въведете? (положителна стойност)" << std::endl;
		std::cin >> br;
	} while (br <= 0);
	for (int i = 0; i<br; i++){
		std::cout << "\nВъведете число: ";
		std::cin >> num;
		push_l(num, left, right);
	}


	case5(num, left, right, bonus1, bonus2);
	std::cout << std::endl;
	system("pause");
}