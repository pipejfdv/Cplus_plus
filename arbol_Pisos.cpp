//Juan Felipe Delgadillo V.
//Andres Felipe Castellanos V.
//Luz Adriana Moreno C.
#include <iostream>
#include <queue>
//tiempo
#include <chrono>
#include <thread>
using namespace std;

//si estan activos los ascensores
bool activo1=false, activo2=false;
int u_piso=0;
int pasajeros=0;
int p_total=0;

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
	int cantidad_Pasajeros;
};

//tiempo de espera
void esperar(int segundos){
	for(int i=0;i<segundos; i++){
		cout<<".";
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout<<endl;
}

int encontrarMaximo(edificio* acceso) {
    while (acceso->der != nullptr) {
        acceso = acceso->der; // Avanza hacia el nodo más a la derecha.
    }

    return acceso->piso; // Retorna el valor máximo.
}

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

//busqueda del piso en Inorden
edificio* buscarPisoInorden(edificio* nodo, int u_piso){
	if(nodo != NULL){
		//si el piso es menor al solicitado
		if(u_piso < nodo->piso){
			return buscarPisoInorden(nodo->izq, u_piso);
		}
		//si el piso es mayor al solicitado
		else if (u_piso > nodo->piso){
			return buscarPisoInorden(nodo->der, u_piso);
		}
		//el piso solicitado es igual
		return nodo;
	}
	return NULL;
}

//destino
void destino (edificio* acceso, bool activo1, bool activo2, Ascensor& ascensor1, Ascensor& ascensor2){
        int u_destino=0;
	cout<<"cerrado puertas"<<endl;
	cout<<"Seleccionar destino"<<endl;
	cin>>u_destino;
	if(activo1){
                edificio* piso_encontrado = buscarPisoInorden(acceso, u_destino);
                if(piso_encontrado != NULL){
                        ascensor1.piso_Actual = u_destino;
			esperar(4);
                        cout<<"llego al destino ascensor 1 - piso"<<u_destino<<endl;
                        cout<<"abriendo puertas"<<endl;
                }
        }
        else if (activo2){
                edificio* piso_encontrado = buscarPisoInorden (acceso, u_destino);
                if(piso_encontrado != NULL){
                        ascensor2.piso_Actual = u_destino;
			esperar(4);
                        cout<<"llego al destino ascensor 2 - piso"<<u_destino<<endl;
                        cout<<"abriendo puertas"<<endl;
                }
        }
        //excepcion
        else{
                cout<<"destino no se encuentra"<<endl;
        }
}

//mover los ascensores
void mov_Ascensor (int u_piso, edificio* acceso, bool activo1, bool activo2, Ascensor& ascensor1, Ascensor& ascensor2){
	if(activo1){
		edificio* nodo_encontrado = buscarPisoInorden(acceso, u_piso);
		if(nodo_encontrado != NULL){
			ascensor1.piso_Actual = u_piso;
			cout<<"llego el ascensor 1 - piso"<<u_piso<<endl;
			esperar(4);
			cout<<"abriendo puertas"<<endl;
			destino(acceso, true, false, ascensor1, ascensor2);
		}
	}
	else if (activo2){
		edificio* nodo_encontrado = buscarPisoInorden (acceso, u_piso);
		if(nodo_encontrado != NULL){
		 	ascensor2.piso_Actual = u_piso;
			cout<<"llego el ascensor 2 - piso"<<u_piso<<endl;
			esperar(4);
			cout<<"abriendo puertas"<<endl;
			destino(acceso, false, true, ascensor1, ascensor2);
		}
	}
	//excepcion
	else{
		cout<<"No hay ascensores activos"<<endl;
	}
}

//determinar la distancia y que ascensor debe moverse
bool invocacion (int solicitud, Ascensor& ascensor1, Ascensor& ascensor2, edificio* acceso, int pasajeros){
	//calcular distancia
	int distancia1 = abs(ascensor1.piso_Actual - solicitud);
	int distancia2 = abs(ascensor2.piso_Actual - solicitud);
	if(distancia1 < distancia2){
		//ejecutar primer ascensor
		activo1 = true;
		mov_Ascensor(u_piso, acceso, true, false, ascensor1, ascensor2);
		p_total += pasajeros;
		return true;
	}
	else{
		//ejecutar segundo ascensor
		activo2 = true;
		mov_Ascensor(u_piso, acceso, false, true, ascensor1, ascensor2);
		p_total += pasajeros;
		return true;
	}
	return false;
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
		acceso = insertar(acceso, n_pisos[i]);
	}
	//maximo
	int ultimoPiso = encontrarMaximo(acceso);
	//crear ascensores
	Ascensor ascensor1 = {acceso->piso, 0,0};
	Ascensor ascensor2 = {ultimoPiso,0,0};
	bool seguir = true;
	int op;
	queue<int> solicitudes;
	do{
		cout<<"- Ascensor 1 - piso: "<<ascensor1.piso_Actual<<endl;
		cout<<"- Ascensor 2 - piso: "<<ascensor2.piso_Actual<<endl;
		cout<<"Cantidad de pasajeros: "<<p_total<<endl;
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
					bool activacion = invocacion(u_piso, ascensor1, ascensor2, acceso, pasajeros);
					if (activacion){
						//agregar solicitudes
						solicitudes.push(u_piso);
					}
				}
				else{
					cout<<"demasiados pasajeros --PELIGRO--"<<endl;
				}
				break;
			case 2:
				seguir = false;
				break;
		}
	}
	while(seguir == true);
}
