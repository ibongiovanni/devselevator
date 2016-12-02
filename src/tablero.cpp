#include "tablero.h"
void tablero::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

ps = new LinkedList();
msj = 3;
sigma=INF;
}
double tablero::ta(double t) {
//This function returns a double.
return sigma;
}
void tablero::dint(double t) {
printLog("(-- dint TABLERO \t\t");
ps->erase(0);
sigma=INF;
printLog("\t --) \n");
}
void tablero::dext(Event x, double t) {
printLog("(-- dext TABLERO \t\t\t");//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

int *aux;
aux = (int*)(x.value);

if (x.port==0) { //Order arrived
	printLog("t= %2.2f\t",t);
	printLog("TABLERO: recibi un pedido= %d",aux[0]);
	if (aux[0]>=1 && aux[0]<=10){
		if (!ps->contains(aux[0])){ //Avoid repeated orders
			ps->append(aux[0]);
		}
		if (msj==4){
			sigma=INF;
		}
		else{
			sigma=0;
		}
	}
	else{sigma = INF;}
}
else{	//Controller message arrived
	printLog("t= %2.2f\t",t);
	printLog("TABLERO: el controlador me mando un= %d",aux[0]);
	msj=aux[0];
	if (aux[0]==3){
		if (ps->empty()){
			printLog(". La cola esta vacia");
			sigma=INF;
		}
		else{
			printLog(". La cola es= "); 
			printLog(ps->tostring());
			sigma=0;
		}
	}
	else{
		sigma=INF;
	}
}

printLog("\t --) \n");

}
Event tablero::lambda(double t) {
printLog("(-- lambda TABLERO \t\t\t");//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

v = ps->at(0);
printLog("t= %2.2f\t",t);
printLog("TABLERO: mando un pedido al controlador= %d",v);
printLog("\t --) \n");
return Event(&v,0);
}
void tablero::exit() {
//Code executed at the end of the simulation.

}
