//CPP:userdevs/elevatordevs/src/lib/linkedlist.cpp
//CPP:userdevs/elevatordevs/src/tablero.cpp
#if !defined tablero_h
#define tablero_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "lib/linkedlist.h"


class tablero: public Simulator { 
// Declare the state,
// output variables
// and parameters

#define INF 1e20;

/* Messages numeration
0 arriba
1 abajo
2 parar 
3 libre
4 ocupado
5 arribaParar
6 abajoParar
*/

//State
LinkedList *ps;
int msj;
double sigma;

public:
	tablero(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
