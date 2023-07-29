#include <iostream>
#include <vector>
using namespace std;

const int N = 4; // Número de objetos disponibles
const int M = 7; // Capacidad de la mochila

vector<int> p = {1, 2, 3, 4}; // Pesos de los objetos
vector<int> b = {2, 3, 4, 5}; // Beneficios de los objetos

vector<int> s(N, 0); // Representación de la solución con árbol combinatorio
vector<int> soa(N, 0); // Solución óptima actual

int voa = 0; // Valor óptimo actual
int pact = 0; // Peso actual
int bact = 0; // Beneficio actual
int contador=1;

void GenerarArbolCombinatorio(int nivel) {
    if (nivel == N) {
        // Verificar si se alcanzó una solución completa
        if (pact <= M && bact > voa) {
            voa = bact;
            soa = s;


        }
        cout<<contador<<" => "; contador++;
        // for (int i = 0; i < s.size(); i++) {
        //     cout << s[i] << " ";
        // }

        // cout<<"|";
        for (int i = 0; i < s.size(); i++) {
            if(s[i]==1){
                cout<< i+1 << " ";
            }
        }
        cout << endl;

        
        return;
    }

    // Generar combinaciones con el objeto no cogido (0)
    s[nivel] = 0;
    GenerarArbolCombinatorio(nivel + 1);

    // Generar combinaciones con el objeto cogido (1)
    s[nivel] = 1;
    pact += p[nivel];
    bact += b[nivel];
    GenerarArbolCombinatorio(nivel + 1);

    // Deshacer cambios para el retroceso
    pact -= p[nivel];
    bact -= b[nivel];
}

int main() {
    GenerarArbolCombinatorio(0);

    cout << "Solucion optima: ";
    for (int i = 0; i < N; i++) {
        if (soa[i] == 1) {
            cout << "Objeto " << i + 1 << " ";
        }
    }
    cout << endl;
    cout << "Valor optimo: " << voa << endl;

    return 0;
}

