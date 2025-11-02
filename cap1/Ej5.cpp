/****************************************************
	Escriba un programa para determinar el MCM de
	dos numeros enteros positivos
*****************************************************/

#include <iostream>
using namespace std;

// Funcion para calcular el mcd
int calcularMCD(int a, int b) {
	while (b != 0) {
	int temp = b;
	b = a % b;
	a = temp;
	}
	return a;
}

int calcularMCM(int a, int b) {
	//  mcm = (a * b) / mcd(a,b)
	return a * b / calcularMCD(a,b);	
}

int main () {
	
	int num1, num2;
	
	cout << "Calculadora de MCM para dos positivos" << endl;
	cout << "\n1er numero positivo: ";
	cin  >> num1;
	cout << "2do numero positivo: ";
	cin  >> num2;
	
	// Validar que sean positivos
	if ( num1 <= 0 || num2 <= 0 ) {
		cout << "\nError: Debe ingresar numeros enteros positivos" << endl;
		return 1;
	}
	
	int mcm = calcularMCM(num1, num2);
	
	cout << "\nEl MCM de " << num1 << " y " << num2 << " es " << mcm << endl;
	
	return 0;
}