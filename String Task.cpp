#include <iostream>
using namespace std;

void main(){
	char str[30];
	char *point;
	int br = 0;
	char letter;
	char *point2;
	cout << "Enter a string!" << endl;
	cin.getline(str, sizeof(str));
	cout << "Enter a letter" << endl;
	cin >> letter;
	cout << "Looking for the letter "<<letter<<" in "<<str<<endl;
	point = strchr(str, letter);
	while (point != NULL)
	{
		cout << "Found the letter "<<letter<<" in " << point-str + 1 << endl;
		point = strchr(point + 1, letter);
		br++;
	}
	point2 = strrchr(str, letter);
	cout << "The last appear of the letter " << letter;
	cout<< " is at " << point2 - str + 1 << " character" << endl;
	cout << "The letter "<<letter<<" is found " << br << " times"<<endl;
	system("pause");
}