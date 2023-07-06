#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

void devolverCambio(int P, vector<int> &C, vector<int> &X)
{
    sort(C.begin(), C.end());
    int n = C.size();
    int actual = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    { // se inicializa con ceros
        X[i] = 0;
    }
    while (actual != P)
    {
        while ((C[j] > (P - actual)) && (j > 0))
        {
            j = j - 1;
        }
        if (j == 0 && C[j] > (P - actual))
        {
            std::cout << "No existe solucion" << std::endl;
            break; // Agregamos un break para salir del bucle si no hay solución
        }
        X[j] = (P - actual) / (C[j]);  // Agregamos una conversión explícita a double
        actual = actual + C[j] * X[j]; // insertar
    }
}

/*
otra version
vector<int> cambioMonedas(int cantidad, const vector<int>& monedas) {
    vector<int> cambio(monedas.size(), 0);
    // Ordenamos las monedas de mayor a menor
    vector<int> sortedmonedas = monedas;
    sort(sortedmonedas.rbegin(), sortedmonedas.rend());

    // Recorremos las monedas y vamos calculando el cambio
    for (int i = 0; i < sortedmonedas.size(); i++) {
        while (cantidad >= sortedmonedas[i]) {
            cambio[i]++;
            cantidad -= sortedmonedas[i];
        }
    }

    return cambio;
}
*/

void ejemplo1()
{
    int cantidad = 389;
    vector<int> monedas = {2, 5, 10, 20, 50, 100, 200}; // Diapositivas de la clase
    vector<int> solucion(monedas.size());
    devolverCambio(cantidad, monedas, solucion);

    cout << "Cambio: " << cantidad << endl;
    cout << "valor  \t| cantidad\n";

    for (int i = 0; i < monedas.size(); i++)
        cout << monedas[i] << " \t| " << solucion[i] << endl;
}

void ejemplo2()
{
    int cantidad = 180;
    vector<int> monedas = {100, 90, 1};
    vector<int> solucion(monedas.size());
    devolverCambio(cantidad, monedas, solucion);

    cout << "Cambio: " << cantidad << endl;
    cout << "valor  \t| cantidad\n";
    for (int i = 0; i < monedas.size(); i++)
        cout << monedas[i] << " \t| " << solucion[i] << endl;
}

int main()
{
    cout << "Ejemplo 1" << endl;
    ejemplo1();

    cout << "\nEjemplo 2" << endl;
    ejemplo2();

    return 0;
}