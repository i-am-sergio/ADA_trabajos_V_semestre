#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100; // Máximo número de elementos
int n; // Número de elementos
int P; // Capacidad de la mochila
int t[MAX_N]; // Vector con los valores de los elementos
int w[MAX_N]; // Vector con los pesos de los elementos
vector<int> bestSol; // Mejor solución encontrada

void printTree(vector<int>& sol, int level, int value, int weight) {
    for (int i = 0; i < level; i++) {
        cout << "\t"; // Indentar para mostrar la jerarquía del árbol
    }
    cout << "Level: " << level << " | Value: " << value << " | Weight: " << weight << " | Selected: ";
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " ";
    }
    cout << endl;

    if (level == n) {
        return;
    }

    // No elegir el elemento actual
    printTree(sol, level + 1, value, weight);

    // Elegir el elemento actual si el peso no excede la capacidad de la mochila
    if (weight + w[level] <= P) {
        sol[level] = 1;
        printTree(sol, level + 1, value + t[level], weight + w[level]);
        sol[level] = 0;
    }
}

void backtracking(vector<int>& sol, int level, int value, int weight) {
    if (level == n) {
        if (value > bestSol[0]) {
            bestSol = sol;
            bestSol[0] = value;
        }
        return;
    }

    // No elegir el elemento actual
    backtracking(sol, level + 1, value, weight);

    // Elegir el elemento actual si el peso no excede la capacidad de la mochila
    if (weight + w[level] <= P) {
        sol[level] = 1;
        backtracking(sol, level + 1, value + t[level], weight + w[level]);
        sol[level] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> w[i];
    }
    cin >> P;

    vector<int> sol(n, 0); // Solución parcial inicialmente vacía
    bestSol = vector<int>(n + 1, 0); // Mejor solución inicialmente vacía

    backtracking(sol, 0, 0, 0);

    // Mostrar el árbol binario
    cout << "Arbol Binario Generado:" << endl;
    printTree(sol, 0, 0, 0);

    // Mostrar la mejor solución encontrada
    cout << "Mejor valor: " << bestSol[0] << endl;
    cout << "Elementos seleccionados: \n";
    for (int i = 0; i < n; ++i) {
        if (bestSol[i + 1] == 1) {
            cout << i + 1 << " -> " << "valor: "<<t[i] <<"| peso: "<< w[i]<< endl;
        }
    }
    cout << endl;

    return 0;
}
