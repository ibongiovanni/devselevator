//CPP:userdevs/elevatordevs/src/lib/linkedlist.cpp
//CPP:userdevs/elevatordevs/src/comparador.cpp
#if !defined comparador_h
#define comparador_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "lib/linkedlist.h"


class comparador: public Simulator { 
// Declare the state,
// output variables
// and parameters
#define INF 1e20;

//Tiempo de cada sistema
Node *ts1;
Node *ts2;
double sigma;

Node *out;
public:
	comparador(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
