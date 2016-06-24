//CPP:userdevs/elevatordevs/src/tablero.cpp
#if !defined tablero_h
#define tablero_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class tablero: public Simulator { 
// Declare the state,
// output variables
// and parameters

//State

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
