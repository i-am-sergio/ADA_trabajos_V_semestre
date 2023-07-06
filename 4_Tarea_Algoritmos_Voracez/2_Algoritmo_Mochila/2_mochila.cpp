#include <iostream>
#include <array>
#include <vector>
#include <tuple>
using namespace std;

// Criterio: Valor Maximo
void mochila1(int M, array<int, 4> &b, array<int, 4> &p, array<double, 4> &x) { // 30 50 40/2 valor: 146
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

        mayor = b[0];
        for (int k = 0; k < b.size(); k++)
        {
            if (b[k] > mayor && visitados[k] == 0)
            { //{20,60,40,30,66};
                mayor = b[k];
            }
        }

        for (int k = 0; k < b.size(); k++)
        {
            if (b[k] == mayor && visitados[k] == 0)
            {
                i = k;
                visitados[k] = 1;
            }
        }

        // cout << "mayor" << mayor << endl;

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

// Criterio: Peso Minimo
void mochila2(int M, array<int, 4> &b, array<int, 4> &p, array<double, 4> &x) { // 10 20 30 40 valor: 156
    int n = x.size();
    for (int i = 0; i < n; i++)
    { // se inicializa con ceros
        x[i] = 0;
    }

    vector<int> visitados(n, 0);
    int menor;

    int pesoAct = 0;
    while (pesoAct < M)
    {
        int i; // el mejor objeto restante

        for (int k = 0; k < p.size(); k++)
        {
            if (visitados[k] == 0)
            {
                menor = p[k];
            }
        }
        for (int k = n - 1; k >= 0; k--)
        {
            if (p[k] < menor && visitados[k] == 0)
            { //{20,60,40,30,66};
                menor = p[k];
            }
        }
        for (int k = n - 1; k >= 0; k--)
        {
            if (p[k] == menor && visitados[k] == 0)
            {
                i = k;
                visitados[k] = 1;
            }
        }
        // cout << menor << endl;

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



// Criterio: Mejor Proporcion
void mochila3(int M, array<int, 4> &b, array<int, 4> &p, array<double, 4> &x)
{
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
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
        for (int k = 0; k < n; k++)
        {
            if (visitados[k] == 0)
            {
                mayor = proporciones[k];
                i = k;
                break;
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (proporciones[k] > mayor && visitados[k] == 0)
            {
                mayor = proporciones[k];
                i = k;
            }
        }

        visitados[i] = 1;

        if (pesoAct + p[i] <= M)
        {
            x[i] = 1;
            pesoAct = pesoAct + p[i];
        }
        else
        {
            x[i] = (M - pesoAct) / static_cast<double>(p[i]); // para obtener decimal en la división
            pesoAct = M;
        }
    }
}


/*void mochila3(int M, array<int,5>& b, array<int,5>& p, array<double,5>& x){ //30 10 20 80%(50) valor: 164
    int n = x.size();
    for(int i=0; i<n; i++){ // se inicializa con ceros
        x[i] = 0;
    }
    int pesoAct = 0;

    vector<int> visitados(n,0);
    vector<double> proporciones(n,0);
    for(int i=0; i<n; i++){ // proporciones
        proporciones[i] = b[i]/((double)p[i]); // valor / peso
    }

    double mayor;

    while(pesoAct < M){
        int i;
        for(int k=0; k<p.size(); k++){
            if(visitados[k]==0){;
                mayor = proporciones[k];
            }
        }

        for(int k=0; k<n; k++){
            if(proporciones[k]>mayor && visitados[k]==0){ //{20,60,40,30,66};
                mayor = proporciones[k];
            }
        }
        for(int k=0; k<n; k++){
            if(proporciones[k]==mayor && visitados[k]==0){
                i = k;
                visitados[k] = 1;
            }
        }


        if(pesoAct+p[i] <= M) {
            x[i] = 1;
            pesoAct = pesoAct+p[i];
        }
        else {
            x[i] = (M-pesoAct)/((double)p[i]); // para obtener decimal en la division
            pesoAct = M;
        }
    }
}*/



/*
int main(){
    int M = 100;
    array<int,5> valoresObjetos = {20,60,40,30,66}; // b
    array<int,5> pesosObjetos = {10,50,40,20,30}; // p
    array<double,5> solucion; // X
    mochila1(M,valoresObjetos,pesosObjetos,solucion);

    double valorTotal = 0;
    for(int i=0; i<solucion.size();i++){
        cout<<"Obj "<<i+1<<" => s:"<<solucion[i]<<" | peso:"<<pesosObjetos[i]<<" | valor:"<<valoresObjetos[i]<<" = "<<solucion[i]*valoresObjetos[i]<<endl;
        valorTotal += (solucion[i]*valoresObjetos[i]);
    }
    cout<<"Valor Total: "<<valorTotal;
    return 0;
}*/

/*
int main(){
    int M = 20;
    array<int,3> valoresObjetos = {25,24,15}; // b
    array<int,3> pesosObjetos = {18,15,10}; // p
    array<double,3> solucion; // X
    mochila1(M,valoresObjetos,pesosObjetos,solucion);

    double valorTotal = 0;
    for(int i=0; i<solucion.size();i++){
        cout<<"Obj "<<i+1<<" => s:"<<solucion[i]<<" | peso:"<<pesosObjetos[i]<<" | valor:"<<valoresObjetos[i]<<" = "<<solucion[i]*valoresObjetos[i]<<endl;
        valorTotal += (solucion[i]*valoresObjetos[i]);
    }
    cout<<"Valor Total: "<<valorTotal;
    return 0;
}
*/

void ejemplo1()
{
    int M = 10;
    array<int, 4> valoresObjetos = {10, 9, 9, 9}; // b
    array<int, 4> pesosObjetos = {10, 3, 3, 4};   // p
    array<double, 4> solucion;                    // X

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
    array<int, 4> valoresObjetos = {10, 1, 1, 1}; // b
    array<int, 4> pesosObjetos = {10, 3, 3, 4};   // p
    array<double, 4> solucion;                    // X

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

int main()
{
    cout << "----- EJEMPLO 1 -----" << endl;
    ejemplo1();
    cout << "----- EJEMPLO 2 -----" << endl;
    ejemplo2();
    return 0;
}