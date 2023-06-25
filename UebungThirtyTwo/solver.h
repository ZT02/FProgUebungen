/* Datei: solver.h */
#define DIM 100
extern int errcode;
#ifdef INLINE
#define getSourceFilename() FILENAME
#endif
#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED
// ...
int solver(double[][DIM], int);
//...
#endif

