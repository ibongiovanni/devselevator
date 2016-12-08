//CPP:userdevs/elevatordevs/src/lib/linkedlist.cpp
//CPP:userdevs/elevatordevs/src/manager.cpp
#if !defined manager_h
#define manager_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "lib/linkedlist.h"


class manager: public Simulator { 
// Declare the state,
// output variables
// and parameters

#define INF 1e20;

LinkedList *ps;
double sigma;

Node* out;

int ped;
public:
	manager(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
