#include <iostream>
#include <vector>
using namespace std;

void Swap(int &elem1, int &elem2) { // Intercarmbia dos elementos
    int temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}

void MyQuickSort(int Array[], int primero, int ultimo){
    int pivote;
    int mayor = primero; //índice del elemento mayor

    if (primero < ultimo) {
        pivote = ultimo;

        for (int i = primero; i < ultimo; i++) {
            if (Array[i] <= Array[pivote]) {
                Swap(Array[i], Array[mayor]);
                mayor++;
            }
        }

        Swap(Array[mayor], Array[ultimo]);

        MyQuickSort(Array, primero, mayor - 1); // Llamada recursiva parte izquierda
        MyQuickSort(Array, mayor + 1, ultimo);  // Llamada recursiva parte derecha
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
    int numeros[] = {23, 5, 17, 28, 1, 11, 30, 6, 19, 8, 25, 13, 4, 16, 2, 7, 20, 9, 12, 22, 15, 10, 3, 27, 18, 14, 24, 26, 29, 21};
    int array2[] = {87, 42, 61, 19, 76, 35, 93, 55, 84, 10, 28, 68, 51, 97, 73};
    cout<<"Array original:\n";
    printVector(array2, 15);
    MyQuickSort(array2, 0, 14);
    cout<<"Array ordenado:\n";
    printVector(array2, 15);
    return 0;
}