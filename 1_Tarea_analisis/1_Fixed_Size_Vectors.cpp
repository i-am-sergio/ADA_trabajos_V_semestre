// Fixed size vectors
#include <iostream>
using namespace std;

// VARIABLES GLOBALES
int gVect[100]; // Buffer para guardar los elementos
int gnCount; // Contador para saber el numero de elementos utilizados

void Insert(int elem){
    if( gnCount < 100 ) // solo podemos insertar si hay espacio
    gVect[gnCount++] = elem; // Inserta el elemento al final
}

int main(){
    Insert(100);
    Insert(999);
    Insert(200);
    Insert(777);
    Insert(300);
    Insert(555);
    Insert(400);

    for(int i=0; i<=gnCount-1; i++){
        std::cout<<gVect[i]<<" | ";
    }

    return 0;
}