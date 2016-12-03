#include "int2float.h"
void int2float::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

sigma=INF;
}
double int2float::ta(double t) {
//This function returns a double.
return sigma;
}
void int2float::dint(double t) {
sigma=INF;
}
void int2float::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

int *aux;
aux = (int*)(x.value);

in = aux[0];
sigma=0;
}
Event int2float::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

out = (double)in;
return Event(&out,0);
}
void int2float::exit() {
//Code executed at the end of the simulation.

}
