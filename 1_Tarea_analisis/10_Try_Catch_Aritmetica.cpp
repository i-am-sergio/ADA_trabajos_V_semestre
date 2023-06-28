#include <iostream>
using namespace std;
// Class CVector definition
class CArithmetic
{
private:
    // Some attributes go here
public:
    static double Addition(double a, double b);
    static double Substraction(double a, double b);
    static double Multiplication(double a, double b);
    static double Division(double a, double b);
    // More methods go here
};

double CArithmetic::Addition(double a, double b)
{
    return a + b;
}

double CArithmetic::Substraction(double a, double b)
{
    return a - b;
}

double CArithmetic::Multiplication(double a, double b)
{
    return a * b;
}

double CArithmetic::Division(double a, double b)
{
    if (b == 0.0)
        throw (int)0; // an exceptions is thrown here
    return a / b;
}

int main()
{
    double x, y, z;
    x = 123.5;
    y = 0;
    try // our critical section with possible exceptions begins here
    {
        z = CArithmetic::Division(x, y);
        cout << z;
    }
    catch (int errorcode) // catching the exception
    {
        cout<<"Error: Division entre 0 es indeterminado ["<<errorcode<<"]\n";
    }
    // Continua con la ejecucion pese a la excepcion
    x = 98.7;
    y = 12.3;
    z = CArithmetic::Addition(x, y);
    cout << z;

    return 0;
}