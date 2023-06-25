/* Datei: solver.cpp */
#include <iostream>
#include "solver.h"
#define FILENAME "solver.cpp"
#ifndef INLINE

static const char* getSourceFilename() {
    return "solver.cpp";
}
#endif
using namespace std;
// ...

int errcode = 0;

int solver(double m[][DIM], int n) {
    cout << getSourceFilename() << ": Function solver called.\n";
    if (n > DIM)
        errcode = 3;
    /* . . . */
    return 0;
}