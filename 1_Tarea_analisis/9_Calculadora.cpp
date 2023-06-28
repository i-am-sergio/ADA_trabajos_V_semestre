#include <iostream>
using namespace std;

float Addition(float a, float b)
{
    return a + b;
}
float Subtraction(float a, float b)
{
    return a - b;
}
float Multiplication(float a, float b)
{
    return a * b;
}
float Division(float a, float b)
{
    return a / b;
}

int main()
{
    typedef float (*lpfnOperation)(float, float);
    // CVector of pointer to functions
    lpfnOperation vpf[4] = {&::Addition, 
                            &::Subtraction,
                            &::Multiplication, 
                            &::Division};
    float a, b, c;
    int opt;
    // enter the operands
    cin >> a >> b;
    // enter the operation 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division
    cin >> opt;
    // The next line replaces
    c = vpf[opt](a, b);
    cout << c;
}