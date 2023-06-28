#include <iostream>
using namespace std;

void Resize(int *&rpVect, int &rnMax)
{
    const int delta = 10; // Used to increase the vector size
    // pgpVect = realloc(gpVect, sizeof(int) * (rnMax + delta));
    int *pTemp = new int[rnMax + delta]; // Alloc a new vector
    for (int i = 0; i < rnMax; i++)      // Transfiere los elementos
        pTemp[i] = rpVect[i];            // podemos usar tambien la funcion memcpy
    delete[] rpVect;                     // borra el vector anterior
    rpVect = pTemp;
    rnMax += delta; // el maximo ha sido incrementado por delta
}

void Insert(int *&rpVect, int &rnCount, int &rnMax, int elem)
{
    if (rnCount == rnMax)      // Verify the overflow
        Resize(rpVect, rnMax); // Resize the vector before inserting elem
    rpVect[rnCount++] = elem;  // Insert the element at the end of the sequence
}

struct Vector
{
    int *m_pVect, // Puntero al buffer
        m_nCount, // Control de cuantos elementos hay actualmente en uso
        m_nMax,   // Control de cuántos se asignan como máximo
        m_nDelta; // Para controlar el crecimiento
};

int main()
{
    int *vector1 = nullptr; // Primer vector
    int count1 = 0;         // Contador de elementos en el vector 1
    int max1 = 0;           // Tamaño máximo del vector 1

    int *vector2 = nullptr; // Segundo vector
    int count2 = 0;         // Contador de elementos en el vector 2
    int max2 = 0;           // Tamaño máximo del vector 2

    for (int i = 2; i <= 10; i += 2)
    {
        Insert(vector1, count1, max1, i);
    }
    for (int i = 1; i <= 10; i += 2)
    {
        Insert(vector2, count2, max2, i);
    }

    // Imprime elementos del vector 1
    cout << "Elementos del vector 1: ";
    for (int i = 0; i < count1; i++)
    {
        cout << vector1[i] << " ";
    }
    cout << endl;

    // Imprime elementos del vector 2
    cout << "Elementos del vector 2: ";
    for (int i = 0; i < count2; i++)
    {
        cout << vector2[i] << " ";
    }
    cout << endl;

    return 0;
}