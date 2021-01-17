#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <exception>
#include <istream>
using namespace std;

class CStudentEmploy {
private:
	string m_strName;
	string m_strFacNum;
	int m_iMinutes;
public:
	CStudentEmploy() {
	}
	CStudentEmploy(string strname, string strfacnum, int minutes) {
		m_strName = strname;
		m_strFacNum = strfacnum;
		m_iMinutes = minutes;
	}
	CStudentEmploy(const CStudentEmploy &obj) {
		m_strName = obj.m_strName;
		m_strFacNum = obj.m_strFacNum;
		m_iMinutes = obj.m_iMinutes;
	}
	int get_m_iMinutes() {
		return m_iMinutes;
	}
	CStudentEmploy operator =(const CStudentEmploy &obj) {
		this->m_strName = obj.m_strName;
		this->m_strFacNum = obj.m_strFacNum;
		this->m_iMinutes = obj.m_iMinutes;
		return *this;
	}
	bool operator <(const CStudentEmploy &obj) const {
		return m_iMinutes < obj.m_iMinutes;
	}
	CStudentEmploy operator +(const CStudentEmploy &obj) {
		this->m_iMinutes += obj.m_iMinutes;
		return *this;
	}
	friend ostream& operator << (ostream& str, const CStudentEmploy &obj)
	{
		str << "\nИме: " << obj.m_strName << "\nФакултетен Номер: " << obj.m_strFacNum << "\nМинути: " << obj.m_iMinutes << endl;
		return str;
	}
	friend istream& operator >> (istream& str, CStudentEmploy* &obj)
	{
		obj = new CStudentEmploy();
		str >> obj->m_strName >> obj->m_strFacNum >> obj->m_iMinutes;
		return str;
	}
};
class StudentComparer {
public:
	bool operator() (CStudentEmploy *lhs, CStudentEmploy *rhs) {
		return *lhs < *rhs;
	}
};
class CAnalizeData {
private:
	vector<CStudentEmploy*>m_vData;
public:
	//Конструктор с име на файл
	CAnalizeData(const string &strFileName) {
		ifstream ifile(strFileName);
		copy(istream_iterator<CStudentEmploy*>(ifile), istream_iterator<CStudentEmploy*>(), back_inserter(m_vData));
	}
	//Сортиране по минути
	void Sort() {
		sort(m_vData.begin(), m_vData.end(), StudentComparer());
	}
	//Изчислява средна стойност
	double calcMean() {
		double avg = 0;
		vector<CStudentEmploy*>::iterator it = m_vData.begin();
		for (it = m_vData.begin(); it != m_vData.end(); it++) {
			avg += (*it)->get_m_iMinutes();
		}
		return avg / m_vData.size();
	}
	//Изчислява ветор от брой студенти по зададени 6 граници
	vector<int>calcNums(int iR1, int iR2, int iR3, int iR4, int iR5, int iR6) {
		int a=0, b=0, c=0, d=0, e=0;
		vector<CStudentEmploy*>::iterator it = m_vData.begin();
		for (it = m_vData.begin(); it != m_vData.end(); it++) {
			if ((*it)->get_m_iMinutes()> iR1&& (*it)->get_m_iMinutes()<= iR2) { a++; }
			if ((*it)->get_m_iMinutes()> iR2&& (*it)->get_m_iMinutes()<= iR3) { b++; }
			if ((*it)->get_m_iMinutes()> iR3&& (*it)->get_m_iMinutes()<= iR4) { c++; }
			if ((*it)->get_m_iMinutes()> iR4&& (*it)->get_m_iMinutes()<= iR5) { d++; }
			if ((*it)->get_m_iMinutes()> iR5&& (*it)->get_m_iMinutes()<= iR6) { e++; }		
		}
		vector<int> calc{ a,b,c,d,e,iR1,iR2,iR3,iR4,iR5,iR6 };
		return calc;
	}
	//Оператор <<(извежда в указан изходен поток)
	friend ostream& operator << (ostream& str, CAnalizeData &obj)
	{
		for (int i = 0; i < obj.m_vData.size(); i++)
		{
			str << "-------------------"<<endl<<"Обект " <<"№ "<<i+1<<":" << endl;
			CStudentEmploy* emp = obj.m_vData[i];
			str << *emp << endl;
		}
		return str;
	}
	//Изчислява вектор,съдържащ вектори от студенти по зададени  6 граници
	vector<vector<CStudentEmploy*>>calcNums2(int iR1, int iR2, int iR3, int iR4, int iR5, int iR6) {
		vector<CStudentEmploy*>a,b,c,d,e;
		for (int i = 0; i < m_vData.size(); i++) {
			if (((m_vData[i]->get_m_iMinutes() > iR1) && (m_vData[i]->get_m_iMinutes() <= iR2))) { a.push_back(m_vData[i]);}
			if (((m_vData[i]->get_m_iMinutes() > iR2) && (m_vData[i]->get_m_iMinutes() <= iR3))) { b.push_back(m_vData[i]);}
			if (((m_vData[i]->get_m_iMinutes() > iR3) && (m_vData[i]->get_m_iMinutes() <= iR4))) { c.push_back(m_vData[i]);}
			if (((m_vData[i]->get_m_iMinutes() > iR4) && (m_vData[i]->get_m_iMinutes() <= iR5))) { d.push_back(m_vData[i]);}
			if (((m_vData[i]->get_m_iMinutes() > iR5) && (m_vData[i]->get_m_iMinutes() <= iR6))) { e.push_back(m_vData[i]);}
		}
		vector<vector<CStudentEmploy*>>AA { a,b,c,d,e};
		return AA;
	}
};
void main() {
	try {
		vector<int>borders = { 20,35,50,65,80,120 };
		//Извеждане на обектите от файл
		setlocale(LC_ALL, "Bulgarian");
		CAnalizeData AB("Test.txt");
		AB.Sort();
		cout << AB << endl;
		cout << "-------------------" << endl;
		//Извеждане броя на студентите по зададени граници
		vector<int> vect = AB.calcNums(borders[0], borders[1], borders[2], borders[3], borders[4], borders[5]);
		vector<int>::iterator itt = vect.begin() + 5;
		for (vector<int>::iterator it = vect.begin(); it != vect.end() - 6; ++it)
		{
			cout << "[" << *it << "]" << "{" << *itt << "-";
			itt++;
			cout << *itt << "}" << endl;
		}
		cout << "-------------------";
		cout << endl << endl;
		//Извеждане на информацията за студентите по задад
		vector<vector<CStudentEmploy*>>AAA = AB.calcNums2(borders[0], borders[1], borders[2], borders[3], borders[4], borders[5]);
		for (int i = 0; i < AAA.size(); i++)
		{
			cout << "Студенти в границата {" << borders[i]+1 << "-" << borders[i + 1] << "} :" << endl;
			for (vector<CStudentEmploy*>::iterator it = AAA[i].begin(); it != AAA[i].end(); it++) {
				cout << **it << endl;
				cout << "-------------------" << endl;
			}
		}
		//Изчисляване на средните минути 
		cout << endl;
		cout << "Средни минути на студент:" << AB.calcMean() << endl << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	system("pause");
}