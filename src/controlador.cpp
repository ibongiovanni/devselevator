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
printLog("(-- dint CONTROLADOR \t\t");

printLog("t= %2.2f\t",t);
if ( msj == 0 || msj == 1){msj_ = 4; sigma = 0; printLog("CONTROLADOR: envie un %d al ascensor ",msj);}
if ( msj == 2){msj_ = 3; sigma = 0; printLog("CONTROLADOR: envie un %d al ascensor ",msj);}
if ( msj == 3 || msj == 4){sigma = INF; printLog("CONTROLADOR: envie un %d al tablero ",msj);}

msj = msj_;
printLog("\t --)\n");

}
void controlador::dext(Event x, double t) {
printLog("(-- dext CONTROLADOR \t\t");//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
int *aux;
aux = (int*)(x.value); 
	
if (x.port == 0) {
	printLog("t= %2.2f\t",t);
	printLog("CONTROLADOR: el tablero mando un= %d ",aux[0]);
	if(dest != piso){}
	else{
		if (aux[0] < piso) {msj = 1; sigma = 0; dest = aux[0]; }
		if (aux[0] > piso) {msj = 0; sigma = 0; dest = aux[0]; }
		if (aux[0] == piso) {msj = 2; sigma = 0; dest = aux[0]; }
	} 
}
else{
	printLog("t= %2.2f\t",t);
	printLog("CONTROLADOR: el asensor mando un= %d ",aux[0]);
	if (aux[0] == dest && aux[0] != lastMsjAsc) { 
		piso = aux[0]; 
		msj = 2; 
		sigma = 0;
		lastMsjAsc=aux[0];
		printLog("- llego al destino ",aux[0]);
	}
	else {
		piso = aux[0]; 
		sigma = INF;
	}
}

printLog("\t --) \n");
}
Event controlador::lambda(double t) {
printLog("(-- lambda CONTROLADOR \t\t");//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
if ( msj == 0 || msj == 1 || msj == 2){
	printLog("t= %2.2f\t",t);
	printLog("CONTROLADOR: mando al ascensor= %d",msj); printLog("\t --) \n");
	return Event(&msj,0);
}
else {
	printLog("t= %2.2f\t",t);
	printLog("CONTROLADOR: mando al tablero= %d",msj); printLog("\t --) \n");
	return Event(&msj,1);
}



}
void controlador::exit() {
//Code executed at the end of the simulation.

}
