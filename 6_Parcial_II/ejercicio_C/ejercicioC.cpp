#include <iostream>
#include <vector>
using namespace std;

int main()
{  
    int numPruebas;
    cin >> numPruebas;
    while ( numPruebas-- )
    {
        int n;
        cin >> n;
        vector<long int> valoresMonedas;
        int valor;

        for (int i = 0; i < n; i++)
        {
            cin >> valor;
            valoresMonedas.emplace_back(valor);
        }

        int sumTotal = 1;
        int monedas = (n > 1)? 2 : 1;

        for (int i = 1; i < n - 1; i++)
            if (sumTotal + valoresMonedas[i] < valoresMonedas[i+1])
            {
                sumTotal += valoresMonedas[i];
                monedas++;
            }

        cout << monedas << endl;
    }
    return 0;
}