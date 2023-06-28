#include <iostream>
using namespace std;

template<typename Type>
class CVector
{
private:
    Type *m_pVect;     // Puntero al buffer
    int m_nCount;     // Control de cuántos elementos hay en uso
    int m_nMax;       // Control de cuántos elementos se pueden almacenar como máximo
    int m_nDelta;     // Para controlar el crecimiento
    void Init(int delta); // Inicializar nuestras variables privadas
    void Resize();    // Redimensionar el vector
public:
    CVector<Type>(int delta = 10); // Constructor
    ~CVector(); // Destructor
    void Insert(Type elem);   // Insertar un nuevo elemento
    // Más métodos van aquí
    void PrintVector();
};

template <typename Type>
void CVector<Type>::Init(int delta){
    this->m_nDelta = delta;
}

template <typename Type>
CVector<Type>::CVector(int delta) {
    Init(delta);
    m_pVect = new Type[delta]; // Asignar memoria inicial para m_pVect
    m_nMax = delta;           // Establecer m_nMax como el tamaño inicial
    m_nCount = 0;             // Establecer m_nCount en 0, ya que no hay elementos inicialmente
}

template <typename Type>
CVector<Type>::~CVector() {
    delete[] m_pVect; // Liberar la memoria asignada al arreglo
}

template <typename Type>
void CVector<Type>::Insert(Type elem) {
    if (m_nCount == m_nMax)     // Verificar el desbordamiento
        Resize();               // Redimensionar el vector antes de insertar elem
    m_pVect[m_nCount++] = elem; // Insertar el elemento al final
}

template <typename Type>
void CVector<Type>::Resize() {
    Type *pTemp = new Type[m_nMax + m_nDelta]; // Asignar un nuevo vector
    for(int i = 0 ; i < m_nMax ; i++) // Transferir los elementos
        pTemp[i] = m_pVect[i]; // también se puede utilizar la función memcpy
    delete[] m_pVect; // eliminar el antiguo vector
    m_pVect = pTemp;
    m_nMax += m_nDelta; // El máximo debe ser incrementado por delta
}

template <typename Type>
void CVector<Type>::PrintVector() {
    for (int i = 0; i < m_nCount; i++) {
        cout<<m_pVect[i]<<" | ";
    }
    cout<<endl;
}

int main() {
    CVector<std::string> vector; // Crear un objeto de la template class CVector

    // Insertar 5 elementos en el vector de strings
    vector.Insert("word1");
    vector.Insert("word2");
    vector.Insert("word3");
    vector.Insert("word4");
    vector.Insert("word5");
    vector.PrintVector();

    return 0;
}
