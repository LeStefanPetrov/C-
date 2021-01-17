#include <iostream>
#include <string>
#include <locale>

using namespace std;

#define N 30

struct student
{
	string ime;
	string familia;
	long int fn;
	float uspeh;
}*pgr[N],*tmp[N];

void add_record(student[], int *);
void sort_uspeh(student *[], int);
void sort_name(student *pgr[], int num);
void sort_familia(student *pgr[], int num);
void sort_fnomer(student *pgr[], int num);

void add_record(student gr[], int *num){

	int br;
	cout << "����� ������ ������ �� ��������?" << endl;
	cin >> br;

	for (int j = *num; j<*num + br; j++){
		cout << "�������� ������� �� ������� �����: " << j + 1 << endl;
		cout << "������ ���: " << endl;
		cin.ignore();
		getline(cin, gr[j].ime);
		cout << "������ �������: " << endl;
		getline(cin, gr[j].familia);
		cout << "������ ��: " << endl;
		cin >> gr[j].fn;
		cout << "������ �����: " << endl;
		cin >> gr[j].uspeh;
		pgr[j] = &gr[j];
	}
	*num += br;

}
void sort_uspeh(student *pgr[], int num){

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++){
			if (pgr[i]->uspeh<pgr[j]->uspeh)
			{
				tmp[i] = pgr[i];
				pgr[i] = pgr[j];
				pgr[j] = tmp[i];
			}
		}
	}

	cout << "��������� �� �����(��������):" << endl;

	for (int i = 0; i < num; i++){
		cout << "\n���: " << pgr[i]->ime << endl;
		cout << "�������: " << pgr[i]->familia << endl;
		cout << "��: " << pgr[i]->fn << endl;
		cout << "�����: " << pgr[i]->uspeh << endl;
	}

}

void sort_name(student *pgr[], int num)
{

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++){
			if (pgr[i]->ime<pgr[j]->ime)
			{
				tmp[i] = pgr[i];
				pgr[i] = pgr[j];
				pgr[j] = tmp[i];
			}
		}
	}

	cout << "��������� �� ���:" << endl;

	for (int i = 0; i < num; i++){
		cout << "\n���: " << pgr[i]->ime << endl;
		cout << "�������: " << pgr[i]->familia << endl;
		cout << "��: " << pgr[i]->fn << endl;
		cout << "�����: " << pgr[i]->uspeh << endl;
	}
}

void sort_familia(student *pgr[], int num)
{

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++){
			if (pgr[i]->familia<pgr[j]->familia)
			{
				tmp[i] = pgr[i];
				pgr[i] = pgr[j];
				pgr[j] = tmp[i];
			}
		}
	}

	cout << "��������� �� �������:" << endl;

	for (int i = 0; i < num; i++){
		cout << "\n���: " << pgr[i]->ime << endl;
		cout << "�������: " << pgr[i]->familia << endl;
		cout << "��: " << pgr[i]->fn << endl;
		cout << "�����: " << pgr[i]->uspeh << endl;
	}

}

void sort_fnomer(student *pgr[], int num)
{

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++){
			if (pgr[i]->fn<pgr[j]->fn)
			{
				tmp[i] = pgr[i];
				pgr[i] = pgr[j];
				pgr[j] = tmp[i];
			}
		}
	}

	cout << "��������� �� ���������� �����(��������):" << endl;

	for (int i = 0; i < num; i++){
		cout << "\n���: " << pgr[i]->ime << endl;
		cout << "�������: " << pgr[i]->familia << endl;
		cout << "��: " << pgr[i]->fn << endl;
		cout << "�����: " << pgr[i]->uspeh << endl;
	}

}
void main(){

	setlocale(LC_ALL, "bulgarian");
	student gr[N];
	int choice;
	int num = 0;

	do{

		cout << "________________________________________________________________________________" << endl;
		cout << "����" << endl;
		cout << "1. �������� �� ��� �����" << endl;
		cout << "2. ��������� �� ������� �� ���" << endl;
		cout << "3. ��������� �� ������� �� �������" << endl;
		cout << "4. ��������� �� ������� �� ���������� �����" << endl;
		cout << "5. ��������� �� ������� �� �����" << endl;
		cout << "6.�����!" << endl;
		cout << "�������� ����� �����" << endl;
		cout << "________________________________________________________________________________" << endl;

		cin >> choice;

		switch (choice){
		case 1: add_record(gr, &num); break;

		case 2:if (num == NULL)
			cout << "����� � �� �������� �����!" << endl;
			   else sort_name(pgr, num); break;

		case 3:if (num == NULL)
			cout << "����� � �� �������� �����!" << endl;
			   else sort_familia(pgr, num); break;

		case 4:if (num == NULL)
			cout << "����� � �� �������� �����!" << endl;
			   else sort_fnomer(pgr, num); break; break;

		case 5:if (num == NULL)
			cout << "����� � �� �������� �����!" << endl;
			   else sort_uspeh(pgr, num); break;
		}
	} while (choice != 6);

	system("pause");
}
