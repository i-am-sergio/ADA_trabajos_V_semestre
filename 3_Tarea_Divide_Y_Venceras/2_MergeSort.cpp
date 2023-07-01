#include <iostream>
#include <vector>
using namespace std;

void Merge(int myArray[], int inicio, int medio, int fin) {
    int sizeIzq = medio - inicio + 1;
    int sizeDer = fin - medio;
    int* subArrayIzq = new int[sizeIzq];
    int* subArrayDer = new int[sizeDer];
    
    for (int i = 0; i < sizeIzq; i++)
        subArrayIzq[i] = myArray[inicio + i];
    for (int j = 0; j < sizeDer; j++)
        subArrayDer[j] = myArray[medio + 1 + j];

    int i = 0, j = 0, k = inicio;
    
    while (i < sizeIzq && j < sizeDer) {
        if (subArrayIzq[i] <= subArrayDer[j]) {
            myArray[k] = subArrayIzq[i];
            i++;
        } else {
            myArray[k] = subArrayDer[j];
            j++;
        }
        k++;
    }
    
    while (i < sizeIzq) { // Copia los elementos restantes del subarreglo izquierdo
        myArray[k] = subArrayIzq[i];
        i++; k++;
    }
    
    while (j < sizeDer) { // Copia los elementos restantes del subarreglo derecho, si hay alguno
        myArray[k] = subArrayDer[j];
        j++; k++;
    }
    
    delete[] subArrayIzq;
    delete[] subArrayDer;
}


void MyMergeSort(int Array[], int inicio, int fin){
    if(inicio < fin){
        int medio = (inicio + fin) / 2; // Dividimos por la mitad
        MyMergeSort(Array, inicio, medio);
        MyMergeSort(Array, medio+1, fin);
        Merge(Array,inicio,medio,fin); // Mezcla las partes ordenadas
    }
}

void printVector(int Array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << Array[i] << " | ";
    }
    cout << endl;
}


int main(){
    int array1[] = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
    printVector(array1, 10);
    MyMergeSort(array1, 0, 9);
    printVector(array1, 10);
    return 0;
}