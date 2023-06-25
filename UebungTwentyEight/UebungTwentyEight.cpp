#include <iostream>
using namespace std;
//String zur�ckgeben anstelle der Adresse, an der der String steht. Denn au�erhalb
//der Funktion ist das Ergebnis nicht sichtbar -> Variable is au�erhalb der Funktion out of scope. Kein Zugriff �ber Adresse m�glich
string strToUpper(const string& s1)
{

	string s2;
	s2 = " ";

	for (int i = 0; i < s1.length(); i++)

		s2 += toupper(s1[i]);

	return s2;

}
//2. M�glichkeit: den String global machen (durch static), dadurch ist das Ergebnis der Funktion auch von au�en Sichtbar und ein zZugriff �ber die zur�ckgegebene Adresse kann erfolgen
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