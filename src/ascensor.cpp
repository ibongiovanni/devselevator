#include "ascensor.h"
void ascensor::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

char *fvar= va_arg(parameters,char*); 
vc =getScilabVar(fvar );
fvar= va_arg(parameters,char*);
altPiso =getScilabVar(fvar );

est = 2;
h = 0;
sigma = INF;
}
double ascensor::ta(double t) {
return sigma;

}
void ascensor::dint(double t) {
switch(est){
	case 0: { h = nf(h); sigma = vc*altPiso; }
	case 1: { h = pf(h); sigma = vc*altPiso; }
	case 5: { est = 2; h = nf(h); sigma = INF; }
	case 6: { est = 2; h = pf(h); sigma = INF; }
}
}
void ascensor::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

int *aux;
aux = (int*)(x.value); 

switch(est){
	case 0: h2 = h + vc*e;
	case 1: h2 = h - vc*e;
	case 2: h2 = h;
}
est2 = aux[0];
sigma2 = sigma- e;
//if ((est = 0) && (aux[0] = 0)) { sigma2 = sigma - e; est2 = aux[0]; }
if ((est = 0) && (aux[0] = 1)) { sigma2 = vc*(h2 - pf(h2)); }
if ((est = 0) && (aux[0] = 2)) { sigma2 = vc*(nf(h2) - h2); est2 = 5; }

if ((est = 1) && (aux[0] = 0)) { sigma2 = vc*(nf(h2) - h2); }
//if ((est = 1) && (aux[0] = 1)) { sigma2 = sigma - e; est2 = aux[0]; }
if ((est = 1) && (aux[0] = 2)) { sigma2 = vc*(h2 - pf(h2)); est2 = 6; }

if ((est = 2) && (aux[0] = 0)){
	if (h2 <= 16) { sigma2 = vc*(2*altPiso);}}

if ((est = 2) && (aux[0] = 1)){
	if (h2 >= 2) { sigma2 = vc*(2*altPiso);}}

est = est2;
h = h2;
sigma = sigma2;




}
Event ascensor::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
double value = (h/2)+1;
return Event(&value,0);


}
void ascensor::exit() {
//Code executed at the end of the simulation.

}
