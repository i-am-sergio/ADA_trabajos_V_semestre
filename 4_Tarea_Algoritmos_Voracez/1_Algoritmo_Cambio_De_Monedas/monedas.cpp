#include <iostream>
#include <array>

void devolverCambio(int P, std::array<int,7>& C, std::array<double,7>& X){
    int n = C.size();
    int actual = 0;
    int j = n-1;
    for (int i=0; i<n; i++){ // se inicializa con ceros
        X[i] = 0;
    }
    while(actual != P){
        while((C[j] > (P-actual)) && (j>0)){
            j = j-1;
        }
        if(j==0){
            std::cout<<"No existe solucion"<<std::endl;
            break; // Agregamos un break para salir del bucle si no hay solución
        }
        X[j] = (P-actual)/static_cast<double>(C[j]); // Agregamos una conversión explícita a double
        actual = actual + C[j]*X[j]; // insertar
    }
}

int main() {
    std::array<int, 7> C = {1, 2, 5, 10, 20, 50, 100};
    std::array<double, 7> X;
    int P = 123;

    devolverCambio(P, C, X);

    for (int i = 0; i < X.size(); i++) {
        std::cout << "X[" << i << "] = " << X[i] << std::endl;
    }

    return 0;
}
