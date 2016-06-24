#include "controlador.h"
void controlador::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

dest = piso = 0;
sigma = INF;
msj = 4;

}
double controlador::ta(double t) {
return sigma;
}
void controlador::dint(double t) {
if ( msj == 0 || msj == 1){msj = 4; sigma = 0;}
if ( msj == 2){msj = 3; sigma = 0;}
if ( msj == 3 || msj == 4){sigma = INF}

}
void controlador::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
int *aux;
aux = (int*)(x.value); 

if (aux[0] == 0) {
	if(dest != piso){}
	else{
		if (aux[0] < piso) {msj = 1; sigma = 0; dest = aux[0]; }
		if (aux[0] > piso) {msj = 0; sigma = 0; dest = aux[0]; }
		if (aux[0] == piso) {msj = 2; sigma = 0; dest = aux[0]; }
	} 
}
else{
	if (aux[0] == dest) { piso = aux[0]; msj = 2; sigma = 0;}
	else {piso = aux[0]; sigma = INF;}
}

}
Event controlador::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
if ( msj == 0 || msj == 1 || msj == 2){return Event(&msj,0);}
else {return Event(&msj,1);}


}
void controlador::exit() {
//Code executed at the end of the simulation.

}
