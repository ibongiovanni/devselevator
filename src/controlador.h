//CPP:userdevs/elevatordevs/src/controlador.cpp
#if !defined controlador_h
#define controlador_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class controlador: public Simulator { 
// Declare the state,
// output variables
// and parameters
#define INF 	1e20;

//State
int dest,piso,msj;
double sigma;

//out
int dest_,piso_,msj_;
double sigma_;

/*
0 arriba
1 abajo
2 parar
3 libre
4 ocupado
*/
public:
	controlador(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
