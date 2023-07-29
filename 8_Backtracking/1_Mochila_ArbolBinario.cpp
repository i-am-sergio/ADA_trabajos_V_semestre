#include <iostream>
#include <vector>
using namespace std;

int valorOptimoActual = 0; // Valor óptimo actual
vector<int> solucionOptimaActual; // Solución óptima actual

void MostrarArbolBinario(int nivel, vector<int>& s) {
    if (nivel == s.size()) {
        return;
    }

    // Mostrar el estado actual del nodo
    cout << "Nivel " << nivel << ": [ ";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != -1) {
            cout <<" "<< s[i] << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << "]" << endl;

    // Prueba con el objeto no cogido
    s[nivel] = 0;
    MostrarArbolBinario(nivel + 1, s);
    // Prueba con el objeto cogido
    s[nivel] = 1;
    MostrarArbolBinario(nivel + 1, s);
    // Deshacer cambios para el retroceso
    s[nivel] = -1;
}

void Generar(int nivel, int n, int M, vector<int>& p, vector<int>& b, vector<int>& s, int& pact, int& bact) {
    if (nivel == n) {
        // Verificar si se alcanzó una solución completa
        if (pact <= M && bact > valorOptimoActual) {
            valorOptimoActual = bact;
            solucionOptimaActual = s;
        }
        return;
    }

    // Prueba con el objeto no cogido
    s[nivel] = 0;
    Generar(nivel + 1, n, M, p, b, s, pact, bact);

    // Prueba con el objeto cogido
    s[nivel] = 1;
    pact += p[nivel] * s[nivel];
    bact += b[nivel] * s[nivel];
    Generar(nivel + 1, n, M, p, b, s, pact, bact);

    // Deshacer cambios para el retroceso
    pact -= p[nivel] * s[nivel];
    bact -= b[nivel] * s[nivel];
    s[nivel] = -1;
}

int main() {
    int n, M;
    cout << "Ingrese el numero de objetos: ";
    cin >> n;

    vector<int> p(n), b(n); // pesos y beneficios de los objetos
    vector<int> s(n, -1); // Representación de la solución con árbol binario
    int pact = 0; // Peso actual
    int bact = 0; // Beneficio actual

    cout << "Ingrese los pesos de los objetos:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Ingrese los beneficios de los objetos:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << "Ingrese la capacidad de la mochila: ";
    cin >> M;

    cout << "Arbol Binario:" << endl;
    MostrarArbolBinario(0, s);
    Generar(0, n, M, p, b, s, pact, bact);

    cout << "Solucion optima:\n";
    for (int i = 0; i < n; i++) {
        if (solucionOptimaActual[i] == 1) {
            cout << "\tObjeto " << i + 1 << " => Peso:"<<p[i]<<" - Beneficio:"<<b[i]<<endl;
        }
    }
    cout << "Valor optimo: " << valorOptimoActual << endl;

    return 0;
}
