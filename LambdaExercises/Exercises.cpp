#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
using namespace std;
class Person {
public:
	Person() {

	}
	int getAge() {
		return 1;
	 }
	 int getint() {
		return 5;
	}

};
class Child : public Person {
private:
	Person test;
public:
	Child() : Person() {

	}

};

class CMulti
{
protected:
	int z1; int z2;
public:
	CMulti(int _z1, int _z2) :
		z1(_z1), z2(_z2) { }
	virtual int rechne() {
		return z1 * z2;
	}
};
class CAdd : public CMulti
{
public:
	CAdd(int _z1, int _z2) :
		CMulti(_z1, _z2) { }
	// Neue Funktionalität
	int rechne() { return z1 + z2; }
};
int main() {
	
		CMulti* zeiger;
		CAdd einObjekt(7, 9);
		zeiger = &einObjekt;
		cout << "Die Rechenoperation mit den im"
			"Objekt gespeicherten Zahlen ergibt: "
			<< zeiger->rechne() << endl;
		cin.get();
		return 0;
	
	vector<int>test = {3, 3, 3, 3 ,3, 3};

	/*for (auto& k : test) {
		k = 4;
	}
	cout << test.size();
	for (int k : test) {
		cout << k << endl;
	} */
	
	vector<int>::iterator iter;
	for (iter = test.begin(); iter != test.end(); iter++) {
		cout << *iter << endl;
	}
	vector<int> l2;
	back_inserter(test);
	copy(test.begin(), test.end(), back_inserter(l2));
	replace(l2.begin(), l2.end(), 3, 99);
	
	for (iter = l2.begin(); iter != l2.end(); iter++) {
		cout << *iter << endl;
	}
	ranges::sort(test);

	Person testclass;
	testclass.getAge();
	Person* toUp = new Child();
	Child* testcl = new Child();
	cout << typeid(testcl).name();
	Person* result = dynamic_cast<Person*>(testcl);
	cout << typeid(testcl).name();
	cout << typeid(result).name();
/*
	double testetst = 1.0e8;
	cout << testetst;

	vector<int>* test = new vector<int>{ 1, 3, 5, 6, 7, 7, 3, 2, 10, 9 };
	auto lam = [](int a, int b) {
		return a > b;
	};

	auto count_even = [](int i) {
		return !(i % 2);
	};
	*/
//	int a = 2;
	//addiert auf alle Zahlen 2 im vektor, Referenz ist wichtig, da diese ref auf die Elemente zeigt
	//Schreib- und Lesezugriff anschauen
//	auto changeV = [a](int& ptr) {ptr += a; };
	// auto result = for_each(test->begin(), test->end(), changeV);
	// cout << test;
	//3 5 7 8 9 9 5 4 12 11
	
	//zählt gerade zahlen
//	int i = count_if(test->begin(),test->end(), count_even);
//	cout << i  << endl;
	//3

	//sortiert vector absteigend
//	sort(test->begin(), test->end(), lam);
//	cout << test; 
	//12 11 9 9 8 7 5 5 4 3

}

