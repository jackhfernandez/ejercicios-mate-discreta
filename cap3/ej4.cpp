/*************************************************************************
* Escriba un programa que tenga como entrada enteros positivos n y r.    *
* si r<=n, imprima las combinaciones de 1,2,3,... , n tomadas r a la vez  *
**************************************************************************/

#include <iostream>
using namespace std;

//  Funcion para calcular el factorial
long long factorial(int n) {
	long long resultado = 1;
	for (int i=2; i<=n; i++) {
		resultado *= i;
	}
	return resultado;
}

// Funcion para calcular combinaciones
long long calcularCombinaciones(int n, int r) {
	if (r>n || r<0) {
		return -1;
	}
	if (r==0 || r==n) {
		return 1;
	}
	// Optimizar C(n,r) = C(n, n-r), usar el menor
	if (r>n-r) {
		r = n-r;
	}
	
	long long resultado = 1;
	for (int  i=0; i<r; i++) {
		resultado *= (n-i);
		resultado /= (i+1);
	}
	return resultado;
}

// Funcion recursiva para generar combinaciones
void generarCombinaciones(int arr[], int combinacion[], int n, int r,
				int inicio, int nivel, int &contador) {
	if (nivel == r) {
		cout << contador << ". ";
		for (int i=0; i<r; i++) {
			cout << combinacion[i];
			if (i<r -1) cout << " ";
		}
		cout << endl;
		contador++;
		return;
	}
	// Generar combinaciones desde inicio para evitar repeticiones
	for (int i=inicio; i<n; i++) {
		combinacion[nivel] = arr[i];
		// llamada recursiva con i+1 para mantener orden ascendente
		generarCombinaciones(arr, combinacion, n, r, i+1, nivel+1, contador);
	}
}

void imprimirCombinaciones(int n, int r) {
	if (r>n || n<=0 || r<0) {
		cout << "Error. Debe cumplirse que 0 <= r <=n y n>0\n" << endl;
		return;
	}
	// Crear arreglo con numeros de 1 a n
	int* arr = new int[n];
	for (int i=0; i<n; i++) {
		arr[i] = i+1;
	}
	// Arreglo para almacenar cada combinacion
	int* combinacion = new int[r];
	
	cout << "\nCombinaciones de {1, 2, ... " << n << "} tomadas " << r << " a la vez" << endl;
	cout << "--------------------------------" << endl;
	
	int contador = 1;
	generarCombinaciones(arr, combinacion, n, r, 0, 0, contador);
	
	cout << "--------------------------------" << endl;
	cout << "Total de combinaciones: " << (contador - 1) << endl;
	
	delete[] arr;
	delete[] combinacion;
}

void combinaciones(){
	int n, r;
	cout << "Ingrese n: ";
	cin  >> n;
	cout << "Ingrese r: ";
	cin  >> r;
	
	if (n <= 0 || r < 0) {
		cout << "Error. n debe ser positivo y r no puede ser negativo\n" << endl;
		return;
	}
	if (r > n) {
		cout << "Error. r debe ser menor o igual que n\n" << endl;
		return;
	}
	
	imprimirCombinaciones(n,r);
	
	long long comb = calcularCombinaciones(n, r);
	
	cout << "\nResultado: C(" << n << "," << r << ") = " << comb << endl;
	cout << "Hay " << comb << " combinaciones diferentes" << endl;
	cout << "\n::::::::::::::::::::::::::::::::::::::::::\n" << endl;
}

void mostraMenu(){
	int opcion;
	do {
		cout << "Calculo de combinaciones C(n,r)" << endl;
		cout << "Formula: C(n,r) = n! / (r! * (n-r)!)\n" << endl;
		cout << "1. Calcular" << endl;
		cout << "0. Salir" << endl;
		cout << "\nSeleccione una opcion: ";
		cin  >> opcion;
		
		switch (opcion) {
			case 1:
				combinaciones();
				break;
			case 0:
				cout << "\nGracias por usar el programa" << endl;
				break;
			default:
				cout << "\nOpcion invalida. Intente nuevamente" << endl;
				break;
		} 
	} while (opcion != 0);
}

int main() {
	
	mostraMenu();
	return 0;
}