//CPP:userdevs/elevatordevs/src/dist.cpp
#if !defined dist_h
#define dist_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class dist: public Simulator { 
// Declare the state,
// output variables
// and parameters

#define INF 1e20;

double sigma;
int p;
int turn;

int out;
public:
	dist(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
