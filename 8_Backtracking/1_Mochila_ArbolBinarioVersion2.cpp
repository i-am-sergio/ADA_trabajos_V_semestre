#include <iostream>
#include <vector>
using namespace std;

class Objeto {
public:
    int peso;
    int beneficio;
    Objeto(int p, int b) {
        peso = p;
        beneficio = b;
    }
};

void actualizarSolucion(vector<int>& solucion, vector<Objeto>& objetos, vector<int>& mochilaFinal, int& pesoFinal, int& beneficioFinal) {
    int beneficioTotal = 0;
    int pesoTotal = 0;
    for (int i = 0; i < objetos.size(); i++) {
        if (solucion[i] == 1) {
            beneficioTotal += objetos[i].beneficio;
            pesoTotal += objetos[i].peso;
        }
    }
    if (beneficioTotal > beneficioFinal) {
        for (int i = 0; i < objetos.size(); i++) {
            mochilaFinal[i] = solucion[i];
        }
        pesoFinal = pesoTotal;
        beneficioFinal = beneficioTotal;
    }
}

bool validarSolucion(const vector<int>& solucion, int etapa, vector<Objeto>& objetos, int capacidadMochila) {
    int pesoTotal = 0;
    for (int i = 0; i <= etapa; i++) {
        if (solucion[i] == 1) {
            pesoTotal += objetos[i].peso;
        }
    }
    return pesoTotal <= capacidadMochila;
}

void mostrarArbolBinario(vector<int>& solucion, int nivel, vector<Objeto>& objetos) {
    if (nivel >= objetos.size()) return;

    cout << "Nivel " << nivel + 1 << ": ";
    for (int i = 0; i <= nivel; i++) {
        if (solucion[i] == 0) {
            cout << "No ";
        } else if (solucion[i] == 1) {
            cout << "Si ";
        } else {
            cout << "N/A ";
        }
    }
    cout << endl;

    // Generar el subárbol tomando el objeto i
    solucion[nivel] = 1;
    mostrarArbolBinario(solucion, nivel + 1, objetos);

    // Generar el subárbol sin tomar el objeto i
    solucion[nivel] = 0;
    mostrarArbolBinario(solucion, nivel + 1, objetos);

    // Restaurar el valor del nodo para que en el siguiente nivel sea considerado como "objeto no estudiado"
    solucion[nivel] = -1;
}



void MochilaBackTracking(vector<int>& solucion, int etapa, vector<Objeto>& objetos, vector<int>& mochilaFinal, int& pesoFinal, int& beneficioFinal, int M) {
    int i = 0;
    if (etapa > objetos.size() - 1) return;
    do {
        //mostrarArbolBinario(solucion, etapa, objetos); // Mostrar el árbol binario
        solucion[etapa] = i;
        if (validarSolucion(solucion, etapa, objetos, M)) {
            if (etapa == objetos.size() - 1)
                actualizarSolucion(solucion, objetos, mochilaFinal, pesoFinal, beneficioFinal);
            else
                MochilaBackTracking(solucion, etapa + 1, objetos, mochilaFinal, pesoFinal, beneficioFinal, M);
        }
        i++;
    } while (solucion[etapa] != 1);
    solucion[etapa] = -1;
}

int main() {
    int n, M;
    cout << "Ingrese el numero de objetos: ";
    cin >> n;

    vector<int> p(n), b(n); // pesos y beneficios de los objetos

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

    vector<Objeto> objetos;
    for (int i = 0; i < n; i++) {
        objetos.push_back(Objeto(p[i], b[i]));
    }

    vector<int> solucion_actual(n, -1);
    vector<int> mochilaFinal(n, 0);
    int pesoFinal = 0;
    int beneficioFinal = 0;

    cout << "Arbol binario de decisiones:\n";
    mostrarArbolBinario(solucion_actual, 0, objetos);

    MochilaBackTracking(solucion_actual, 0, objetos, mochilaFinal, pesoFinal, beneficioFinal, M);

    cout << "Solucion optima Mochila: ";
    for (int i = 0; i < n; i++) {
        if (mochilaFinal[i] == 1) {
            cout << "Objeto " << i + 1 << " ";
        }
    }
    cout << endl;
    cout << "Valor Optimo: " << beneficioFinal << endl;
    return 0;
}
