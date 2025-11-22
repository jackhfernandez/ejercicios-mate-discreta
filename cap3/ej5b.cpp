/*******************************************************************************
* Programa: Generador de secuencia de Fibonacci                                *
* Tarea: Escriba una funcion no recursiva que con entrada k imprima            *
*        los k-numeros de Fibonacci                                            *
*******************************************************************************/

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

namespace Config {
	const int VALOR_MINIMO = 1;
	const int VALOR_MAXIMO = 93;
}

namespace {
	const int OPCION_CALCULAR = 1;
	const int OPCION_SALIR    = 0;
}

void limpiaBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int solicitaK() {
	int k;
	cout << "\nIngrese K (1-" << Config::VALOR_MAXIMO << "): ";
	cin  >> k;
	
	if (cin.fail()) {
		limpiaBuffer();
		return -1;
	}
	return k;
}

bool esValido(int k) {
	return k >= Config::VALOR_MINIMO && k <= Config::VALOR_MAXIMO;
}

void imprimeEncabezado(int k) {
	cout << "\nSecuencia de los primeros " << k << " numeros de fibonacci:\n" << endl;
}

void imprimeNumerosBase(int k) {
	if (k >= 1) {
		cout << "0";
	}
	if (k >= 2) {
		cout << " 1";
	}
}

void calculaEImprimeRestantes(int k) {
	if (k <= 2) return;
	
	long long anterior = 0;
	long long actual   = 1;
	
	for (int i=3; i<=k; i++) {
		long long siguiente = anterior + actual;
		cout << " " << siguiente;
		anterior = actual;
		actual = siguiente;
	}
}

void imprimeFibonacci() {
	int k = solicitaK();
	if (!esValido(k)) {
		if (k < Config::VALOR_MINIMO) {
			cout << "\nError. Debe ingresar un numero positivo" << endl;
		} else {
			cout << "\nError. El valor maximo permitido es " << Config::VALOR_MAXIMO << endl;
		}
		return;
	}
	imprimeEncabezado(k);
	imprimeNumerosBase(k);
	calculaEImprimeRestantes(k);
	
	cout << "\n\n" << string(50, '-') << "\n" << endl;
}

void mostrarOpcionesMenu() {
	cout << "Generador de numeros de fibonacci" << endl;
	cout << "\n1. Calcular" << endl;
	cout << "0. Salir" << endl;
	cout << "\nSeleccione una opcion: ";
}

void procesarOpcion(int opcion) {
	switch (opcion) {
		case OPCION_CALCULAR:
			imprimeFibonacci();
			break;
		case OPCION_SALIR:
			cout << "\nGracias por usar el programa\n" << endl;
			break;
		default:
			cout << "\nOpcion invalida. Intente de nuevo\n" << endl;
			break;
	}
}

int solicitarOpcion() {
	int opcion;
	cin >> opcion;
	if (cin.fail()) {
		limpiaBuffer();
		return -1;
	}
	return opcion;
}

void mostrarMenu() {
	int opcion;
	
	do {
		mostrarOpcionesMenu();
		opcion = solicitarOpcion();
		procesarOpcion(opcion);
		
	} while (opcion != OPCION_SALIR);
}

int main (){
	
	cout << fixed << setprecision(0);
	
	mostrarMenu();
	return 0;
}