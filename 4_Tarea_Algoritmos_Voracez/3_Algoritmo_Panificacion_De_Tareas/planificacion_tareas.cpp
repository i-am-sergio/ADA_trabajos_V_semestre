#include <iostream>
#include <array>
#include <vector>
using namespace std;

void Factible(){

}

// Criterio: Valor Maximo
void mochila1(int M, array<int,3>& b, array<int,3>& p, array<double,3>& x){ //30 50 40/2 valor: 146
    int n = x.size();
    for(int i=0; i<n; i++){ // se inicializa con ceros
        x[i] = 0;
    }
    int pesoAct = 0;

    vector<int> visitados(n,0);
    int mayor;

    while(pesoAct < M){
        int i;

        mayor = b[0];
        for(int k=0; k<b.size(); k++){
            if(b[k]>mayor && visitados[k]==0){ //{20,60,40,30,66};
                mayor = b[k];
                // indiceMayor = k;
            }
        }

        for(int k=0; k<b.size(); k++){
            if(b[k]==mayor && visitados[k]==0){
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
}

int main(){
    int M = 20;
    array<int,3> valoresObjetos = {25,24,15}; // b
    array<int,3> pesosObjetos = {18,15,10}; // p
    array<double,3> solucion; // X
    mochila1(M,valoresObjetos,pesosObjetos,solucion);

    double valorTotal = 0;
    for(int i=0; i<solucion.size();i++){
        cout<<"Obj "<<i+1<<" => s:"<<solucion[i]<<" | p:"<<pesosObjetos[i]<<" | v:"<<valoresObjetos[i]<<" = "<<solucion[i]*valoresObjetos[i]<<endl;
        valorTotal += (solucion[i]*valoresObjetos[i]);
    }
    cout<<"Valor Total: "<<valorTotal;
    return 0;
}