#include <iostream>
using namespace std;
//estructura
struct almacen{
	int Cod_Cli;
	string Nom_Cli;
	string Ape_Cli;
	int Can_Fotos;
	int Val_fot;
}clientes[100];

//variables globales
int cantidad, i, op, cod_consulta;
//almacen clientes[max];
void visual(almacen clientes[], int cantidad){
	//funcion para ver los clientes
	for(i=0; i< cantidad; i++){
		cout<<clientes[i].Cod_Cli<<" "<<clientes[i].Nom_Cli<<" "<<clientes[i].Ape_Cli<<" "<<clientes[i].Can_Fotos<<" "<<clientes[i].Val_fot<<endl;
	}
}

void consulta(int cantidad, int cod_consulta, almacen clientes[]){
	//funcion de consulta de cliente especifico
	for(i=0; i< cantidad; i++){
		if (clientes[i].Cod_Cli==cod_consulta){
			cout<<clientes[i].Cod_Cli<<" "<<clientes[i].Nom_Cli<<" "<<clientes[i].Ape_Cli<<" "<<clientes[i].Can_Fotos<<" "<<clientes[i].Val_fot<<endl;
		}
	}
}

void informe(almacen clientes[], int cantidad){
	//funcion para mostrar el informe solicitado	
	//visual
	for(i=0; i< cantidad; i++){
		cout<<"ID cliente: "<<clientes[i].Cod_Cli<<"\t"<<"Cantidad fotos: "<<clientes[i].Can_Fotos<<"\t"<<"Valor unitario: "<<clientes[i].Val_fot<<"\t"<<"Total: "<<
		clientes[i].Val_fot*clientes[i].Can_Fotos<<endl;
	}
}

void eliminar_Registro(almacen clientes[], int cantidad, int cod_consulta){
	//elemento para poder ogranizar la estrutura nuevamente
	int eliminado= cod_consulta -1;
	//buscar el cliente a eliminar
	for(i=0;i <cantidad; i++){
		if(clientes[i].Cod_Cli == cod_consulta){
			eliminado = i;
			break;
		}
	}
	//Reestructurar el arreglo remplandolo por el consecutivo
	if(eliminado != -1){
		for(int i=eliminado; i < cantidad - 1;i++){
			clientes[i]=clientes[i+1];
		}
		cantidad--;
		cout<<"El cliente con el numero "<<cod_consulta<<" a sido eliminado."<<endl;
		visual(clientes, cantidad);
	}
	else{
		cout<<"El cliente solicitado con el ID "<<cod_consulta<<" no se encontro"<<endl;
	}
}

int main(){
	bool final=true;
	do{	
		cout<<"-----Bienvenido-----"<<endl;
		cout<<"Opciones\n1.Ingresar clientes\n2.Consultar cliente\n3.Ver informe\n4.Eliminar cliente\n5.Salir"<<endl;
		cin>>op;
		
		
		switch(op){
			case 1:
				system("cls");
				cout<<"Ingresa la cantidad de clientes que desees"<<endl;
				cin>>cantidad;
				
				for(i=0;i<cantidad;i++){
					cout<<"Ingrese el codigo del cliente: "<<endl;
					cin>>clientes[i].Cod_Cli;
					cout<<"¿Cual es su nombre?"<<endl;
					cin>>clientes[i].Nom_Cli;
					cout<<"¿Cual es su apellido?"<<endl;
					cin>>clientes[i].Ape_Cli;
					cout<<"¿Cual es la cantidad de fotos?"<<endl;
					cin>>clientes[i].Can_Fotos;
					cout<<"¿Valor de la foto por unidad?"<<endl;
					cin>>clientes[i].Val_fot;
					
					system("cls");
				}
				visual(clientes, cantidad);
				system("pause");
				system("cls");
				break;
			case 2:
				cout<<"¿Cual es el ID del cliente a consultar?"<<endl;
				cin>>cod_consulta;
				consulta(cantidad,cod_consulta,clientes);
				break;
			case 3:
				informe(clientes, cantidad);
				break;
			case 4:
				//int cod_consulta;
				cout<<"¿Cual es el ID del cliente a borrar?"<<endl;
				cin>>cod_consulta;
				eliminar_Registro(clientes, cantidad, cod_consulta);
				break;
			case 5:
				final = false;
				break;
		}
	}
	while(final == true);
}
