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

printLog("ASCENSOR: valores de parametros: vc= %2.2f; altPiso= %2.2f\n",vc,altPiso);
est = 2;
h = 0;
sigma = INF;
}
double ascensor::ta(double t) {
return sigma;

}
void ascensor::dint(double t) {
printLog("(-- dint ASCENSOR \t\t\t");
printLog("t= %2.2f\t",t);
switch(est){
	case 0: { h = nf(h); sigma = vc*altPiso; printLog("ASCENSOR: voy a seguir subiendo"); break; }
	case 1: { h = pf(h); sigma = vc*altPiso; printLog("ASCENSOR: voy a seguir bajando"); break;}
	case 5: { est = 2; sigma = INF; printLog("ASCENSOR: voy a descansar"); break;}
	case 6: { est = 2; sigma = INF; printLog("ASCENSOR: descansar"); break;}
}
printLog(",h= %2.2f, sigma= %2.2f ",h,sigma);
printLog("\t --) \n");
}
void ascensor::dext(Event x, double t) {
printLog("(-- dext ASCENSOR \t\t\t");//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

int *aux;
aux = (int*)(x.value); 

printLog("t= %2.2f\t",t);
printLog("ASCENSOR: me llego una orden= %d\n",aux[0]);
switch(est){
	case 0: {h2 = h + vc*e; break; }
	case 1: {h2 = h - vc*e; break; }
	case 2: {h2 = h; break; }
}
est2 = aux[0];
sigma2 = sigma- e;
if ((est == 0) && (aux[0] == 1)) { sigma2 = vc*(h2 - pf(h2)); }
if ((est == 0) && (aux[0] == 2)) { sigma2 = 0; est2 = 5; }

if ((est == 1) && (aux[0] == 0)) { sigma2 = vc*(nf(h2) - h2); }
//if ((est == 1) && (aux[0] == 1)) { sigma2 = sigma - e; est2 = aux[0]; }
if ((est == 1) && (aux[0] == 2)) { sigma2 = 0; est2 = 6; }

if ((est == 2) && (aux[0] == 0)){
	if (h2 <= 16) { sigma2 = vc*altPiso;}}

if ((est == 2) && (aux[0] == 1)){
	if (h2 >= 2) { sigma2 = vc*altPiso;}}


est = est2;
h = h2;
sigma = sigma2;

printLog("t= %2.2f\t",t);
printLog("ASCENSOR: estado: est= %d, h= %2.2f, sigma= %2.2f ",est,h,sigma);

printLog("\t --) \n");


}
Event ascensor::lambda(double t) {
printLog("(-- lambda ASCENSOR \t\t");//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
if ( est==0 || est==5) {value=nf(h)/2+1;}
else {value=pf(h)/2+1;}
printLog("t= %2.2f\t",t);
printLog("ASCENSOR: llegue al piso= %d, h: %2.2f ",value,h);
printLog("\t --) \n");
return Event(&value,0);


}
void ascensor::exit() {
//Code executed at the end of the simulation.

}
