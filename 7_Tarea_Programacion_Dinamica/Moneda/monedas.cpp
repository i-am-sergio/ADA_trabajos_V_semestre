#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000; // Valor infinito para representar casos no resolubles

template <typename T>
using Matrix = std::vector<std::vector<T>>;

// Función para calcular el mínimo de dos números
int min(int a, int b) {
    return (a < b) ? a : b;
}

void printMatrix(Matrix<int>& M){
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++)
            if(M[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << M[i][j] << "\t";
        cout << "\n";
    }
}

// Función de cambio con programación dinámica
int CambioDeMonedas(int k, int q, vector<int>& c) {
    // Crear la tabla DP para guardar los resultados de los subproblemas
    Matrix<int> DP(k + 1, vector<int>(q + 1, 0));

    // Rellenar los casos base
    for (int i = 1; i <= k; i++) {
        DP[i][0] = 0;
    }
    for (int j = 1; j <= q; j++) {
        DP[0][j] = INF;
    }

    // Rellenar la tabla usando la ecuación de cambio
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= q; j++) {
            if (c[i] <= j) {
                DP[i][j] = min(DP[i - 1][j], 1 + DP[i][j - c[i]]);
            } else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }
    printMatrix(DP);

    // Reconstruir la solución óptima y obtener el número mínimo de monedas
    vector<int> x(k + 1, 0);
    int i = k, j = q;
    while (i != 0 && j != 0) {
        if (DP[i][j] == DP[i - 1][j]) {
            i--;
        } else {
            x[i]++;
            j -= c[i];
        }
    }

    cout << "\nSolucion: Numero de monedas de cada tipo:\n";
    for (int i = 1; i <= k; i++) {
        cout << "\t- Tipo " << c[i] << " => " << x[i] << " monedas\n";
    }

    return DP[k][q]; // El resultado óptimo está en DP[k][q]
}

int main() {
    int k, q;
    cout << "Ingrese el numero de tipos de monedas: ";
    cin >> k;

    vector<int> c(k + 1); // valores de las monedas (el índice 0 no se usa)
    cout << "Ingrese los valores de las monedas:\n";
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }

    cout << "Ingrese la cantidad P que desea obtener de cambio: ";
    cin >> q;

    int resultadoCambio = CambioDeMonedas(k, q, c);
    if (resultadoCambio == INF) {
        cout << "No es posible obtener el cambio con las monedas que hay.\n";
    } else {
        cout << "El numero minimo de monedas necesarias para obtener " << q << " es: " << resultadoCambio << endl;
    }

    return 0;
}
