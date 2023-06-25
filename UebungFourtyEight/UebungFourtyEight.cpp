#include <iostream>
using namespace std;

template<int n>
class Fakultaet {
public:
	static constexpr int value = n*Fakultaet<n-1>::value;
};

template<>
class Fakultaet<0>
{
public:
	static constexpr int value = 1;


};

int main()
{
	constexpr int x = Fakultaet<6>::value;
	cout << x << endl;
	return 0;
}