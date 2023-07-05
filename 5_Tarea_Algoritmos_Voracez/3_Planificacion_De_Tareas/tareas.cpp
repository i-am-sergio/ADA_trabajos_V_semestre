#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct Tarea
{
    int num;
    int beneficio;
    int plazo;
};

bool compararPorPlazo(const Tarea &a, const Tarea &b)
{
    return a.plazo < b.plazo;
}

vector<int> planificarTareas(int n, vector<int> &beneficios, vector<int> &plazos, vector<int>& solucion)
{
    vector<Tarea> tareas(n);
    for (int i = 0; i < n; i++) {
        tareas[i] = {i + 1, beneficios[i], plazos[i]};
    }

    sort(tareas.begin(), tareas.end(), compararPorPlazo); // ordena por plazo
    vector<int> planificacion(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int tarea = tareas[i].num;
        int j = min(n, tareas[i].plazo);

        while (j >= 1 && planificacion[j] != 0) {
            j--;
        }

        if (j >= 1) {
            planificacion[j] = tarea;
            solucion.push_back(tarea);
        }
    }
    return solucion;
}
/*
int main()
{
    int n = 6; // tareas
    vector<int> beneficios = {20, 15, 10, 7, 5, 3};
    vector<int> plazos = {3, 1, 1, 3, 1, 3};
    vector<int> solucion; 
    planificarTareas(n,beneficios, plazos, solucion);

    cout << "Solucion => ";
    for (int tarea : solucion)
    {
        cout << tarea << " ";
    }
    cout << endl;

    // Mostrar las soluciones
    for (int i : solucion)
    {
        int indice = i - 1;
        cout << "tareas[" << i << "] => num: " << i << "| beneficio: " << beneficios[indice] << "| plazo: " << plazos[indice] << "\n";
    }

    return 0;
}
*/

int main()
{
    int n = 4; // tareas
    vector<int> beneficios = {100, 10, 15, 27}; // beneficio
    vector<int> plazos = {2, 1, 2, 1};      // plazo de ejecucion de la tarea
    vector<int> solucion; 
    planificarTareas(n,beneficios, plazos, solucion);

    cout << "Solucion => ";
    for (int tarea : solucion)
    {
        cout << tarea << " ";
    }
    cout << endl;

    // Mostrar las soluciones
    for (int i : solucion)
    {
        int indice = i - 1;
        cout << "tareas[" << i << "] => num: " << i << "| beneficio: " << beneficios[indice] << "| plazo: " << plazos[indice] << "\n";
    }

    return 0;
}

/*
int main()
{
    int n = 4;                         // tareas disponibles
    vector<int> b = {100, 10, 15, 27}; // beneficio
    vector<int> d = {2, 1, 2, 1};      // plazo de ejecucion de la tarea
    vector<int> solucion(n);
    planificacionDeTareas(n, b, d, solucion);
    return 0;
}
*/
