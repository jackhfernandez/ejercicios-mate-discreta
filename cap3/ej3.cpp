/*******************************************************************************
* Escriba un programa que acepte dos numeros enteros positivos n y r. si r <= n*
* regrese el numero de combinaciones de n objetos tomados r a la vez           *
*******************************************************************************/

#include <iostream>
using namespace std;

// Funcion para calcular el factorial de un numero
unsigned long long factorial(int num) {
	unsigned long long resultado = 1;
	for (int i=2; i<=num; i++) {
		resultado *= i;
	}
	return resultado;
}

// Funcion para calcular combinaciones C(n,r) = n! / (r! * (n-r)!)
unsigned long long combinaciones(int n, int r) {
	// Optimizar: c(n,r) = c(n, n-r) usar el menor
	if (r > n - r) {
		r= n-r;
	}
	
	unsigned long long resultado = 1;
	
	for (int i=0; i<r; i++) {
		resultado *= (n-i);
		resultado /=(i+1);
	}
	return resultado;
}

void resultado() {
	int n,r;
	cout << "Ingrese n: ";
	cin  >> n;
	cout << "Ingrese r: ";
	cin  >> r;
	
	// Validar que sean positivos
	if (n <=0 || r<0) {
		cout << "Error. n debe ser positivo y r no puede ser negativo." << endl;
		return;
	}
	// Validar que r<=n
	if (r<=n) {
		unsigned long long resultado = combinaciones(n,r);
		cout << "\nC(" << n << ", " << r << ") = " << resultado << endl;
		cout << "Numero de combinaciones de " << n << " objetos\ntomados " <<
				r << " a la vez es: " << resultado << endl;
		cout << "\n::::::::::::::::::::::::::::::::::::::::::::\n" << endl;
	} else {
		cout << "Error. r debe ser menor o igual que n." << endl;
		return;
	}
}

void mostrarMenu() {
	int opcion;
	do {
		cout << "Calculadora de combinaciones C(n,r)" << endl;
		cout << "Formula: C(n,r) = n! / r! * (n-r)!\n" << endl;
		cout << "1. Calcular" << endl;
		cout << "0. Salir" << endl;
		cout << "\nSeleccione una opcion: ";
		cin  >> opcion;
		
		switch (opcion) {
			case 1:
				resultado();
				break;
			case 0:
				cout << "\nGracias por usar el programa" << endl;
				break;
			default:
				cout << "\nOpcion invalida. Intente de nuevo" << endl;
				break;
		}
	} while (opcion != 0);
}

int main(){
	
	mostrarMenu();
	return 0;
}