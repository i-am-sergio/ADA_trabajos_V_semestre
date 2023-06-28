#include <iostream>

namespace MyNS
{
int gnCount; // Global counter
// Some small function implemented inline
double Addition(double a, double b) // Global function
{
    return a + b;
}
double Substraction(double a, double b) // Global function
{
    return a - b;
}
// Some prototypes
long factorial(int n); // Global function
class CTest
{
public:
    CTest();
    void Method1();
};
    // More variables, functions, methods, classes, structs go here
};

int main(){
    double num1 = 10;
    double num2 = 20;
    std::cout<<"Resultado de la suma de "<<num1<<" + "<<num2<<" = "<<MyNS::Addition(num1,num2)<<"\n";
    std::cout<<"Resultado de la resta de "<<num2<<" - "<<num1<<" = "<<MyNS::Addition(num2,num1)<<"\n";
}