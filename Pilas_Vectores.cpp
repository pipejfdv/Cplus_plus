#include <iostream>
using namespace std;
#include <stack>
//variables
int tamano, resul,i, op;

//funciones
void agregar(int arreglo[], int tamano, int resul){
	for (i=0; i<tamano; i++){
		cout<<"Valor es: "<<endl;
		cin>>arreglo[i];
	}
	//mostrar info del array
	for(i=0; i<resul; i++){
		cout<<arreglo[i]<<"\t"<<endl;
	}
}

int ult_Valor(int arreglo[], int resul){
	//Revisar el caso de que el arrelo tenga elementos
	if(resul > 0){
		//revisar la ultima posicion del array
		if(arreglo[resul-1]==0){
			//si el tamaño es mayor a 2
			if(resul > 1){
				cout<<arreglo[resul -2]<<endl;
			}//ultimo valor en el caso de que tamaño sea de 2
			else{
				int ultimo_Valor = arreglo[resul-1];
        			cout<<"ultimo valor :"<<ultimo_Valor<<endl;
        			return ultimo_Valor;
			}
		}//ultimo valor
		else{
			int ultimo_Valor = arreglo[resul-1];
        		cout<<"ultimo valor :"<<ultimo_Valor<<endl;
        		return ultimo_Valor;
		}
	}//No se encuentran valores en la pila
	else{
		cout<<"No hay valores en la pila"<<endl;
	}
	return 0;
}

void eliminar(int ultimo_Valor, int arreglo[]){
	int eliminado=arreglo[ultimo_Valor]= 0;
        cout<<"Se elimino el valor: "<<eliminado<<"\t";
}

void pila_tamano(int resul){
	cout<<"El tamaño de la pila es: "<<resul<<endl;
}

//ejeucuion del programa
int main(){
	bool seguir = true;

	cout<<"----Organiza tu pila----"<<endl;
	cout<<"Ingresa el tamaño de tu pila"<<endl;
	cin>>tamano;
	int arreglo[tamano];
	//tamaño del arreglo se alamcena en resul
	resul=sizeof(arreglo)/sizeof(arreglo[0]);
	system("clear");
	do{
		cout<<"Escoge la opcion que quieras marcando uno de los números"<<endl;
		cout<<"1.Agregar Valores"<<endl;
		cout<<"2.Ver el ultimo valor - Ver si esta vacia"<<endl;
		cout<<"3.Eliminar valor"<<endl;
		cout<<"4.Ver tamaño de la pila"<<endl;
		cout<<"5.Salir del programa"<<endl;
		cin>>op;
//variable que toma el valor retornado de la funci>
int fuc_ult_Valor = ult_Valor(arreglo, resul);
		switch(op){
			case 1:
				system("clear");
				//funcion push
				agregar(arreglo,tamano, resul);
				system("pause");
				break;
			case 2:
				system("clear");
				//funcion top
				ult_Valor(arreglo, resul);
				system("pause");
				break;
			case 3:
				system("clear");
				//funcion pop
				eliminar(fuc_ult_Valor, arreglo);
				system("pause");
				break;
			case 4:
				system("clear");
				//tamaño de pila para mostrar
				pila_tamano(resul);
				system("pause");
				break;
			case 5:
				system("clear");
				seguir = false;
				system("pause");
				break;
		}
	}
	while(seguir == true);
}
