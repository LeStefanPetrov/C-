#include <iostream>
#include <locale>

using namespace std;

void first(){
	unsigned int x = 13;
	unsigned int n = 3;
	if ((x&(1 << n)) != 0)
	{ cout << "���� � 1 !"; }
	else{
		cout << "���� � 0 !";
	}
	cout << endl<<endl;
}

void second(){
	unsigned int x = 13;
	unsigned int y = 1;
	unsigned int z;
	if ((x&( 1<<y)) == 0){
		cout << "���� � 0 !";
		z = x | (1 << y);
	
		cout << endl << "������ ����� � : "<<z << endl<<endl;
	}
	else
		cout << "���� � 1 !"<<endl<<endl;
}

void third(){
	unsigned int x = 13;
	unsigned int y = 2;
	unsigned int z;

	if ((x&(1 << y)) != 0){
		cout << "���� � 1 !";
		z = x &~(1 << y);
		cout << endl <<"������ ����� � : "<< z << endl<<endl;
	}
	else
		cout << "���� � 0 !" << endl<<endl;
}

void fourth(){
	unsigned int x = 15;
	unsigned int y = 2;
	unsigned int z;
	z = x ^ (1 << y);
	cout << "������ ����� � : "<<z;
}

void main(){

	setlocale(LC_ALL, "Bulgarian");
	cout << "�������� ���� n-��� ��� � �������:" << endl;
	first();
	cout << "������������ �� n-��� ��� � �������:" << endl;
	second();
	cout << "������������ �� n-��� ��� � ����:" << endl;
	third();
	cout << "����������� �� n-��� ���:" << endl;
	fourth();
	cout << endl<<endl;

	system("pause");
}
