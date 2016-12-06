//CPP:userdevs/elevatordevs/src/dist.cpp
//CPP:userdevs/elevatordevs/src/dist2.cpp
#if !defined dist2_h
#define dist2_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class dist2: public Simulator { 
// Declare the state,
// output variables
// and parameters

#define INF 1e20;

double sigma;
int p;
int as1,as2; //3=libre 4=ocupado

int out;
int asOut;
public:
	dist2(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
