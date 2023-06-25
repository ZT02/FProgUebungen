#include<iostream>
#include<vector>
using namespace std;

class box {
public:
	box() {
		cout << "Initialisierung" << endl;
	}

	~box() {
		cout << "Aufraeumen" << endl;
	}
}w;

int main()
{
	std::cout << "Hello World!" << std::endl;
}
//Initialisierung
//Hello World
//Aufraeumen

template<typename Typ, typename Container = vector<Typ>>
class Behaelter {
	Container m_container;
public:
	Behaelter() {
		typename Container::size_type size = 0;
		typename Container::size_type* ptr = &size;
		typename Container::size_type pizza = 1;
	}
};
int main() {
	int x = 0;
	int* ptr = &x;
	*ptr = 5;
	
}