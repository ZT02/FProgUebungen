#pragma once
#include <iostream>
using namespace std;
class Person {
private:
	string name;
	string* ptr;
public:

	Person(const string& nm);
	const string& getName() const;
};