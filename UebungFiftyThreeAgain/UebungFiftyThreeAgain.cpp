#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> search_mod(const vector<int>& numbers, unsigned m) {
	auto mod = [m](int a)->bool { return a % m == 0; };
	vector<int> numbersCopy = vector<int>();
	copy(numbers.begin(), numbers.end(), back_inserter(numbersCopy));
	vector<int> result = vector<int>();
	for (auto& temp : numbersCopy)
		cout << temp << " ";
	vector<int>::iterator iter;
	iter = numbersCopy.begin();
	while(iter != numbersCopy.end()) {
		iter++;
		iter = find_if(iter, numbersCopy.end(), mod);
		if (iter != numbersCopy.end())
			result.push_back(*iter);
		
	}
	
	
	

		
	return result;
}


int main() {
	vector<int> ref = vector<int>(100);
	iota(ref.begin(), ref.begin() + 100, 1);
	for (auto& temp : ref)
		cout << temp << " ";

	vector<int> newRes = search_mod(ref, 2);
	for (auto& temp : newRes)
		cout << temp << " ";
	return 1;
}