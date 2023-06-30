#include <iostream>
#include <vector>
using namespace std;

void swap(int &elem1, int &elem2)
{ // Intercarmbia dos elementos
    int temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}

int elegirPivote(int Array[], int primero, int ultimo)
{
    int contador = primero;
    for (int i = primero + 1; i <= ultimo; i++)
    {
        if (Array[i] <= Array[primero])
        {
            contador++;
            swap(Array[i], Array[contador]);
        }
    }
    swap(Array[contador], Array[primero]);
    return contador;
}

void QuickSort(int Array[], int primero, int ultimo)
{
    int pivote;
    if (primero < ultimo)
    {
        pivote = elegirPivote(Array, primero, ultimo);
        QuickSort(Array, primero, pivote - 1); // Izquierda
        QuickSort(Array, pivote + 1, ultimo);  // Derecha
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

int main()
{
    int numeros[] = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
    printVector(numeros, 10);
    QuickSort(numeros, 0, 9);
    printVector(numeros, 10);
    return 0;
}