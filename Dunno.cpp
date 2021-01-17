#include <iostream>
using namespace std;
int main(){
	double a[5][5];
	double b[25];
	int br(0);
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[i][j] >= -100 && a[i][j]<=100 && a[i][j] != 0)
			{
				b[br] = a[i][j];
				br++;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < br; i++){
		cout << b[i]<<endl;

	}


	system("pause");
	return 0;
}