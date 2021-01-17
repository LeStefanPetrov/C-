#include <iostream>
#include <conio.h>
using namespace std;
const int N(4);
const int wmax(7);
int weight[] = { 1, 3, 4, 5 };
int value[] = { 1, 4, 5, 7 };
int T[N + 1][wmax + 1];
int mvalue(int a, int b)
{
	return (a > b) ? a : b;
}
void printt(int T[N + 1][wmax + 1])
{
	for (int i = 0; i < N + 1; i++)
	{
		for (int w = 0; w <= wmax; w++)
		{
			cout << T[i][w] << "\t";
		}
		cout << endl;
	}
}
int main()
{
	for (int i = 0; i <= N; i++)
	{
		for (int w = 0; w <= wmax; w++)
		{
			if (w == 0 || i == 0)
			{
				T[i][w] = 0;
			}
			else if (weight[i - 1] > w)
			{
				T[i][w] = T[i - 1][w];
			}
			else
			{
				T[i][w] = mvalue(value[i - 1] + T[i - 1][w - weight[i - 1]], T[i - 1][w]);
			}
		}
	}
	printt(T);
	int n = N, w = wmax, total_weight = 0;
	while (n>0)
	{
		if (T[n][w] > T[n - 1][w])
		{
			cout << "Item with " << weight[n - 1] << " kg and value = " << value[n - 1] << endl;
			total_weight += weight[n - 1];
			w -= weight[n - 1];
		}
		n--;
	}
	cout << "Total weight = " << total_weight << "  with total value " << T[N][wmax] << endl;
	_getch();
}