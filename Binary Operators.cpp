#include <iostream>
#include <locale>

using namespace std;

void first(){
	unsigned int x = 13;
	unsigned int n = 3;
	if ((x&(1 << n)) != 0)
	{ cout << "Бита е 1 !"; }
	else{
		cout << "Бита е 0 !";
	}
	cout << endl<<endl;
}

void second(){
	unsigned int x = 13;
	unsigned int y = 1;
	unsigned int z;
	if ((x&( 1<<y)) == 0){
		cout << "Бита е 0 !";
		z = x | (1 << y);
	
		cout << endl << "Новото число е : "<<z << endl<<endl;
	}
	else
		cout << "Бита е 1 !"<<endl<<endl;
}

void third(){
	unsigned int x = 13;
	unsigned int y = 2;
	unsigned int z;

	if ((x&(1 << y)) != 0){
		cout << "Бита е 1 !";
		z = x &~(1 << y);
		cout << endl <<"Новото число е : "<< z << endl<<endl;
	}
	else
		cout << "Бита е 0 !" << endl<<endl;
}

void fourth(){
	unsigned int x = 15;
	unsigned int y = 2;
	unsigned int z;
	z = x ^ (1 << y);
	cout << "Новото число е : "<<z;
}

void main(){

	setlocale(LC_ALL, "Bulgarian");
	cout << "Проверка дали n-тия бит е единица:" << endl;
	first();
	cout << "Установяване на n-тия бит в единица:" << endl;
	second();
	cout << "Установяване на n-тия бит в нула:" << endl;
	third();
	cout << "Инвертиране на n-тия бит:" << endl;
	fourth();
	cout << endl<<endl;

	system("pause");
}
