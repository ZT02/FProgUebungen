#include <iostream>
#include <list>
using namespace std;

int main() {
	list<string>* container = new list<string>();
	list<string>::iterator iter;
	int counter = 5;
	int i = 0;
	while (i < 5) {
		bool check = true;
			string temp;
			cin >> temp;


			for (iter = container->begin(); iter != container->end(); iter++) {
				if (*iter == temp)
					check = false;

			}
		
			if (check) {
				container->push_back(temp);
				i++;
		}

			else {
				cout << "Element: " << temp << " bereits vorhanden, erneuter Versuch!" << endl;
			}
	}
	


	
	delete container;
	return 0;
}