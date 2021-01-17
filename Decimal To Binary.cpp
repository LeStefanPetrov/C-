#include <iostream>
using namespace std;
int decimal(int a);
void main(){
	setlocale(LC_ALL, "bulgarian");
	int a;
	cout << "Въведете десетично число,по-голямо от 0" << endl;
	do{
		cin >> a;
		if (a < 0){ cout << "Въведете положително число или 0 " << endl; }
	} while (a < 0);
	cout<<"Числото: "<<a<<" е равно на "<<decimal(a)<<" в двоична бройна система."<<endl;
	system("pause");
}
int decimal(int a){
	if (a == 0)
		return 0;
	else
		return (a % 2 +10*(decimal (a / 2)));
}