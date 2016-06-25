//CPP:userdevs/elevatordevs/src/elevatorFloor.cpp
//CPP:userdevs/elevatordevs/src/ascensor.cpp
#if !defined ascensor_h
#define ascensor_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "elevatorFloor.h"


class ascensor: public Simulator { 
// Declare the state,
// output variables
// and parameters

#define INF 	1e20;
double vc,altPiso;

//State
int est;
double h,sigma;


int est2;
double h2, sigma2;

/*
0 arriba
1 abajo
2 parar 
3 arribaParar
4 abajoParar
*/


public:
	ascensor(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
