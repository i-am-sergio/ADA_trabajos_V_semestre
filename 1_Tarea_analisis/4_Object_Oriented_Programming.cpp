#include <iostream>
using namespace std;

class CVector
{
private:
    int *m_pVect,         // Puntero al buffer
        m_nCount,         // Control de cuantos elementos hay en uso
        m_nMax,           // Control how many are allocated as maximum
        m_nDelta;         // Para controlar el crecimiento
    void Init(int delta); // Init para nuestras variables privadas
    void Resize();        // Resize el vector
public:
    CVector(int delta = 10); // Constructor
    ~CVector(); // Destructor
    void Insert(int elem);   // Insert a new element
    // More methods go here
    void PrintVector();
};

void CVector::Init(int delta){
    this->m_nDelta = delta;
}

CVector::CVector(int delta) {
    Init(delta);
    m_pVect = new int[delta]; // Asignar memoria inicial para m_pVect
    m_nMax = delta;           // Establecer m_nMax como el tamaño inicial
    m_nCount = 0;             // Establecer m_nCount en 0, ya que no hay elementos inicialmente
}

CVector::~CVector() {
    delete[] m_pVect; // Liberar la memoria asignada al arreglo
}


void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax)     // Verify the overflow
        Resize();               // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Resize() {
    int *pTemp = new int[m_nMax + m_nDelta]; // Alloc a new vector
    for(int i = 0 ; i < m_nMax ; i++) // Transfiere los elementos
        pTemp[i] = m_pVect[i];
    delete [ ] m_pVect; // delete the old vector
    m_pVect = pTemp;
    m_nMax += m_nDelta; // El maximo tiene que ser incrementado por delta
}

void CVector::PrintVector() {
    for (int i = 0; i < m_nCount; i++) {
        cout << m_pVect[i] << " | ";
    }
    cout << endl;
}


int main() {
    CVector vector; // Crear un objeto de la clase CVector

    // Insertamos 5 elementos en el vector
    vector.Insert(10);
    vector.Insert(20);
    vector.Insert(30);
    vector.Insert(40);
    vector.Insert(50);
    vector.PrintVector();

    return 0;
}