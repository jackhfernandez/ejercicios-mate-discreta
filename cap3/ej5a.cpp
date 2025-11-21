/*******************************************************************************
* Programa: Generador de secuencia de Fibonacci                                *
* Tarea: Escriba una funcion recursiva que con entrada k imprima               *
*        los k-numeros de Fibonacci                                            *
*******************************************************************************/

#include <iostream>
#include <limits>

const int FIBONACCI_BASE_CERO = 0;
const int FIBONACCI_BASE_UNO  = 1;
const int OPCION_CALCULAR     = 1;
const int OPCION_SALIR        = 0;

using namespace std;

int calcularFibonacci(int n) {
	if (n == 0) return FIBONACCI_BASE_CERO;
	if (n == 1) return FIBONACCI_BASE_UNO;
	
	return calcularFibonacci(n - 1) + calcularFibonacci(n-2);
}

void imprimirSecuenciaFibonacci(int k, int actual = 0) {
	if (actual >= k) {
		cout << endl;
		return;
	}
	cout << calcularFibonacci(actual);
	
	if (actual < k - 1) {
		cout << " ";
	}
	imprimirSecuenciaFibonacci(k, actual + 1);
}

int solicitarK() {
	int k;
	while (true) {
		cout << "Ingrese k (k > 0): ";
		cin  >> k;
		
		if (cin.fail()) {
			cin.clear(); // Limpia el estado de error
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta entrada invalida
			cout << "Error. Debe ingresar un numero entero." << endl;
			continue;
		}
		
		if (k <= 0) {
			cout << "Error. k debe ser mayor que cero." << endl;
			continue;
		}
		
		if (k > 15) {
			cout << "Advertencia. Valores grandes pueden tardar mucho tiempo" << endl;
		}
		return k;
	}
}

void ejecutarCalculo() {
	int k = solicitarK();
	
	cout << "Los primeros " << k << " numeros de Fibonacci son" << endl;
	imprimirSecuenciaFibonacci(k);
}

void pausar() {
	cout << "\nPresion Enter para continuar...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}

void mostrarMenu(){
	int opcion;
	do {
		cout << "Generador de secuencia de fibonacci\n" << endl;
		cout << "1. Calcular" << endl;
		cout << "0. Salir " << endl;
		cout << "\nSeleccione una opcion: ";
		cin  >> opcion;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nError. Opcion invalida. Intente de nuevo." << endl;
			pausar();
			continue;
		}
		switch (opcion) {
			case OPCION_CALCULAR:
				ejecutarCalculo();
				pausar();
				break;
				
			case OPCION_SALIR:
				cout << "\nGracias por usar el programa" << endl;
				pausar();
				break;
			default:
				cout << "Opcion invalidad. Intente de nuevo" << endl;
				break;
		}
	} while (opcion != OPCION_SALIR);
}

int main() {
	
	mostrarMenu();
	return 0;
}
