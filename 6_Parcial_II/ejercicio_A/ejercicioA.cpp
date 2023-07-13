#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long x;
    vector<long> integers;
    long numMedio1, numMedio2, mediana;

    while(cin >> x)
    {
        integers.emplace_back(x);
        std::sort(integers.begin(), integers.end());
        
        if(integers.size() % 2 != 0){
            mediana = integers[integers.size() / 2];
            cout << mediana << endl;
            continue;
        }
        numMedio1 = integers[integers.size() / 2];
        numMedio2 = integers[integers.size() / 2 - 1];
        mediana = (numMedio1 + numMedio2) / 2;
        cout << mediana << endl;
    }
    return 0;
}
