#include <iostream>
#include <vector>
using namespace std;

void funcion1_ON(int N){ /// Conteo: f(n) = n+1 + n + n/2
    int contador_for = 0;
    int contador_if = 0;
    int contador_print = 0;
    for (int i=0; i<=N; i++, contador_for++){ // n+1
        if([&]() { contador_if++; return i%2==0; }()){ // Se aumenta el contador_if cada vez que se ejecuta
            cout<<i<<endl; // n/2
            contador_print++;
        }
    }
    contador_for++;
    int costoTotal = contador_for+contador_if+contador_print;
    cout<<"Costo: "<<contador_for<<" + "<<contador_if<<" + "<<contador_print<<" = "<<costoTotal<<endl;
}

void funcion2_Oncuadrado(int N){
    int contador_for1 = 0;
    int contador_for2 = 0;
    int contador_print = 0;
    for (int i=0; i<N; i++,contador_for1++){ //n+1
        for (int j=i; j<N; j++,contador_for2++){ // (n)(n+1)/2 + n
            cout<<i<<","<<j<<endl; contador_print++;// (n)(n+1)/2
        }
        contador_for2++;
    }
    contador_for1++;
    int costoTotal = contador_for1+contador_for2+contador_print;
    cout<<"Costo: "<<contador_for1<<" + "<<contador_for2<<" + "<<contador_print<<" = "<<costoTotal;
}

void funcion3_OAB(vector<int> A, vector<int> B){
    int contador_for1 = 0;
    int contador_for2 = 0;
    int contador_print = 0;
    for (int i=0; i<A.size(); i++, contador_for1++){ // A+1
        for (int j=0; j<B.size(); j++,contador_for2++){ // (A)(B+1)
            cout<<A[i]<<","<<B[j]<<endl; contador_print++; //(A)(B) 
        }
        contador_for2++;
    }
    contador_for1++;
    int costoTotal = contador_for1+contador_for2+contador_print;
    cout<<"Costo: "<<contador_for1<<" + "<<contador_for2<<" + "<<contador_print<<" = "<<costoTotal;
}

void funcion4_Onlogn(int N) {
    int c_for = 0;
    int c_j = 0;
    int c_while = 0;
    int c_print = 0;
    int c_mult = 0;

    for (int i=0; i<N; i++,c_for++){ ////n+1 
        int j=1; c_j++; // n
        while([&]() { c_while++; return j<N; }()){ // n*(log2n + 1) 
            cout<<j<<endl; c_print++;// n*(log2n)
            j=j*2; c_mult++;// n*(log2n)
        }
    }
    c_for++;
    int costoTotal = c_for+c_j+c_while+c_print+c_mult;
    cout<<"Costo: ";
    cout<<c_for<<" + "<<c_j<<" + "<<c_while<<" + "<<c_print<<" + "<<c_mult<<" = ";
    cout<<costoTotal;
}

void funcion5_On(int N){
    int c_for1=0;
    int c_for2=0;
    int c_if1=0;
    int c_if2=0;
    int c_print1=0;
    int c_print2=0;
    for (int i=0; i<N; i++,c_for1++){ // n+1
        c_if1++;
        if(i%2==0){ // n
            cout<<i<<endl; c_print1++; //n/2
        }
    }
    for(int i=0; i<N; i++, c_for2++){ // n+1
        c_if2++;
        if(i%2!=0){ // n
            cout<<i<<endl; c_print2++; // n/2
        }
    }
    c_for1++;
    c_for2++;
    int costoTotal = c_for1+c_for2+c_if1+c_if2+c_print1+c_print2;
    cout<<"Costo: ";
    cout<<c_for1<<" + "<<c_if1<<" + "<<c_print1<<" + ";
    cout<<c_for2<<" + "<<c_if2<<" + "<<c_print2;
    cout<<" = "<<costoTotal;
}

void funcion6_OlogN(int N){
    int c_asignacion=1;
    int c_while=0;
    int c_print=0;
    int c_mult=0;
    int i=1;
    while(i<N){
        c_while++;
        cout<<i<<endl; c_print++;
        i = i*2; c_mult++;
    }
    c_while++;
    cout<<"Costo: "<<c_asignacion<<" + "<<c_while<<" + "<<c_print<<" + "<<c_mult<<" = "<<c_asignacion+c_while+c_print+c_mult<<endl;
}

void funcion7_O1(){
    int c_N = 1; // N = 1000 coste = 1
    int c_if = 0;
    int c_else = 0;
    int c_print = 0;
    c_if++;
    int N = 1000;
    if(N%2 == 0){ //1
        cout<<"par"<<endl; c_print++; // 1
    } else {
        c_else++;
        cout<<"impar"<<endl; c_print++; // 1
    }
    cout<<"Costo: "<<c_N<<" + "<<c_if<<" + "<<c_else<<" + "<<c_print<<" = "<<c_N+c_if+c_else+c_print;
}


int main() {
    // funcion1_ON(5); // n=5 =>  6 + 5 + 3 = 13
    // funcion2_Oncuadrado(7); //n=7 => 8 + 35 + 28 = 71
    funcion3_OAB({10,20,30,40,50},{11,12,13,14,15,16,17}); // A=5,B=7 => 6 + 40 + 35 = 81
    // funcion4_Onlogn(16); // n=16 => 17 + 16 + 80 + 64 + 64 = 241
    // funcion5_On(11); // n=11 => 12 + 11 + 6 + 12 + 11 + 5 = 57
    // funcion6_OlogN(9); // n=9 => 1 + 5 + 4 + 4 = 14
    // funcion7_O1(); // n=1000 => 1 + 1 + 1 + 0 = 3

    return 0;
}