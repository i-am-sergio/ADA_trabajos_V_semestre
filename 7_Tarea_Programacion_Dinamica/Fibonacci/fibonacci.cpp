#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fib2(int n){
    int* f = new int[n+1];

    f[0] = 0;
    f[1] = 1;

    for(int i=2; i<=n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    int var = f[n];
    delete [] f;
    return var;
}

int main()
{
    for (int i=1; i<=10; i++){
        int resultado = fib(i);
        cout << resultado << endl; 
    }

    return 0;
}