#include <iostream>
using namespace std;
//Variables globales - primeros puntos
int vector_Primer[10], i, op;
int size_Vector;


//variables globales para el tercer punto
int vector_Seg[5];
int contador_deficientes = 0;
int contador_regulares = 0;
int contador_buenos = 0;
int contador_excelentes = 0;
//funciones para primeros puntos
int asignar_val(){
	cout<<"Ingresa los 10 valores para almacenarlos"<<endl;
	for(i=1;i<=9; i++){
			cout<<"Ingresa el valor "<<i<<": "<<endl;
			cin>>vector_Primer[i];
			system("cls");
		}
	cout<<"Estos son tus valores"<<endl;
	for (i=0; i<=9;i++){
		cout<<vector_Primer[i]<<"\n"<<endl;
		}	
}

int suma_Vec(){
	system("cls");
	int suma=0 ;
	for (i=0; i < size_Vector; i++)
	{
		suma += vector_Primer[i];
	}
	cout<<"suma: "<<suma<<endl;
	return suma;
}

int resta_Vec(){
	system("cls");
	int resta=0;
	for (i=0; i < size_Vector; i++)
	{
		resta -= vector_Primer[i];
	}
	cout<<"resta: "<<resta<<endl;
}

int multi_Vec(){
	system("cls");
	int multi=1;
	for (i=0; i < size_Vector; i++)
	{
		multi *= vector_Primer[i];
	}
	cout<<"multiplicaion: "<<multi<<endl;
}

int divi_Vec(){
	system("cls");
	float divi= 1.0;
	for (i=0; i < size_Vector; i++)
	{
		divi /= vector_Primer[i];
	}
	cout<<"division: "<<divi<<endl;
}

int prom_Vec(){
	system("cls");
	float prom = suma_Vec()/size_Vector;
	cout<<"Este es tu promedio "<<prom<<endl;
	}

int primero(){
	system("cls");
	bool final = true;
	asignar_val();
	do{	
		cout<<"Escoge la opcion que quieras:"<<endl;
		cout<<"1.Ver suma"<<endl;
		cout<<"2.Ver resta"<<endl;
		cout<<"3.Ver multiplicacion"<<endl;
		cout<<"4.Ver division"<<endl;
		cout<<"5.Regresar al menu principal"<<endl;
		cin >> op;
		switch(op){
			case 1:
				suma_Vec();
				break;	
			case 2:
				resta_Vec();
				break;
			case 3:
				multi_Vec();
				break;
			case 4:
				divi_Vec();
				break;
			case 5:
				final = false;
				break;
		}
	}
	while(final == true);
}

//Funciones para tercer punto

//prototipo para poder ejecutar la funcion sin definirla
void opciones_3();

void rendimiento(){
	system("cls");
    for (int i = 0; i < 5; i++) {
	   cout << "Estudiante " << (i + 1) << ": " << vector_Seg[i] << endl;
	}

    cout << "\nResumen:" << endl;
    cout << "Deficientes: " << contador_deficientes << " estudiantes" << endl;
    cout << "Regulares: " << contador_regulares << " estudiantes" << endl;
    cout << "Buenos: " << contador_buenos << " estudiantes" << endl;
    cout << "Excelentes: " << contador_excelentes << " estudiantes" << endl;

}


void ing_Notas(){

	//Ingreso de notas
	for(i=1;i<=5; i++){
		cout<<"Ingresa la nota "<<i<<": "<<endl;
		cin>>vector_Seg[i];
		
        if (vector_Seg[i] >= 0 && vector_Seg[i] <= 5) {
        	contador_deficientes++;
        } 
		else if (vector_Seg[i] >= 6 && vector_Seg[i] <= 10) {
            contador_regulares++;
        } 
		else if (vector_Seg[i] >= 11 && vector_Seg[i] <= 15) {
            contador_buenos++;
        } 
		else if (vector_Seg[i] >= 16 && vector_Seg[i] <= 20) {
            contador_excelentes++;
        }
		system("cls");
	}
	cout<<"Estas fueron las notas ingresadas: "<<endl;
	for(i=1;i<=5; i++){
		cout<<vector_Seg[i]<<"\t"<<endl;
	}
}

void segundo(){
	system("cls");
	cout<<"Para poder evaluar el rendimiento de un estudiante"<<"\n"<<"necesitamos que ingreses las notas de (0-20)"<<endl;
	cout<<"Ingresa las notas (Recuerda son maximo 5 notas):"<<endl;
	ing_Notas();
	system("pause");
	opciones_3();
}

void opciones_3(){
	//menu secundario del programa 3
	bool final = true;
	do{
		cout<<"Escoge tu opcion"<<"\n"<<"1.Ver rendimiento"<<endl;
		cout<<"2.Regresar y cambiar valores"<<endl;
		cout<<"3.Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				rendimiento();
				break;
			case 2:
				ing_Notas();
				break;
			case 3:
				final = false;
				break;
		}
	}
	while(final == true);
}

int main (){
	bool final = true;
	system("cls");
		do{
			cout<<"---Bienvenido----"<<endl;
			cout<<"1.Crear tu vector (Sumar, Restar, Multiplicar, Dividir)"<<endl;
			cout<<"2.Ver el promedio de tu vector creado"<<endl;
			cout<<"3.Programa"<<endl;
			cout<<"4.Salir"<<endl;
			cin>>op;
			//tamaño del vector
			size_Vector=sizeof(vector_Primer)/sizeof(vector_Primer[0]);
			switch(op){
				case 1:
					primero();
				break;
				case 2:
					prom_Vec();
					break;
				case 3:
					segundo();
				case 4:
					final = false;
					break;	
			}

		}
		while(final== true);
}
