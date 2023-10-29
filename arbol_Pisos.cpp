#include <iostream>
using namespace std;

//si estan activos los ascensores
bool activo1=false, activo2=false;
int u_piso=NULL, pasjeros=NULL;

struct edificio{
	int piso;
	edificio* izq;
	edificio* der;
	//contructor del nodo
	edificio(int valor):piso(valor), izq(NULL), der(NULL){}
};

struct Ascensor{
	int piso_Actual;
	int capacidad;
};
//funcion con la cual se define con un puntero
edificio* insertar(edificio* acceso, int valor){
	//si el nodo esta vacio
	if (acceso == NULL){
		return new edificio(valor);
	}
	//asignar los siguiente valores
	if (valor < acceso->piso){
		acceso->izq = insertar(acceso->izq, valor);
	}
	else if (valor > acceso->piso){
		acceso->der = insertar(acceso->der, valor);
	}
	return acceso;
}

//mover los ascensores
void mov_Ascensor (int u_piso){
	if(activo1){
		
	}
	else if (activo2){
	}
}

//determinar la distancia y que ascensor debe moverse
bool invocacion (int solicitud, const Ascensor& ascensor1,const Ascensor& ascensor2,){
	int distancia1 = NULL, distancia2 = NULL;

	//calcular distancia
	distancia1 = abs(ascensor1.piso_Actual - solicitud);
	distancia2 = abs(ascensor2.piso_Actual - solicitud);
	if(distancia1 < distancia2){
		//ejecutar primer ascensor
		return activo1 = true;
	}
	else{
		
		//ejecutar segundo ascensor
		return activo2 = true;
	}		
}

//estructura del nodo
int main(){
	cout<<"---------Ascensores---------"<<endl;
	edificio* acceso = NULL;
	int n_pisos[30]={};
	//llenar el array de cantidad de pisos
	for (int i = 0; i < 30; i++){
		n_pisos[i]=i+1;	
	}
	//tope del array
	int limite = (sizeof(n_pisos)/sizeof(n_pisos[0]));
	//asignar pisos en el arbol
	for(int i = 0; i <limite;i ++){
		acceso = insertar(acceso, i);
	}
	//crear ascensores
	Ascensor ascensor1 = {acceso->piso, 0};
	Ascensor ascensor2 = {acceso->der=NULL,0};
	bool seguir = true;
	int op = NULL;
	do{
		cout<<"- Ascensor 1 - piso: "<<ascensor1.piso_Actual<<endl;
		cout<<"- Ascensor 2 - piso: "<<ascensor2.piso_Actual<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"Menu\n1. Llamar ascensor\n2. Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				cout<<"Piso a escoger: "<<endl;
				cin>>u_piso;
				cout<<"Personas que ingresan: "<<endl;
				cin>>pasajeros;
				if(pasajeros <= 6){
					bool activacion = invocacion(u_piso);
					if (activacion){
						mov_Ascensor(u_piso);
					}
					else{
						cout<<"fallo al solicitar el ascensor"<<endl;
					}
				}
				else{
					cout<<"demasiados pasajeros --PELIGRO--"<<endl;
				}
		}
	}
	while(seguir == true);
}
