#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Segmento
{
public:
    int Li, Ri;
};

bool compararPorLi(const Segmento &segm1, const Segmento &segm2)
{
    return segm1.Li < segm2.Li;
}

int main()
{
    int numCasos;
    cin >> numCasos;
    while (numCasos--)
    {
        int M;
        cin >> M;
        vector<Segmento> S(1);
        while (cin >> S[0].Li >> S[0].Ri){
            S.emplace_back(S[0]);
            if(S[0].Li == 0 && S[0].Ri == 0)
                break;
        }
            
        sort(S.begin() + 1, S.end(), compararPorLi);
        int actualL = 0;
        int limR_Alcanzado = 0;
        
        vector<Segmento> segmentos;
        int i = 1;
        while (limR_Alcanzado < M)
        {
            
            int nuevoL = actualL;
            int masLejano = 0;
            for (; i < S.size(); i++)
            {
                if (S[i].Li > actualL){
                    break;
                }
                else if (S[i].Ri >= nuevoL)
                {
                    nuevoL = S[i].Ri;
                    masLejano = i;
                }
            }
            if (masLejano == 0){
                break;
            }
            segmentos.emplace_back(S[masLejano]);
            actualL = limR_Alcanzado = nuevoL;
        }
        if (limR_Alcanzado >= M)
        {
            cout << segmentos.size() << "\n";
            for(const auto& it : segmentos){
                cout << it.Li << " " << it.Ri; 
            }
        }
        else
            cout << "0" << "\n";
        if (numCasos)
            cout << "\n";
    }
    return 0;
}