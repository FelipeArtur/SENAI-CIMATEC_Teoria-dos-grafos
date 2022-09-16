#ifndef _QUEUE_h
#define _QUEUE_h

#include "MYTOOLS.h" // mallocc()

// Vértice de grafo (veja GRAPHlists.h).
#define vertex int

void 
QUEUEinit( int N);

bool 
QUEUEempty( void);

void 
QUEUEput( vertex v);

vertex 
QUEUEget( void);

void 
QUEUEfree( void);

#endif
