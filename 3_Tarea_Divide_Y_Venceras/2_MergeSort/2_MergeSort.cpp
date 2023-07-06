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
    
    while (i < sizeIzq) { // Copia los elementos restantes del subArrayIzq
        myArray[k] = subArrayIzq[i];
        i++; k++;
    }
    
    while (j < sizeDer) { // Copia los elementos restantes del subArrayDer
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
    int array2[] = {23, 5, 17, 28, 1, 11, 30, 6, 19, 8, 25, 13, 4, 16, 2, 7, 20, 9, 12, 22, 15, 10, 3, 27, 18, 14, 24, 26, 29, 21};
    cout<<"Array original:\n";
    printVector(array2, 30);
    MyMergeSort(array2, 0, 29);
    cout<<"Array Ordenado:\n";
    printVector(array2, 30);
    return 0;
}