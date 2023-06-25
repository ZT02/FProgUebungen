#include <iostream>
#include <set>
#include <stdlib.h>
using namespace std;


int main() {
	srand(time(0));
	set<int>* lottozahlen = new set<int>();
	set<int>::iterator iter; //Ist  ein Zeiger
	while (lottozahlen->size() < 7) {
		lottozahlen->insert(rand() % 49 + 1);
	}
	
	cout << "Lottozahlen: " << endl;
	for (iter = lottozahlen->begin(); iter != lottozahlen->end(); iter++)
		cout << *iter << " ";
	
	delete lottozahlen;
	return 1;
}