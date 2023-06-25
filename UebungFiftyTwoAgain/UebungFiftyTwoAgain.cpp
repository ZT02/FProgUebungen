#include "Header.h"
#include <list>
using namespace std;

Person::Person(const string& nm) : name(nm) {}
const string& Person::getName() const {
	return name;
}

class Kontakte {
private:
	list<Person*>* contacts =new list<Person*>();
	
public:
	void insertEl(Person* a) {
		if(a != nullptr)
		contacts->push_back(a);
	}

	void printAll() {
		
		for (const Person* temp : *contacts)
			cout<< temp->getName() << endl; 
		
		/*list<Person*>::iterator iter;
		for (iter = contacts->begin(); iter != contacts->end(); iter++) {
			cout << (*iter)->getName() << endl;
		} */
	}
	;;;;;;;;;
	bool contains(string s) {
		 list<Person*>::iterator check = find_if(contacts->begin(), contacts->end(), [s](Person* b) {  return b->getName().find(s) != string::npos; });
		 if (check == contacts->end())
			 return false;
		 else
			 return true;
	}

};









int main() {
	Person* test1 = new Person("Markus Leistner");
	Person* test2 = new Person("Chanel");
	Person* test3 = new Person("Pizza Bob");
	Person* test4 = new Person("Ngoc Thi Pham");
	Kontakte newKon = Kontakte();
	newKon.insertEl(test1);
	newKon.insertEl(test2);
	newKon.insertEl(test3);
	newKon.insertEl(test4);
	newKon.printAll();
	cout << newKon.contains("Pham") << endl;
	
	return 1;
}