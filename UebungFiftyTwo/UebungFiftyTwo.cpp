#include <string>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
class Person {
private:

	string name;
public:

	Person(const string& nm) : name(nm) {

	}
	const string& getName() const {
		return name;
	}
};

class Kontakte {
private:
	list<Person*> people;

public:
	Kontakte(list<Person*> temp) : people(temp) {}

	~Kontakte() {
		for (Person* p : people) {
			delete p;
		}
	}
	void printAll() {
		list<Person*>::iterator iter;
		for (iter = people.begin();iter != people.end(); iter++) {
			cout << (*iter)->getName() << endl;
		}
		//for (auto& p : people)
			//cout << p << endl;
	}

	Person* contains(string search) {
		list<Person*>::iterator iter;
		iter = find_if(people.begin(), people.end(), [&search](const Person* a) {
			//Substring
			return strstr(a->getName().c_str(), search.c_str());
			//return a->getName().find(search, 0) != string::npos;
		
			});
		return (*iter);
	}
};



int main() {
	Person* a = new Person("Jakob Görtel");
	Person* b = new Person("Markus Leistner");
	Person* c = new Person("Ngoc Pham");

	list<Person*> people{ a, b, c };
	Kontakte test(people);
	test.printAll();
	cout << test.contains("Markus")->getName();
	
	return 1;
}