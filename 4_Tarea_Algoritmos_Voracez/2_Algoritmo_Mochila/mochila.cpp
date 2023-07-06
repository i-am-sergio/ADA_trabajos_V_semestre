#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

// Función de comparación personalizada
bool compararPor1erCampo(const std::tuple<int, int, double, bool> &a, const std::tuple<int, int, double, bool> &b)
{
    return std::get<0>(a) < std::get<0>(b);
}

bool compararPor2doCampo(const std::tuple<int, int, double, bool> &a, const std::tuple<int, int, double, bool> &b)
{
    return std::get<1>(a) < std::get<1>(b);
}

void mochila(int M, vector<tuple<int, int, double, bool>> &candidatos, int criterio)
{
    int n = candidatos.size();
    for (int i = 0; i < n; i++)
    {
        std::get<2>(candidatos[i]) = 0;
        std::get<3>(candidatos[i]) = false;
    }

    int pesoAct = 0;

    while (pesoAct < M)
    {
        int i;

        if (criterio == 1)
        { // Valor Máximo
            auto ptrCandidatoEscogido = max_element(candidatos.begin(), candidatos.end(), compararPor1erCampo);
            i = distance(candidatos.begin(), ptrCandidatoEscogido);
        }
        else if (criterio == 2)
        { // Peso Mínimo
            auto ptrCandidatoEscogido = min_element(candidatos.begin(), candidatos.end(), compararPor2doCampo);
            i = distance(candidatos.begin(), ptrCandidatoEscogido);
        }

        if (pesoAct + std::get<0>(candidatos[i]) <= M)
        {
            std::get<2>(candidatos[i]) = 1;
            pesoAct += std::get<0>(candidatos[i]);
        }
        else
        {
            std::get<2>(candidatos[i]) = (M - pesoAct) / static_cast<double>(std::get<0>(candidatos[i]));
            pesoAct = M;
        }

        std::get<3>(candidatos[i]) = true; // Marcar el candidato como visitado
    }
}

void ejemplo1()
{
    std::vector<std::tuple<int, int, double, bool>> candidatos;

    candidatos.emplace_back(10, 10, 0, false);
    candidatos.emplace_back(3, 9, 0, false);
    candidatos.emplace_back(3, 9, 0, false);
    candidatos.emplace_back(4, 9, 0, false);

    int capacidadMochila = 10;

    mochila(capacidadMochila, candidatos, 1);

    for (const auto &tupla : candidatos)
    {
        std::cout << "Peso: " << std::get<0>(tupla) << ", Beneficio: " << std::get<1>(tupla) << ", Solucion: " << std::get<2>(tupla) << std::endl;
    }
}

void ejemplo2()
{
    std::vector<std::tuple<int, int, double, bool>> candidatos;

    candidatos.emplace_back(18, 25, 0, false);
    candidatos.emplace_back(15, 24, 0, false);
    candidatos.emplace_back(10, 15, 0, false);

    int capacidadMochila = 20; // M

    mochila(capacidadMochila, candidatos, 1);

    for (const auto &tupla : candidatos)
    {
        std::cout << "Peso: " << std::get<0>(tupla) << ", Beneficio: " << std::get<1>(tupla) << ", Solucion: " << std::get<2>(tupla) << std::endl;
    }
}

int main()
{
    ejemplo1();
    cout << endl;
    ejemplo2();
    return 0;
}
