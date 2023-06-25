#include <iostream>
using namespace std;
//String zurückgeben anstelle der Adresse, an der der String steht. Denn außerhalb
//der Funktion ist das Ergebnis nicht sichtbar -> Variable is außerhalb der Funktion out of scope. Kein Zugriff über Adresse möglich
string strToUpper(const string& s1)
{

	string s2;
	s2 = " ";

	for (int i = 0; i < s1.length(); i++)

		s2 += toupper(s1[i]);

	return s2;

}
//2. Möglichkeit: den String global machen (durch static), dadurch ist das Ergebnis der Funktion auch von außen Sichtbar und ein zZugriff über die zurückgegebene Adresse kann erfolgen
string& strToUpper2(const string& s1)
{
	
	static string s2;
	s2 = " ";

	for (int i = 0; i < s1.length(); i++)

		s2 += toupper(s1[i]);

	return s2;

}

int main() {
	string input = "test";
	cout << strToUpper(input) << endl;
	cout << strToUpper2(input) << endl;
}