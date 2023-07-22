#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using Matrix = std::vector<std::vector<T>>;

vector<int> ReconstruirSolucion(int, int, vector<int>&, vector<int>&, Matrix<int>&);


int max(int a, int b) {
    return (a > b) ? a : b;
}

void printMatrix(Matrix<int>& M){
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++)
            cout << M[i][j] << "\t";
        cout << "\n";
    }
}

// Función de la mochila con programación dinámica
int Mochila(int n, int M, vector<int> &p, vector<int> &b)
{
    // Crear la tabla V
    Matrix<int> V(n + 1, vector<int>(M + 1, 0));
    // Rellenar los casos base
    for (int i = 0; i <= n; i++){
        V[i][0] = 0;
    }
    for (int j = 0; j <= M; j++){
        V[0][j] = 0;
    }
    // Rellenar la tabla usando la ecuación de la mochila
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            if (p[i - 1] <= j) {
                V[i][j] = max(V[i - 1][j], b[i - 1] + V[i - 1][j - p[i - 1]]);
            }
            else {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    // Imprime tabla 
    printMatrix(V);

    // Reconstruir la solución óptima
    vector<int> solucion = ReconstruirSolucion(n, M, p, b, V);

    // Mostrar la solución óptima
    cout << "\nObjetos incluidos en la Solucion Optima:\n";
    for (int i = 0; i < n; i++) {
        if (solucion[i] == 1) {
            cout << "\t- Objeto " << i + 1 << " => Peso: " << p[i] << ", Beneficio: " << b[i] << "\n";
        }
    }

    return V[n][M]; // El resultado óptimo es V[n][M]
}

// Función para reconstruir la solucion optima
vector<int> ReconstruirSolucion(int n, int M, vector<int>& p, vector<int>& b, Matrix<int>& V) {
    vector<int> x(n, 0); // Inicializar la solución óptima con todos los objetos no incluidos
    int j = M;
    for (int i = n; i >= 1; i--) {
        if (V[i][j] == V[i - 1][j]) {
            x[i - 1] = 0; // No se incluye el objeto i
        } else {
            x[i - 1] = 1; // Se incluye el objeto i
            j -= p[i - 1];
        }
    }
    return x;
}


int main()
{
    int n, M;
    cout << "Ingrese el numero de objetos: ";
    cin >> n;

    vector<int> p(n), b(n); // pesos y beneficios de los objetos

    cout << "Ingrese los pesos de los objetos:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Ingrese los beneficios de los objetos:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << "Ingrese la capacidad de la mochila: ";
    cin >> M;

    int resultado = Mochila(n, M, p, b);
    cout << "El beneficio optimo es: " << resultado << endl;

    return 0;
}
