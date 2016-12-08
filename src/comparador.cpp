#include "comparador.h"
void comparador::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

ts1=NULL;
ts2=NULL;
sigma=INF;

out = NULL;
}
double comparador::ta(double t) {
//This function returns a double.

return sigma;
}
void comparador::dint(double t) {
ts1=NULL;
ts2=NULL;
sigma=INF;
}
void comparador::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

Node** aux;
aux = (Node**)(x.value);
printLog("t= %2.2f\t",t);


if (x.port==0) { //
	 printLog("COMPARADOR: recibi un mensaje del manager1= %d",aux[0]->est_time);

	ts1=aux[0];
	if (ts2==NULL){
		sigma=INF;
	}
	else{
		sigma=0;
	}
}
else{ //
	 printLog("COMPARADOR: recibi un mensaje del manager2= %d",aux[0]->est_time);

	ts2=aux[0];
	if (ts1==NULL){
		sigma=INF;
	}
	else{
		sigma=0;
	}
}

}
Event comparador::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

int port=0;
if ( ts2->est_time < ts1->est_time ){
	out = new Node(ts2->data, ts2->est_time);
	port=1;
}
else{
	out = new Node(ts1->data, ts1->est_time);
}

return Event(&out,port);
}
void comparador::exit() {
//Code executed at the end of the simulation.

}
