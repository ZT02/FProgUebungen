#include <iostream>

using namespace std;

const int LEN = 32;
typedef struct Foo
{
	char* ding;
	char* dong;
};

char* f1(void)
{
	char carray[LEN];
	carray[0] = 'a';
	return carray;
} // #1: Zeiger auf lokales Stack-Array wird zurückgegeben

char* f2(void)
{
	char* cp;
	int i = LEN;
	cp = new char[i];
	while (i) cp[i--] = '\0'; // #2: i ist um 1 zu groß und greift hinter das Array
	return cp;
}

char* f3()
{
	return new char[1024];
}

int main(void)
{
	char* cp1;
	char* cp2;
	char* cp3;
	struct Foo* f;
	f = new Foo();
	f->ding = new char[128];
	f->dong = new char[128];
	cp1 = f1();
	cp1[0] = 0x01;  // #3: cp1 ist hier nicht mehr gültig
	cp2 = f2();     // #4: cp2 wird anschließend nicht mehr freigegeben
	cp3 = f3();
	cp3 = nullptr;  // #5: Speicher aus cp3 wird durch Umsetzung des Zeiger verwaist
	delete f;       // #6: Freigabe von ding und dong fehlen 
	delete[] cp3;   // #7: cp3 zeigt nicht mehr auf den angelegten Speicher
	return 0;
}