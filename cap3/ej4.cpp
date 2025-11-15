/*************************************************************************
* Escriba un programa que tenga como entrada enteros positivos n y r.    *
* si r<=n, imprima las combinaciones de 1,2,3,... , n tomadas r a la vez  *
**************************************************************************/

#include <iostream>
using namespace std;

// Funcion para calcular combinaciones
long long calcularCombinaciones(int n, int r) {
	if (r>n) {
		return -1;
	}
	if (r==0) {
		return 1;
	}
	long long resultado = 1;
	for (int i=0; i<r; i++) {
		resultado *=(n-i);
	}
	return resultado;	
}

// Funcion recursiva auxiliar
void generarCombinacionesRecursiva(int arr[], bool usado, int combinacion,
		int n, int r, int nivel, int &contador){
	if (nivel == r){
		cout << contador << "."
		for (int i=0; i<r; i++) {
			cout << permutacion[i];
			if (i<r-1) cout << "";
		}
		cout << endl;
		contador++;
		return;
	}
	// Probar cada numero de 1 a n
	for (int i=0; i<n; i++) {
		if (!usado[i]) {
			usado[i] = true;
			combinacion[nivel] = arr[i];
			// Recursion siguiente nivel
			generarCombinacionesRecursiva(arr, usado, combinacion,n,r,nivel,contador);
			usado[i] = false; // desmarcar
		}
	}
}

// Funcion para imprimir combinaciones
void imprimirCombinaciones(int n, int r) {
	if (r>n || n<=0 || r<0) {
		cout << "Error. Debe cumplirse"
	}
}

void mostraMenu(){
	int opcion;
	do {
		cout << "Calculo de combinaciones C(n,r)" << endl;
		cout << "Formula: C(n,r) = n! / r! * (n-r)!\n" << endl;
		cout << "1. Calcular" << endl;
		cout << "0. Salir" << endl;
		cout << "\nSeleccione una opcion: ";
		cin  >> opcion;
		
		switch (opcion) {
			case 1:
				//
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
	
	//
	return 0;
}