//CPP:userdevs/int2float.cpp
#if !defined int2float_h
#define int2float_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class int2float: public Simulator { 
// Declare the state,
// output variables
// and parameters
#define INF 1e20;

int in;
double sigma;

double out;
public:
	int2float(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
