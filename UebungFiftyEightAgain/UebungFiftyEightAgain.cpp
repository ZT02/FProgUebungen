#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
class Check {
private:
	string saveString;
public:
	Check(string s) : saveString(s) {

	}
	bool operator()(string s) {
		return s.find(saveString) != string::npos;
	}
};
int search(deque<string>& subs, const string& s) {
	int counter = 0;
	Check temp = Check(s);
	for_each(subs.begin(), subs.end(), [&](string t) {

		if (temp(t))
		counter++;
		
		});
	return counter;
}



int main()
{
	deque<string> subjects;
	subjects.push_back("Deutsch");
	subjects.push_back("Mathematik");
	subjects.push_back("Englisch");
	subjects.push_back("Religion");
	subjects.push_back("Sport");
	subjects.push_back("Musik");

	cout << "Fächer: ";
	for (auto s : subjects)
		cout << s << ", ";

	cout << endl;
	cout << "Darin kommt \"li\" " << search(subjects, "li") << " mal vor." << endl;

	cout << "Darin kommt \"ik\" " << search(subjects, "ik") << " mal vor." << endl;

	return 0;
}