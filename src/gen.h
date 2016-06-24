//LIB:-lm
//CPP:random/lib/randomc.cpp
//CPP:userdevs/elevatordevs/src/gen.cpp
#if !defined gen_h
#define gen_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "time.h"
#include "random/lib/randomc.h"
#include "math.h"


class gen: public Simulator { 
// Declare the state,
// output variables
// and parameters

//state
double s;

//output
double v;

//aux
CRandomMersenne *RanGen;
double y[10];

//Params
double lam;






public:
	gen(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
