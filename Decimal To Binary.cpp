#include <iostream>
using namespace std;
int decimal(int a);
void main(){
	setlocale(LC_ALL, "bulgarian");
	int a;
	cout << "�������� ��������� �����,��-������ �� 0" << endl;
	do{
		cin >> a;
		if (a < 0){ cout << "�������� ����������� ����� ��� 0 " << endl; }
	} while (a < 0);
	cout<<"�������: "<<a<<" � ����� �� "<<decimal(a)<<" � ������� ������ �������."<<endl;
	system("pause");
}
int decimal(int a){
	if (a == 0)
		return 0;
	else
		return (a % 2 +10*(decimal (a / 2)));
}