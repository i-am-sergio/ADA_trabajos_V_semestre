#include <iostream>
using namespace std;

double Potencia(double base, double exponente){ // 2^10
    if(exponente > 0){
        return base * Potencia(base,exponente-1); // 2 * 2^9 ... 2 * 2^8
    } else if(exponente < 0) { // caso de exponente negativo
        return 1.0 / (base * Potencia(base,-(exponente) - 1));
    }
    return 1.0;
}

int main(){
    double num = 5;
    double exponente = -2;
    double resultado = Potencia(num,exponente);
    cout<<"Base: "<<num<<endl;
    cout<<"Exponente: "<<exponente<<endl;
    cout<<"Resultado => "<<resultado<<endl;
    return 0;
}