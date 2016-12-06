#include "dist.h"
void dist::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

sigma=INF;

turn=0;
}
double dist::ta(double t) {
//This function returns a double.
return sigma;
}
void dist::dint(double t) {
//Switch elevator's turn
if (turn==0){
	turn=1;
}
else{ turn = 0; }

//Go to rest mode
sigma=INF;
}
void dist::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

printLog("(-- dext DISTRIBUIDOR \t\t");

printLog("t= %2.2f\t",t);


int *aux;
aux = (int*)(x.value); 

//Save the request in state var
p=aux[0];

sigma=0;

printLog("DISTRIBUIDOR: recibi un pedido= %d",p);
printLog("\t --)\n");
}
Event dist::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
printLog("(-- lambda DISTRIBUIDOR \t\t");

printLog("t= %2.2f\t",t);

out = p;
printLog("DISTRIBUIDOR: envio un %d al ascensor %d",p,turn);
printLog("\t --)\n");
//Output by the port 0 or 1 depending of which turn is
return Event(&out,turn);	



}
void dist::exit() {
//Code executed at the end of the simulation.

}
