#include <numeric>
#include <iostream>
#include <list>
#include <ranges>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
void square_numbers(int n) {
	
	int count = 0;
	vector<int> numbers = {};
	int a[100];
	
	//	iota(a, a + 1, 1);
	auto results = numbers | views::filter([](int n) {return n % 2 == 0; });
	//int root = sqrt(n) + 1;
	//int a[10];
	//iota(a, a + 10, root);
	//for (int i : a)
		//cout << i*i << endl;
}

int main() {
	square_numbers(200);
	return 1;
}