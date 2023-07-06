#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Criterio 1: Beeficio Maximo
void mochila1(int M, vector<int> &b, vector<int> &p, vector<double> &x)
{
    int n = x.size();
    for (int i = 0; i < n; i++)
    { // se inicializa con ceros
        x[i] = 0;
    }
    int pesoAct = 0;

    vector<int> visitados(n, 0);
    int mayor;

    while (pesoAct < M)
    {
        int i;
        int pos;
        mayor = -1;
        for (int k = 0; k < b.size(); k++)
        {
            if ((b[k] > mayor) && (visitados[k] == 0))
            { //{20,60,40,30,66};
                mayor = b[k];
                pos = k;
            }
        }

        visitados[pos] = 1;
        i = pos;

        if (pesoAct + p[i] <= M)
        {
            x[i] = 1;
            pesoAct = pesoAct + p[i];
        }
        else
        {
            x[i] = (M - pesoAct) / ((double)p[i]); // para obtener decimal en la division
            pesoAct = M;
        }
    }
}

// Criterio 2: Peso minimo
void mochila2(int M, vector<int> &b, vector<int> &p, vector<double> &x)
{
    int n = x.size();
    for (int i = 0; i < n; i++)
    { // se inicializa con ceros
        x[i] = 0;
    }
    int pesoAct = 0;

    vector<int> visitados(n, 0);
    int menor;

    while (pesoAct < M)
    {
        int i;
        int pos;
        menor = std::numeric_limits<int>::max();
        for (int k = 0; k < b.size(); k++)
        {
            if ((b[k] < menor) && (visitados[k] == 0))
            { //{20,60,40,30,66};
                menor = b[k];
                pos = k;
            }
        }

        //cout << "menor " << menor << endl;
        visitados[pos] = 1;
        i = pos;


        if (pesoAct + p[i] <= M)
        {
            x[i] = 1;
            pesoAct = pesoAct + p[i];
        }
        else
        {
            x[i] = (M - pesoAct) / ((double)p[i]); // para obtener decimal en la division
            pesoAct = M;
        }
    }
}

// Criterio 3   : Mejor Proporcion
void mochila3(int M, vector<int> &b, vector<int> &p, vector<double> &x)
{
    int n = x.size();
    for (int i = 0; i < n; i++)
    { // se inicializa con ceros
        x[i] = 0;
    }
    int pesoAct = 0;

    vector<int> visitados(n, 0);
    vector<double> proporciones(n, 0);
    for (int i = 0; i < n; i++)
    {
        proporciones[i] = (double)b[i] / p[i]; // valor / peso
    }

    double mayor;

    while (pesoAct < M)
    {
        int i;
        int pos;
        mayor = -1;
        for (int k = 0; k < b.size(); k++)
        {
            if ((proporciones[k] > mayor) && (visitados[k] == 0))
            { //{20,60,40,30,66};
                mayor = proporciones[k];
                pos = k;
            }
        }

        visitados[pos] = 1;
        i = pos;

        if (pesoAct + p[i] <= M)
        {
            x[i] = 1;
            pesoAct = pesoAct + p[i];
        }
        else
        {
            x[i] = (M - pesoAct) / ((double)p[i]); // para obtener decimal en la division
            pesoAct = M;
        }
    }
}






void ejemplo1()
{
    int M = 10;
    vector<int> valoresObjetos = {10, 9, 9, 9};     // b
    vector<int> pesosObjetos = {10, 3, 3, 4};       // p
    vector<double> solucion(valoresObjetos.size()); // X

    cout << "Criterio 1:\n";
    mochila1(M, valoresObjetos, pesosObjetos, solucion);
    double valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;

    cout << "Criterio 2:\n";
    mochila2(M, valoresObjetos, pesosObjetos, solucion);
    valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;

    cout << "Criterio 3:\n";
    mochila3(M, valoresObjetos, pesosObjetos, solucion);
    valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;
}

void ejemplo2()
{
    int M = 10;
    vector<int> valoresObjetos = {10,1,1,1};      // b
    vector<int> pesosObjetos = {10,3,3,4};        // p
    vector<double> solucion(valoresObjetos.size()); // X

    cout << "Criterio 1:\n";
    mochila1(M, valoresObjetos, pesosObjetos, solucion);
    double valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;
    
    cout << "Criterio 2:\n";
    mochila2(M, valoresObjetos, pesosObjetos, solucion);
    valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;

    cout << "Criterio 3:\n";
    mochila3(M, valoresObjetos, pesosObjetos, solucion);
    valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;
}

void ejemplo3()
{
    int M = 20;
    vector<int> valoresObjetos = {25, 24, 15};      // b
    vector<int> pesosObjetos = {18, 15, 10};        // p
    vector<double> solucion(valoresObjetos.size()); // X

    cout << "Criterio 1:\n";
    mochila1(M, valoresObjetos, pesosObjetos, solucion);
    double valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;

    cout << "Criterio 2:\n";
    mochila2(M, valoresObjetos, pesosObjetos, solucion);
    valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;

    cout << "Criterio 3:\n";
    mochila2(M, valoresObjetos, pesosObjetos, solucion);
    valorTotal = 0;
    for (int i = 0; i < solucion.size(); i++)
    {
        cout << "Obj " << i + 1 << " => s:" << solucion[i] << " | peso:" << pesosObjetos[i] << " | valor:" << valoresObjetos[i] << " = " << solucion[i] * valoresObjetos[i] << endl;
        valorTotal += (solucion[i] * valoresObjetos[i]);
    }
    cout << "Valor Total: " << valorTotal << endl;
}


int main()
{
    ejemplo1();
    cout << endl;
    ejemplo2();
    cout << endl;
    ejemplo3();

}
