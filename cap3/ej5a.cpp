/*******************************************************************************
* Escriba una funcion que con entrada k imprima los k-numeros de Fibonacci *****
*******************************************************************************/

#include <iostream>
using namespace std;

void imprimeFibonacci() {
	int k;
	cout << "\nIngrese K: ";
	cin  >> k;
	if (k <= 0) {
		cout << "Por favor ingrese un numero positivo" << endl;
		return;
	}
	if (k>=1) {
		cout << "\n0";
	}
	if (k >= 2) {
		cout << " 1";
	}
	
	long long anterior = 0;
	long long actual = 1;
	for (int i=3; i<=k; i++) {
		long long siguiente = anterior + actual;
		cout << " " << siguiente;
		anterior = actual;
		actual = siguiente;
	}
	cout << "\n\n------------------------------\n"<< endl;
}

void mostrarMenu(){
	int opcion;
	do {
		cout << "Mostrar K-numeros de fibonacci\n" << endl;
		cout << "1. Calcular \n0. Salir \nSeleccione una opcion: ";
		cin  >> opcion;
		switch (opcion) {
			case 1:	
				imprimeFibonacci();
				break;
			case 0:
				cout << "\nGracias por usar el sistema" << endl;
				break;
			default:
				cout << "Opcion invalida. Intente de nuevo" << endl;
				break;
		}
	} while (opcion != 0);
}

int main (){
	
	mostrarMenu();
	return 0;
}