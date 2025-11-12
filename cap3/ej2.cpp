/*************************************************************************
* Escriba un programa que tenga como entrada enteros positivos n y r.    *
* si r<=n, imprima las permtaciones de 1,2,3,... , n tomadas r a la vez  *
**************************************************************************/

#include <iostream>
using namespace std;

// Funcion para calcular permutaciones
long long calcularPermutaciones(int n, int r) {
	if (r>n) {
		return -1;
	}
	if(r==0) {
		return 1;
	}
	long long resultado = 1;
	for (int i=0; i<r; i++) {
		resultado *=(n - i);
	}
	return resultado;
}

// Funcion recursiva auxiliar 
void generarPermutacionesRecursiva(int arr[], bool usado[], int permutacion[],
	int n, int r, int nivel, int &contador){
	// caso base. cuando se completa una permutacion de tamano r
	if (nivel == r) {
		cout << contador << ". ";
		for (int i=0; i<r; i++) {
			cout << permutacion[i];
			if (i<r-1) cout << " ";
		}
		cout << endl;
		contador++;
		return;
	}
	// Probar cada numero de 1 a n
	for (int i=0; i<n; i++) {
		if (!usado[i]){
			usado[i] = true;
			permutacion[nivel] = arr[i];
			
			// REcursion siguiente nivel
			generarPermutacionesRecursiva(arr, usado, permutacion, n, r, nivel+1, contador);
			
			usado[i] = false; // desmarcar
		}
	}
}

// Funcion para imprimir permutaciones
void imprimirPermutaciones(int n, int r){
	if (r > n || n <= 0 || r < 0) {
		cout << "Error. Debe cumplirse que 0 <= r <= n y n > 0" << endl;
		return;
	}
	// Crear arreglo con numeros de 1 a n
	int* arr = new int[n];
	for (int i=0; i<n; i++) {
		arr[i] = i+1;
	}
	// Arreglo auxiliar
	bool* usado = new bool[n];
	int* permutacion = new int[r];
	
	// Inicializar todos como no usados
	for (int i=0; i<n; i++){
		usado[i] = false;
	}
	
	cout << "\nPermutaciones de {1,2,3, ...," << n << "} tomadas " << r << " a la vez" << endl;
	cout << "-------------------------------------" << endl;
	
	int contador = 1;
	generarPermutacionesRecursiva(arr, usado,  permutacion, n, r,0, contador);
	
	cout << "-------------------------------------" << endl;
	cout << "Total de permutaciones: " << (contador - 1) << endl;
	
	// Liberar memoria
	delete[] arr;
	delete[] usado;
	delete[] permutacion;
}

//  validar y mostrar resultados
void opcionPermutaciones() {
	int n,r;
	
	cout << "Ingrese n: ";
	cin  >> n;
	cout << "Ingrese r: ";
	cin  >> r;
	
	if (n<=0 || r<0) {
		cout << "Error. n debe ser positivo y r no puede ser negativo." << endl;
		return;
	}
	
	if (r > n) {
		cout << "Error. r debe ser menor o igual que n." << endl;
		return;
	}
	
	imprimirPermutaciones(n, r);
	
	long long perm = calcularPermutaciones(n,r);
	
	cout << "\nResultado: P(" << n << "," << r << ") = " << perm << endl;
	cout << "Hay " << perm << " formas diferentes de ordenar." << endl;
	cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::\n" << endl;
}

void mostrarMenu(){
	int opcion;
	do {
		cout << "Calculo de permutaciones" << endl;
		cout << "Formula: P(n,r) = n! / (n-r)!\n" << endl;
		cout << "1. Calcular" << endl;
		cout << "0. Salir" << endl;
		cout << "\nSeleccione una opcion: ";
		cin  >> opcion;
		
		switch (opcion) {
			case 1:
				opcionPermutaciones();
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
	
	mostrarMenu();
	return 0;
}