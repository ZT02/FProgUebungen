int i;
unsigned int ui;
char cFeld[20];
int iFeld[20];
//1
template<typename T>
T f(T* t, int i) { /* ...*/ }
//2
template<typename T>
T f(T s, T t) { /* ...*/ }
//3
template<>
char f(char* s, int i) { /* ... */ }
//4
template<>
double f(double x, double y) { /* ... */ }

/*
	f(cFeld, 20) Funktioniert: 3 haben das passende Template
	f(iFeld, 20) Funktioniert: 1 passende Template
	f(iFeld[0], i) 2
	f(i, ui) 2
	f(iFeld, ui) 1
	f(&i, i) 1
*/

