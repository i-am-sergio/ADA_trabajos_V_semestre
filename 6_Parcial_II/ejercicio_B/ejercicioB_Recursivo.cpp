#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

class Punto
{
public:
    double x;
    double y;
};

bool comparador_Punto(const Punto& a, const Punto& b)
{
    return a.x < b.x;
}

double DistanciaEntre2Puntos(const Punto& a, const Punto& b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double Divide(vector<Punto>& a, int ini, int fin)
{
    if (ini >= fin)
        return 99999;

    int mid = (ini + fin) / 2;
    double min_left = Divide(a, ini, mid);
    double min_right = Divide(a, mid + 1, fin);
    return Mezclar(a, ini, mid, fin, min_left, min_right);
}

double Mezclar(vector<Punto>& a, int ini, int mid, int fin, double min_left, double min_right)
{
    double d = min(min_left, min_right);
    double line = (a[mid].x + a[mid + 1].x) * 0.5;
    double min_D = d;

    for (int i = mid + 1; a[i].x < line + d && i <= fin; i++)
    {
        for (int j = mid; a[j].x > line - d && j >= ini; j--)
        {
            double temp = DistanciaEntre2Puntos(a[i], a[j]);
            if (temp < min_D)
                min_D = temp;
        }
    }
    return min_D;
}

int main()
{
    int N;
    vector<Punto> point;
    while (cin >> N)
    {
        if (N == 0){
            break;
        }

        point.resize(N);
        for (int i = 0; i < N; i++){
            cin >> point[i].x;
            cin >> point[i].y;
        }

        sort(point.begin(), point.end(), comparador_Punto);

        double dis = Divide(point, 0, N - 1);

        if (dis >= 10000.0){
            cout << "INFINITY" << endl;
        }
        else{
            cout << fixed << setprecision(4) << dis << endl;
        }
    }

    return 0;
}

