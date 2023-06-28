#include <iostream>
#include <cstdlib>
using namespace std;

int *gpVect = NULL; // Buffer dinamico para guardar los elementos int
int gnCount = 0;    // Contador para saber el número de elementos utilizados int
int gnMax = 0;      // Variable que contiene el tamaño de la memoria asignada

void Resize() {
    const int delta = 10; // Used to increase the vector size
    //gpVect = realloc(gpVect, sizeof(int) * (gnMax + delta));
    int *pTemp = new int[gnMax + delta]; // Alloc a new vector
    for(int i = 0 ; i < gnMax ; i++) // Transfer the elements
        pTemp[i] = gpVect[i]; // we can also use the function memcpy
    delete [ ] gpVect; // delete the old vector
    gpVect = pTemp;
    gnMax += delta; // El maximo tiene que ser incrementado por delta
}

void Insert(int elem) {
    if (gnCount == gnMax) // No hay espacio en este momento para elem
        Resize();         // Cambiar el tamaño del vector antes de insertar elem
    gpVect[gnCount++] = elem;
}

int main() {
    Insert(100);
    Insert(999);
    Insert(200);
    Insert(777);
    Insert(300);
    Insert(555);
    Insert(400);

    for(int i=111; i<=300; i+=20){
        Insert(i);
    }

    for (int i = 0; i < gnCount; i++) {
        std::cout<<gpVect[i]<<" | ";
    }

    delete[] gpVect;
    gpVect = nullptr;
    return 0;
}