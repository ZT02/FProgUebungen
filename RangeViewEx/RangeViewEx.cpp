#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <ranges>
using namespace std;

class Lehrer {


};

class Person {
public:
	string name;
	string* ptr;
public:
	Person(string name, string nachname) : name(name), ptr(nullptr) {
		ptr = new string(nachname);
	}

	Person(const Person& another) : name(another.name) {
		cout << "Copyconstructor called" << endl;
		ptr = new string;
		*ptr = (*another.ptr);
	}
	friend class Lehrer;
	Person& operator= (Person&& another) {
		if (this != &another) {
			name = another.name;
			another.name = "empty";
			delete ptr;
			*ptr = *(another.ptr);
			another.ptr = nullptr;
			
		}
		return *this;
	}

	const string& getName() const {
		static string s = *ptr + name;
		return s;
	}

	Person(Person&& another) {
		name = another.name;
		another.name = "empty";
		delete ptr;
		*ptr = *(another.ptr);
		another.ptr = nullptr;


	}
};



int main() {
	Person test1("Markus", "Leistner");
	Person test2 = test1;
	*(test1.ptr) = "Chantal";
	cout << test2.getName();

	int array[6];
	iota(array, array + 6, 1);
	int test4[] = {1,2, 6, 4, 8, 7, 9, 14, 13, 3};
	auto lambdaF = [](int& c) { return c + 1; };
	auto res32 = ranges::for_each(test4, [](int& c) { ++c; });

	for (auto k : test4)
		cout << k;

	int s[] = { 1, 2, 3 };
	
	int Uppercase = 0; //wird vom Lambda-Ausdruck geändert
	auto ks = for_each(s, s+4, lambdaF);

	for (auto k : s)
		cout << k<< endl ;

	array[0] = 7;
	ranges::sort(array);

	for (int& a : array)
		cout << a << endl;
	/*vector<int> test2 = {1,2, 6, 4, 8, 7, 9, 14, 13, 3};
	//vector<int> test3 = vector<int>(test2.size());
	//ranges::copy_if(test2.begin(), test2.end(),
		test3.begin(), [&](int a) {return a % 2 != true; });
	ranges::replace_if(test3, [](int i) {return i % 1 == 0; }, 4);
	int n = ranges::count_if(test3, [](int a) {return a == 4; });
	cout << "Anzahl an 4en: " << n << endl;
	for (int& a : test3)
		cout << a << endl;

	cout << "----------" << endl;
	auto result = test2 | views::filter([](int a) {return a % 2 != true; }) | views::take(3) | views::drop(1) | views::transform([](int b) {return b * 2; });

	*/
	
	
	//for (auto k : result)
		//cout << k << endl;

	
	return 1;
}