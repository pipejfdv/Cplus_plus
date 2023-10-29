#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

//Variables
int f=0,c=0,score=50, op;
bool final = true;
//inicial es para mostrar mapa inicial
int valor=0, inicial=0;
string mapa [6][6];
string visual [6][6];

//limpieza de pantalla en windows y linux
#ifdef _WIN32
//borrado de windows
        #define clearComando "cls"
#else
//borrado de linux
        #define clearComando "clear"
#endif

void generar_Mapa(){
        //resetear random
        srand(time(0));
        //asignar valor V
        for (f=0; f<=5; f++ ){
                for (c=0; c<=5; c++){
                        mapa[f][c] = "V";
                }
        }
        //asignar F aleatorio
        int contador = 0;
        while(contador < 5){
                f = rand() % 6;
                c = rand() % 6;
                if(mapa[f][c] == "V"){
                        mapa[f][c]="F";
                        contador ++;
                }
        }
        f=0;
        c=0;
}

int espejo(int f, int c){
	//Asignar X mapa inicial sin cambio
	if(inicial == 0){
	        for (f=0; f<=5; f++ ){
	                for (c=0; c<=5; c++){
	                        visual[f][c] = "X";
	                }
	        }
	//Visualizar mapa inicial
		cout<<"Vista de mapa Inicial"<<endl;
		cout<<"  0 1 2 3 4 5 \n";
		for(f=0; f<=5; f++){
			cout<<valor<<" ";
			for(c=0; c<=5; c++){
				cout<<visual[f][c]<<" ";
			}
			valor ++;
			cout<<endl;
		}
		inicial ++;
		valor = 0;
		return 0;
	}
	//Mapa que se modifiara para que el usuario vea
	else{
		//si en el caso la posicion escogida tiene una v
		if(mapa[f][c] == "V"){
			//validar el espacio si ya hay una X o V
			if(visual[f][c]=="X"){
				visual[f][c] = "V";
				cout<<"  0 1 2 3 4 5 \n";
				for(f=0; f<=5; f++){
					cout<<valor<<" ";
		                        for(c=0; c<=5; c++){
		                                cout<<visual[f][c]<<" ";
		                        }
		                        valor ++;
		                        cout<<endl;
		                }
		        valor = 0;
				return 1;
			}
			//validar si el espacio ya esta vacio
			else if(visual[f][c]=="V"){
				cout<<"Ese espacio ya lo habias seleccionado -5 puntos"<<endl;
				return 3;
			}
		}
		//si en el caso la posicion escogida tiene una f
		else if(mapa[f][c]=="F"){
			visual[f][c] = "F";
                        cout<<"  0 1 2 3 4 5 \n";
                        for(f=0; f<=5; f++){
                        	cout<<valor<<" ";
                                for(c=0; c<=5; c++){
                                        cout<<visual[f][c]<<" ";
                                }
                                valor ++;
                                cout<<endl;
                        }
                        valor = 0;
                        return 2;
		}
	}
	valor = 0;
	return 0;
}

int validacion_Juego(){
	int fantasmas=0;
	int resultado;
	resultado= espejo(f,c);
	while(score > 0 && score < 60 && fantasmas <3){
	       	cout<<"fila"<<endl;
	       	cin>>f;
	        cout<<"columna"<<endl;
	        cin>>c;
		resultado=espejo(f,c);
		//Espacio vacio sumar puntos
		switch(resultado){
		case 1:
			score = score+3;
			f=0;
			c=0;
			cout<<"Espacio vacio acumulas +3 puntos"<<endl;
			cout<<"Puntaje: "<<score<<endl;
			break;
		//Espacio con fantasmas y aumentar contador de fantasmas encontramos
		case 2:
			score = score-5;
			fantasmas++;
			f=0;
			c=0;
			cout<<"Fantasma encontrado -5 puntos"<<endl;
			cout<<"Puntaje: "<<score<<endl;
			break;
		//Espacio ya repetido restar puntos
		case 3:
			score = score-5;
			f=0;
			c=0;
			cout<<"Espacio ya repetido -5"<<endl;
			cout<<"Puntaje: "<<score<<endl;
			break;
		}
	}
	if(score<0){
		cout<<"te quedaste sin puntos de vida"<<endl;
		return 0;
	}
	else if(score>60){
		cout<<"cumpliste mas de 60 puntos\n---GANASTE---"<<endl;
		return 0;
	}
	else if(fantasmas >= 3){
		cout<<"Encontraste más de 3 fantasmas, perdiste"<<endl;
		return 0;
	}
}

int info_Mapa(){
	system(clearComando);
	int contrasena=1234;
	int evaluo;
	cout<<"Ingresa la contraseña para ver el mapa"<<endl;
	cin>>evaluo;
	if(evaluo == contrasena){
		cout<<"Mapa Creado"<<endl;
                cout<<"  0 1 2 3 4 5 \n";
                for(f=0; f<=5; f++){
                	cout<<valor<<" ";
                        for(c=0; c<=5; c++){
                                cout<<mapa[f][c]<<" ";
                        }
                        valor ++;
                        cout<<endl;
                }
        valor = 0;
	}
	else{
		cout<<"Constrase�a incorrecta"<<endl;
	}
	return 0;
}
int main(){
	generar_Mapa();
	do{
		cout<<"----Ghost game----"<<endl;
		cout<<"Escoge la opciones que necesites"<<endl;
		cout<<"1) Jugar\n2) Ver mapa\n3) Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				cout<<"Es un juego donde tienes que encontrar los espacios vacio y acumular un total de 60 puntos\nNo puedes repetir la misma coordenada y trata de evitar los fantasmas"<<endl;
				system("pause");
				validacion_Juego();
				break;
			case 2:
				info_Mapa();
				break;
			case 3:
				cout<<"Elaborado por:\nJuan Felipe Delgadillo V.\nAndres Felipe Castellanos V."<<endl;
				final = false;
				break;
		}
	}
	while(final == true);
	return 0;
}
