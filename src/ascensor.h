//CPP:userdevs/elevatordevs/src/ascensor.cpp
#if !defined ascensor_h
#define ascensor_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class ascensor: public Simulator { 
// Declare the state,
// output variables
// and parameters

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
