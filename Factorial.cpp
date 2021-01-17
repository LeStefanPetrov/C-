#include <iostream>
using namespace std;
int factorial(int k){
	if (k > 1)
		return (k*factorial(k - 1));
	else return(1);
}

void main(){
	int k;
	cout << "Vuvedete cqlo chislo " << endl;
	cin >> k;
	cout << endl << k << "!=" << factorial(k) << endl;
	system("pause");q
}