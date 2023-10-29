#include <iostream>
using namespace std;

//variables globales
float celsius, fahren, kelvin;

//cambio de celsius a Fahrenheit 
int celci_Fahren(){
	system("cls");
	cout<<"Ingresa la temperatura en Celsius"<<endl;
	cin>>celsius;
	fahren = celsius * 1.8 + 32;
	cout<<"Tu temperatura en celsius a fahrenheit es esta: "<<fahren<<endl;	
	system("pause");
}

//cambio de fahrenhit a celcius
int Fahren_celci(){
	system("cls");
	cout<<"Ingresa la temperatura en fahrenheit"<<endl;
	cin>>fahren;
	celsius = (fahren - 32)/1.8;
	cout<<"Tu temperatura en fahrenheit a celsius es esta: "<<celsius<<endl;	
	system("pause");
}

//cambio de celsius a kelvin
int celci_kelvin(){
	system("cls");
	cout<<"Ingresa la temperatura en celsius"<<endl;
	cin>>celsius;
	kelvin = celsius + 273.15;
	cout<<"Tu temperatura en celsius a kelvin es esta: "<<kelvin<<endl;
	system("pause");
}

//cambio de kelvin a celsius
int kelvin_celci(){
	system("cls");
	cout<<"Ingresa la temperatura en kelvin"<<endl;
	cin>>kelvin;
	celsius= kelvin - 273.15;
	cout<<"Tu temperatura de kelvin a celsius es esta: "<<celsius<<endl;
	system("pause");
}

//cambio de fahrenheit a kelvin
int fahren_kelvin(){
	system("cls");
	cout<<"Ingresa la temperatura en Fahrenheit"<<endl;
	cin>>fahren;
	kelvin = (fahren + 459.67) * 5/9;
	cout<<"Tu temperatura de Fahrenheit a kelvin es esta: "<<kelvin<<endl;
	system("pause");
}

//cambio de kelvin a fahrenheit
int kelvin_fahren(){
	system("cls");
	cout<<"Ingresa la temperatura en kelvin"<<endl;
	cin>>kelvin;
	fahren = kelvin * 9/5 - 459.67;
	cout<<"Tu temperatura de kelvin a Fahrenheit es esta: "<<fahren<<endl;
	system("pause");
}

int main(){
	bool final = true;
	int op;
	do{
		system("cls");
		cout<<"-----Cambio de grados-----"<<endl;
		cout<<"Escoge la opcion que quieras: \n1.Celsius a Fahrenheit\n2.Fahrenheit a celsius\n3.Celsius a kelvin\n4.Kelvin a celsius\n5.Fahrenheit a kelvin\n6.Kelvin a fahrenheit\n7.Salir"<<endl;
		cin>>op;
		switch(op){
			case 1:
				celci_Fahren();
				break;
			case 2:
				Fahren_celci();
				break;
			case 3:
				celci_kelvin();
				break;
			case 4:
				kelvin_celci();
				break;
			case 5:
				fahren_kelvin();
				break;
			case 6:
				kelvin_fahren();
				break;
			case 7:
				final = false;
				break;
		}
	}
	while(final == true);	
}
