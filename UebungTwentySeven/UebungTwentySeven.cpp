#include <iostream>
using namespace std;
void strcpy1(char* s, char* t)
{
	int i = 0;
	while (t[i] = s[i])
		i++;
}

void strcpy2(char* s, char* t)
{
	while (*t = *s)
	{
		s++;
		t++;
	}
}

int main() {
	char input[5] = "test";
	char output[5];
	strcpy1(input, output);
	cout << output << endl;
	return 0;
}