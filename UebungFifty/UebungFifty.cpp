#include <iostream>
#include <vector>
using namespace std;

int main() {
	string einlesen;
	vector<string> behaelter;
	vector<string>::iterator iter = behaelter.begin();
	for (int i = 0; i < 10; i++) {
		cin >> einlesen;
		
		iter = find(behaelter.begin(), behaelter.end(), einlesen);
		if (iter != behaelter.end())
		{
			cout << "Element: " << einlesen << " bereits vorhanden.";
		}
		else
			behaelter.push_back(einlesen);
	}


	return 1;
}