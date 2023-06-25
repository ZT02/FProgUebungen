#include <stdio.h>
#include <iostream>
using namespace std;
char* c[] =

{

"he dast ga",

"lllt dumm",

"C i",

"dar nich"

};

char** cp[] = { c + 3, c + 2, c + 1, c };

char*** cpp = cp;



int main(void)

{
	// cp[0+1] = c+2 -> "C i"
	printf("%s", **++cpp);

	// cpp -> cp[1-1] = c +3 -> + 1  ->  "he dast ga" + 5 -> "st ga"
	printf("%s", *-- * ++cpp + 5);

	//c+3 -> "ar nich"
	printf("%s", cpp[-2][0] + 2);

	//(c+ 2) +1 -> c +1 = "lllt dumm" +3 = "t dumm"
	printf("%s\n", *(cpp[1] + 1) + 3);

	getchar();

}