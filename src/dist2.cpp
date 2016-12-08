#include "dist2.h"
void dist2::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

sigma=INF;

//Both systems are free at begining
as1=3;
as2=3;

cola1=cola2=0;
}
double dist2::ta(double t) {
//This function returns a double.
return sigma;
}
void dist2::dint(double t) {

//Go to rest mode
sigma=INF;
}
void dist2::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

printLog("(-- dext DISTRIBUIDOR \t\t");

printLog("t= %2.2f\t",t);
int *aux;
aux = (int*)(x.value);

if (x.port==0){ 
	//Save the request in state var
	p=aux[0];
	sigma=0;
	printLog("DISTRIBUIDOR: recibi un pedido= %d",p);
}
else{
	if (x.port == 1){ //Message from system1
		if (aux[0]==3) {
			if (cola1>0) cola1--;
		}
		if (cola1==0)
			as1 = 3;
		else as1 = 4;
		printLog("DISTRIBUIDOR: el sistema 1 mando un= %d, la cola es de %d pedidos, as1= %d",aux[0],cola1,as1);
	}
	else{ //Message from system2
		if (aux[0]==3) {
			if (cola2>0) cola2--;
		}
		if (cola2==0)
			as2 = 3;
		else as2 = 4;
		printLog("DISTRIBUIDOR: el sistema 2 mando un= %d, la cola es de %d pedidos, as2= %d",aux[0],cola2,as2);
	}
	sigma=INF;
}

printLog("\t --)\n");
}
Event dist2::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
printLog("(-- lambda DISTRIBUIDOR \t\t");

printLog("t= %2.2f\t",t);

if (as1==3 || as2==4){ //is the system1 free? Or both system are busy?
	asOut=0; //Go to the system1
	cola1++;
}
else { //then system1 is busy and system2 is free
	asOut=1; //Go to the system2
	cola2++;
}

out = p;
printLog("DISTRIBUIDOR: envio un %d al sistema %d",p,asOut+1);
printLog("\t --)\n");
//Output by the port 0 or 1 depending of which turn is
return Event(&out,asOut);	



}
void dist2::exit() {
//Code executed at the end of the simulation.

}
