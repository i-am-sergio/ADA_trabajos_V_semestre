#include <iostream>
#include <queue>
using namespace std;

#define N 4

// Nodo del árbol del espacio de estados
struct Nodo
{
    // Almacena el nodo padre del nodo actual
    // Ayuda a rastrear el camino cuando se encuentra la respuesta
    Nodo *padre;

    // Contiene el costo del camino para los nodos ancestros
    // incluyendo el nodo actual
    int costoCamino;

    // Contiene el costo menos prometedor
    int costo;

    // Contiene el número de trabajador
    int idTrabajador;

    // Contiene el ID del trabajo
    int idTrabajo;

    // El arreglo booleano "asignado" contendrá
    // información sobre los trabajos disponibles
    bool asignado[N];
};

// Función para asignar un nuevo nodo en el árbol de búsqueda
// Aquí, la persona x se asigna al trabajo y
Nodo *nuevoNodo(int x, int y, bool asignado[],
              Nodo *padre)
{
    Nodo *nodo = new Nodo;

    for (int j = 0; j < N; j++)
        nodo->asignado[j] = asignado[j];
    nodo->asignado[y] = true;

    nodo->padre = padre;
    nodo->idTrabajador = x;
    nodo->idTrabajo = y;

    return nodo;
}

// Función para calcular el costo menos prometedor
// del nodo después de que el trabajador x se asigna al trabajo y.
int calcularCosto(int matrizCostos[N][N], int x,
                  int y, bool asignado[])
{
    int costo = 0;

    // para almacenar los trabajos no disponibles
    bool disponibles[N] = {true};

    // comenzar desde el siguiente trabajador
    for (int i = x + 1; i < N; i++)
    {
        int minimo = INT_MAX, indiceMinimo = -1;

        // hacerlo por cada trabajo
        for (int j = 0; j < N; j++)
        {
            // si el trabajo no está asignado
            if (!asignado[j] && disponibles[j] &&
                matrizCostos[i][j] < minimo)
            {
                // almacenar el número del trabajo
                indiceMinimo = j;

                // almacenar el costo
                minimo = matrizCostos[i][j];
            }
        }

        // agregar el costo del siguiente trabajador
        costo += minimo;

        // el trabajo se vuelve no disponible
        disponibles[indiceMinimo] = false;
    }

    return costo;
}

// Objeto de comparación utilizado para ordenar el montón (heap)
struct comp
{
    bool operator()(const Nodo *izquierdo,
                    const Nodo *derecho) const
    {
        return izquierdo->costo > derecho->costo;
    }
};

// imprimir las asignaciones
void imprimirAsignaciones(Nodo *min)
{
    if (min->padre == NULL)
        return;

    imprimirAsignaciones(min->padre);
    cout << "Asignar Trabajador " << char(min->idTrabajador + 'A') << " al Trabajo " << min->idTrabajo + 1 << endl;
}

// Encuentra el costo mínimo utilizando Branch and Bound.
int encontrarCostoMinimo(int matrizCostos[N][N])
{
    // Crear una cola de prioridad para almacenar nodos vivos del
    // árbol de búsqueda
    priority_queue<Nodo *, std::vector<Nodo *>, comp> colaPrioridad;

    // inicializar el heap con un nodo ficticio con costo 0
    bool asignado[N] = {false};
    Nodo *raiz = nuevoNodo(-1, -1, asignado, NULL);
    raiz->costoCamino = raiz->costo = 0;
    raiz->idTrabajador = -1;

    // Agregar el nodo ficticio a la lista de nodos vivos;
    colaPrioridad.push(raiz);
    // Encuentra un nodo vivo con el menor costo estimado,
    // agrega sus hijos a la lista de nodos vivos y
    // finalmente elimínalo de la lista.
    while (!colaPrioridad.empty())
    {
        // Encuentra un nodo vivo con el menor costo estimado
        Nodo *min = colaPrioridad.top();

        // El nodo encontrado se elimina de la lista de
        // nodos vivos
        colaPrioridad.pop();

        // i almacena el siguiente trabajador
        int i = min->idTrabajador + 1;

        // si todos los trabajadores tienen asignado un trabajo
        if (i == N)
        {
            imprimirAsignaciones(min);
            return min->costo;
        }

        // hacerlo por cada trabajo
        for (int j = 0; j < N; j++)
        {
            // si no está asignado
            if (!min->asignado[j])
            {
                // crear un nuevo nodo en el árbol
                Nodo *hijo = nuevoNodo(i, j, min->asignado, min);
                // costo para los nodos ancestros incluyendo el nodo actual
                hijo->costoCamino = min->costoCamino + matrizCostos[i][j];
                // calcular su límite inferior
                hijo->costo = hijo->costoCamino + calcularCosto(matrizCostos, i, j, hijo->asignado);
                // Agregar el hijo a la lista de nodos vivos;
                colaPrioridad.push(hijo);
            }
        }
    }
    return 0;
}

int main()
{
   
    int matrizCostos[N][N] = {
        {94, 1, 54, 68},
        {74, 10, 88, 82},
        {62, 88, 8, 76},
        {11, 74, 81, 21}
    };

    // int matrizCostos[N][N] = {
    // {5, 6, 4},
    // {3, 8, 2},
    // {6, 5, 1}
    // };

    cout << "\nCosto Optimo es \n"; 
    encontrarCostoMinimo(matrizCostos);

    return 0;
}
