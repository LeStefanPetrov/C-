#include <iostream>
using namespace std;
void first(){
	unsigned int a, b, c;
	a = 13;
	b = 5;
	c = a&b;
	cout << c << "=";
	c = (a | b);
	cout << c << "=";
	c = a^b;
	cout << c << "=";
	unsigned short d = ~4;
	//1101
	//0101
	//1000
}
void second(){
	unsigned int aa = 10;
	unsigned int aaa, aaaa;
	aaa = aa << 2;
	aaaa = aa >> 1;
	cout << endl << aaa << endl << aaaa;
	cout << endl;
}
void third(){
	unsigned int bb=4,bbb;
	bbb = bb&(bb - 1);
	cout << endl << "tova e bbb: " << bbb << endl;
	//100
	//011
	
}
void forth(){
	int x = 5;
	int cc=(x << 3) - x;
	cout << "Umnojeno po 7: "<< cc << endl;
}
void fifth(){
	int xx = 11, yy = 22;
	xx = xx^yy;
	yy = xx^yy;
	xx = xx^yy;
	cout << "After swap:" << endl;
	cout << "XX e:" << xx << endl;
	cout << "YY e:" << yy << endl;
}
void sixth(){
	int prim = 15 & 3;
	int primm = 15 | 3;
	int primmmm = 5 ^ 12;
	unsigned short prin = ~4;
	
	// 1111
	// 0100
	// 1011
	cout <<endl<<"prim: "<< prim;
	cout << endl << "primm: " << primm;
	cout << endl << "primmm: " << primmmm;
	cout << endl << "prin: " << prin;
	cout << endl;
}
void seventh(){
	int z =3;
	int y =3;
	//100
	//011
	//111
	cout << endl;
	if ((z^y) >0){
		cout << "imat protivopolojni znaci";
	}

	if ((z^y)==0){ cout << "imat ednakvi znaci"; }
}
void eighth(){
	int a=13;
	if ((a & 1) == 0){
		cout << endl << "chisloto e chetno";
	}
	else{ cout << endl << "chisloto e nechetno"; }
	cout << endl;
}
void main(){
	first();
	second();
	third();
	forth();
	fifth();
	sixth();
	seventh();
	eighth();
	system("pause");
}

// 0101
// 1100
//