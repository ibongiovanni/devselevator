#include "manager.h"
void manager::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

ps = new LinkedList();

est=3;
sigma=INF;
timeAct=0;
last_floor=1;
}
double manager::ta(double t) {
//This function returns a double.
return sigma;
}
void manager::dint(double t) {
printLog("(-- dint MANAGER \t\t\t");
sigma=INF;

if (outport==1){
	timeAct= (double) abs(ped-last_floor)*2;
	last_floor=ped;
}

printLog("t= %2.2f\t",t);
printLog("MANAGER: el puerto de salida fue: %d, timeAct: %2.2f, ped: %d, last_floor: %d",outport,timeAct,ped,last_floor);

printLog("\t --) \n");
}
void manager::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
printLog("(-- dext MANAGER \t\t\t");
printLog("t= %2.2f\t",t);
if (timeAct>e){ //Actualiza el tiempo de uso restante
	timeAct = timeAct-e;
}
else{
	timeAct=0;
}

inport=x.port;	

if (x.port == 0){ //Recibe un pedido
	int *aux;
	aux = (int*)(x.value);
	ped = aux[0];
	sigma = 0;
	outport=0;
	printLog("MANAGER: Recibi un pedido: %d", ped);
}
if (x.port== 1) { //Recibe un nodo del comparador
	Node** aux;
	aux = (Node**)(x.value);
	if (est==3 && ps->empty()){ //Revisa si debe enviarlo al sistema
		sigma=0;
		outport=1;
		ped=aux[0]->data;
		//last_floor=ped;
		printLog("MANAGER: Recibi un nodo y debo enviarlo (%d,%2.2f)",ped,aux[0]->est_time);
	}
	else {
		if (!ps->contains(aux[0]->data)){ //Evitar repetidos
			double prev_floor; //De donde parte el ascensor
			if (ps->empty()){		prev_floor=(double)last_floor; }
			else { 						prev_floor = ps->last_ped(); }
			Node * new_node = new Node( aux[0]->data, fabs( ((double)aux[0]->data) - prev_floor) );
			ps->append_node(new_node);
			printLog("MANAGER: Recibi un nodo: (%d,%2.2f) y lo mande a la cola: (%d,%2.2f)",aux[0]->data,aux[0]->est_time, new_node->data,new_node->est_time);
		}
		printLog("MANAGER: Recibi un nodo con un pedido repetido");
		sigma=INF;
	}
}
if (x.port == 2){ //Recibe un libre/ocupado del sistema
	int *aux;
	aux = (int*)(x.value);
	sigma=INF;
	if (aux[0]==3){
		if (!ps->empty()){
			sigma=0;
			outport=1;
			ped = ps->at(0);
			//last_floor=ped;
			ps->erase(0);
		}
	}
	printLog("MANAGER: Recibi un %d del sistema, sigma: %2.2f", aux[0],sigma);
}

printLog("\t --) \n");
}
Event manager::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
printLog("(-- lambda MANAGER \t\t\t");
printLog("t= %2.2f\t",t);
if (outport==0){
	double ttotal=0;
	ttotal+=timeAct; //Tiempo en completar el pedido actual
	ttotal+=ps->total_time(); //Tiempo total en la cola
	double prev_floor; //De donde parte el ascensor
		if (ps->empty()){		prev_floor=(double)last_floor; } //Si no hay pedidos en la cola
		else { 						prev_floor = ps->last_ped(); }	 //Si hay pedidos en la cola
	int dist_pisos = abs(prev_floor-ped); //Diferencia entre el piso al que quiere ir y el piso del que parte
	ttotal += (double) dist_pisos*2; //distancia por el tiempo que tarda en hacer cada piso
	printLog("\n\t timeAct: %2.2f \n\t dist_pisos: %2.2f \n\t ps.total_time: %2.2f \n\t\t\t",timeAct,(double)dist_pisos,ps->total_time());
	out = new Node(ped,ttotal);
	printLog("MANAGER: Envio un nodo: (%d,%2.2f) al comparador", out->data, out->est_time);
	printLog("\t --) \n");
	return Event(&out,outport);		
}
else{
	printLog("MANAGER: Envio un pedido: %d al sistema", ped);
	printLog("\t --) \n");
	return Event(&ped,outport);	
}


}
void manager::exit() {
//Code executed at the end of the simulation.

}
