#include <vector>
#include <iostream>
using namespace std;

vector<int> search_mod(const vector<int>& numbers, unsigned m) {
	vector<int> result;
	
	auto mod = [&m](int i) { return !(i % m); };
	
	auto iter = find_if(numbers.begin(), numbers.end(), mod);
	
	while (iter != numbers.end()) {
		iter = find_if(iter, numbers.end(), mod);
		result.push_back(*iter);
		iter++;
	}

	return result;
}

int main() {
	vector<int> test;
	for (int i = 1; i <= 100; i++)
		test.push_back(i);

	vector<int> result  = search_mod(test, 2);
	for (auto& r : result)
		cout << r << endl;
	return 0;
}