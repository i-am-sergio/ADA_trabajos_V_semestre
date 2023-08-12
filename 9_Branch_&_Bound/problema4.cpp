#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define N 5

vector<vector<int>> matrizCostos = {
        {0, 3, 10, 11, 7},
        {3, 0, 8, 12, 9},
        {10, 8, 0, 9, 4},
        {11, 12, 9, 0, 5},
        {7, 9, 4, 5, 0}
};

struct Nodo
{
    int nivel;
    int ciudadActual;
    vector<bool> visitado;
    int costoCamino;
    vector<int> camino;
};

int calcularCotaInferior(vector<vector<int>>& matrizCostos, Nodo nodo)
{
    int cota = nodo.costoCamino;

    for (int i = 0; i < N; i++)
    {
        if (!nodo.visitado[i])
        {
            int minCosto = numeric_limits<int>::max();
            for (int j = 0; j < N; j++)
            {
                if (i != j && !nodo.visitado[j])
                {
                    minCosto = min(minCosto, matrizCostos[i][j]);
                }
            }
            cota += minCosto;
        }
    }

    return cota;
}

struct ComparadorNodos
{
    bool operator()(const Nodo& a, const Nodo& b)
    {
        return calcularCotaInferior(matrizCostos, a) > calcularCotaInferior(matrizCostos, b);
    }
};

int encontrarCostoMinimo(vector<vector<int>>& matrizCostos, vector<int>& caminoOptimo)
{
    priority_queue<Nodo, vector<Nodo>, ComparadorNodos> colaPrioridad;

    Nodo nodoInicial;
    nodoInicial.nivel = 0;
    nodoInicial.ciudadActual = 0;
    nodoInicial.visitado.assign(N, false);
    nodoInicial.visitado[0] = true;
    nodoInicial.costoCamino = 0;
    nodoInicial.camino.push_back(0);

    int costoMinimo = numeric_limits<int>::max();

    colaPrioridad.push(nodoInicial);

    while (!colaPrioridad.empty())
    {
        Nodo nodoActual = colaPrioridad.top();
        colaPrioridad.pop();

        if (nodoActual.nivel == N - 1)
        {
            int costoTotal = nodoActual.costoCamino + matrizCostos[nodoActual.ciudadActual][0];
            if (costoTotal < costoMinimo)
            {
                costoMinimo = costoTotal;
                caminoOptimo = nodoActual.camino;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (!nodoActual.visitado[i])
            {
                Nodo nuevoNodo;
                nuevoNodo.nivel = nodoActual.nivel + 1;
                nuevoNodo.ciudadActual = i;
                nuevoNodo.visitado = nodoActual.visitado;
                nuevoNodo.visitado[i] = true;
                nuevoNodo.costoCamino = nodoActual.costoCamino + matrizCostos[nodoActual.ciudadActual][i];
                nuevoNodo.camino = nodoActual.camino;
                nuevoNodo.camino.push_back(i);

                if (calcularCotaInferior(matrizCostos, nuevoNodo) < costoMinimo)
                {
                    colaPrioridad.push(nuevoNodo);
                }
            }
        }
    }

    return costoMinimo;
}

void imprimirCaminoOptimo(const vector<int>& caminoOptimo)
{
    cout << "Camino Optimo: ";
    for (int ciudad : caminoOptimo)
    {
        cout << ciudad << " ";
    }
    cout << "0" << endl;  // Regresar a la ciudad inicial
}

int main()
{
    vector<int> caminoOptimo;
    int costoOptimo = encontrarCostoMinimo(matrizCostos, caminoOptimo);

    cout << "Costo Optimo del Viaje: " << costoOptimo << endl;
    imprimirCaminoOptimo(caminoOptimo);

    return 0;
}
