#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;
struct students {
	string ime;
	string nomer;
	float srusp;
	int vuzrast;
	int pol;
};
int broi;
const int N = 30;
fstream fp;

void create(struct students per[]);
void sort(struct students per[]);
void main()
{
	int proceed = 0;
	struct students per[N];
	int menu;
	do{
		cout << "1.Zapisvane na studenti" << endl;
		cout << "2.Prezapisvane na dannite za mujete i za jenite" << endl;
		cout << "3.Opredelqne na nai-mladata studentka i podrejdane na dannite" << endl;
		cout << "4.Exit" << endl;
		cout << "Izberi" << endl;
		cin >> menu;

		switch (menu)
		{
		case 1:create(per); break;
		case 2:sort(per); break;
		}
	} while (menu != 4);
	system("pause");


}
void create(struct students per[])
{
	students p;
	cout << endl << "Vuvedete broi studenti (do 30)" << endl;
	do{
		cin >> broi;
	} while (broi < 1 || broi>30);
	ofstream fp;
	fp.open("infile.txt");
	if (!fp)
	{
		cout << endl << "Greshka pri suzdavane na faila" << endl;
		exit(1);
	}
	for (int i = 0; i < broi; i++)
	{
		cout << "Vuvedete dannite za student nomer" << i + 1 << endl;
		cout << "Ime" << endl;
		cin >> per[i].ime;
		cout << "Vuvedete Fakulteten nomer" << endl;
		cin >> per[i].nomer;
		cout << "Vuvedete sreden uspeh" << endl;
		cin >> per[i].srusp;
		cout << "Vuvedete vuzrast" << endl;
		cin >> per[i].vuzrast;
		cout << "Vuvedete pol(1-muj/0-jena)" << endl;
		cin >> per[i].pol;
	}

	fp.write((char*)per, broi*sizeof(students));
	fp.close();
	ifstream fp1;
	fp.open("outfile.txt");
	if (!fp1)
	{
		cout << endl << "Greshka pri suzdavane na faila" << endl;
		exit(1);
	}
	for (int i = 0; i < broi; i++)
	{
		cout << endl << "ime  " << per[i].ime;
		cout << endl << "fnomer  " << per[i].nomer;
		cout << endl << "sreden uspeh  " << per[i].srusp;
		cout << endl << "vuzrast  " << per[i].vuzrast;
		cout << endl << "pol  " << per[i].pol << endl;
	}
	fp.close();
}

void sort(struct students per[])
{
	students p;
	int M[30];
	int F[30];
	int br = 0;
	int num = 0;
	ifstream fp;
	if (!fp)
	{
		cout << endl << "Greshka pri suzdavane na faila" << endl;
		exit(1);
	}
	for (int i = 0; i <broi; i++)
	{
		fp.read((char*)per, sizeof(students));
		if (per[i].pol == 1)
		{
			per[i].pol = M[br++];
		}
		else
		{
			per[i].pol = F[num++];
		}
	}
	cout << "Mujete sa " << br << endl;
	cout << "Jenite sa " << num << endl;
	fp.close();
}

