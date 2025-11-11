#include <iostream>
using namespace std;

// Funcion para calcular el factorial de un numero
long long calcularFactorial(int num)
{
	long long resultado = 1;
	for (int i = 2; i <= num; i++)
	{
		resultado *= i;
	}
	return resultado;
}

// Funcion para calcular permutaciones P(n,r) = n!/ (n-r)!
long long calcularPermutaciones(int n, int r)
{
	// Validar que r<=n
	if (r > n)
	{
		return -1; // Indica error
	}
	// Si r es 0, hay una permutacion (no selecciona nada)
	if (r == 0)
	{
		return 1;
	}
	// Optimizar calculo de fact para numeros grandes
	long long resultado = 1;
	for (int i = 0; i < r; i++)
	{
		resultado *= (n - i);
	}
	return resultado;
}

void permutaciones()
{
	int n, r;
	cout << "Ingrese n: ";
	cin >> n;

	cout << "Ingrese r: ";
	cin >> r;

	// Validaciones
	if (n <= 0 || r < 0)
	{
		cout << "Error! n debe ser positivo y r no puede ser negativo." << endl;
		return;
	}
	if (r > n)
	{
		cout << "Error! r debe ser menor o igual que n." << endl;
		return;
	}
	long long permutaciones = calcularPermutaciones(n, r);

	cout << "\nResultado: P(" << n << "," << r << ") = " << permutaciones << endl;
	cout << "Hay " << permutaciones << " formas diferentes de ordenar " << r << " objetos tomados de " << n << ".\n" << endl;
}

void mostrarMenu()
{
	int opcion;

	do
	{
		cout << "Calculadora de permutaciones P(n,r)" << endl;
		cout << "Formula: P(n,r) = n! / (n-r)!" << endl
			 << endl;
		cout << "1. Calcular permutaciones" << endl;
		cout << "0. Salir" << endl;
		cout << "\nSeleccione una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			permutaciones();
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

int main()
{
	mostrarMenu();
	return 0;
}