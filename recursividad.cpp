#include <iostream>
#include <fstream>
using namespace std;

int numero, n, resultado=0;

int ciclo(int numero){	
	if(numero == 0){
		numero = 1;		
	}
	else{
		resultado ++;
		cout<<resultado<<" \t";
		numero=numero*ciclo(numero-1);
	}
	
	return numero;
}

int main(){
	cout<<"cuantas ejecuciones quieres :"<<endl;
	cin>>numero;
	cout<<"
	 :"<<endl;
	system("cls");
	ciclo(numero);
}
