#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Tarea
{
public:
    int id;
    int beneficio;
    int plazo;
};

bool compararPorBeneficio(const Tarea &tarea1, const Tarea &tarea2)
{
    return (tarea1.beneficio > tarea2.beneficio);
}

void planificacionDeTareas(vector<Tarea> &candidatos, vector<Tarea> &solucion)
{
    int n = candidatos.size();
    // Ordenar los candidatos por beneficio de mayor a menor
    sort(candidatos.begin(), candidatos.end(), compararPorBeneficio);

    // Crear un vector de booleanos para marcar las tareas escogidas
    vector<bool> escogidos(n, false);

    // Realizar la planificación de tareas
    for (int i = 0; i < candidatos.size(); i++)
    {
        // Calcular el plazo mínimo para la tarea actual
        int plazoMinimo = min(n, candidatos[i].plazo);
        // Buscar la posición adecuada para colocar la tarea en el vector de solución
        int j = plazoMinimo - 1;
        while(j>=0){
             if (escogidos[j] == false)
            {
                escogidos[j] = true;
                solucion[j] = candidatos[i];
                break;
            }
            j--;
        }
    }
}

void ejemplo1()
{
    vector<Tarea> candidatos = {{1, 100, 2}, {2, 10, 1}, {3, 15, 2}, {4, 27, 1}};
    vector<Tarea> solucion(candidatos.size());

    // Imprimir los candidatos antes de la planificación
    cout<<"EJEMPLO 1 TAREAS"<<endl;
    for (int i = 0; i < candidatos.size(); i++)
        cout << candidatos[i].id << " => beneficio: " << candidatos[i].beneficio << " - plazo: " << candidatos[i].plazo << endl;

    // Realizar la planificación de tareas
    planificacionDeTareas(candidatos, solucion);

    cout << "\nSolucion: " << endl;

    // Imprimir la solución después de la planificación
    for (int i = 0; i < solucion.size(); i++)
        cout << solucion[i].id << " => beneficio: " << solucion[i].beneficio << " \tplazo: " << solucion[i].plazo << endl;
}

void ejemplo2()
{
    vector<Tarea> candidatos = {{1, 20, 3}, {2, 15, 1}, {3, 10, 1}, {4, 7, 3}, {5, 5, 1}, {6, 3, 3}};
    vector<Tarea> solucion(candidatos.size());

    cout<<"EJEMPLO 2 TAREAS"<<endl;
    // Imprimir los candidatos antes de la planificación
    for (int i = 0; i < candidatos.size(); i++)
        cout << candidatos[i].id << " => beneficio: " << candidatos[i].beneficio << " \tplazo: " << candidatos[i].plazo << endl;

    // Realizar la planificación de tareas
    planificacionDeTareas(candidatos, solucion);

    cout << "\nSolucion: " << endl;

    // Imprimir la solución después de la planificación
    for (int i = 0; i < solucion.size(); i++)
        cout << solucion[i].id << " => beneficio: " << solucion[i].beneficio << " \tplazo: " << solucion[i].plazo << endl;
}

void ejemplo3()
{
    vector<Tarea> candidatos = {{1, 50, 2}, {2, 10, 1}, {3, 15, 2}, {4, 30, 1}};
    vector<Tarea> solucion(candidatos.size());

    cout<<"EJEMPLO 3 TAREAS"<<endl;
    // Imprimir los candidatos antes de la planificación
    for (int i = 0; i < candidatos.size(); i++)
        cout << candidatos[i].id << " => beneficio: " << candidatos[i].beneficio << " \tplazo: " << candidatos[i].plazo << endl;

    // Realizar la planificación de tareas
    planificacionDeTareas(candidatos, solucion);

    cout << "\nSolucion: " << endl;

    // Imprimir la solución después de la planificación
    for (int i = 0; i < solucion.size(); i++)
        cout << solucion[i].id << " => beneficio: " << solucion[i].beneficio << " \tplazo: " << solucion[i].plazo << endl;
}

int main()
{
    ejemplo1();
    cout<<endl;
    ejemplo2();
    cout<<endl;
    ejemplo3();

    return 0;
}
