#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using Matrix = std::vector<std::vector<T>>;

Matrix<int> SumaMatrices(Matrix<int> &matrix1, Matrix<int> &matrix2)
{
    Matrix<int> resultado(matrix1.size(), vector<int>(matrix1.size()));
    for (int i = 0; i < matrix1.size(); i++)
        for (int j = 0; j < matrix1[0].size(); j++)
            resultado[i][j] = matrix1[i][j] + matrix2[i][j];
    return resultado;
}

Matrix<int> RestaMatrices(Matrix<int> &matrix1, Matrix<int> &matrix2)
{
    Matrix<int> resultado(matrix1.size(), vector<int>(matrix1.size()));
    for (int i = 0; i < matrix1.size(); i++)
        for (int j = 0; j < matrix1[0].size(); j++)
            resultado[i][j] = matrix1[i][j] - matrix2[i][j];
    return resultado;
}

Matrix<int> operator+(Matrix<int> matrix1, Matrix<int> matrix2)
{
    Matrix<int> resultado = SumaMatrices(matrix1, matrix2);
    return resultado;
}

Matrix<int> operator-(Matrix<int> matrix1, Matrix<int> matrix2)
{
    Matrix<int> resultado = RestaMatrices(matrix1, matrix2);
    return resultado;
}

Matrix<int> add_matrix(Matrix<int> matrix1, Matrix<int> matrix2, int split_index, int multiplier = 1)
{
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix1[i][j] = matrix1[i][j] + (multiplier * matrix2[i][j]);
    return matrix1;
}

Matrix<int> Multiply_Matrices_Strassen(Matrix<int> matrix1, Matrix<int> matrix2)
{
    int n = matrix1.size();
    Matrix<int> resultado(n, vector<int>(n, 0));

    if (n == 1)
    {
        resultado[0][0] = matrix1[0][0] * matrix2[0][0];
        return resultado;
    }
    else
    {
        int sizeDividido = n / 2;

        Matrix<int> a00(sizeDividido, vector<int>(sizeDividido));
        Matrix<int> a01(sizeDividido, vector<int>(sizeDividido));
        Matrix<int> a10(sizeDividido, vector<int>(sizeDividido));
        Matrix<int> a11(sizeDividido, vector<int>(sizeDividido));

        Matrix<int> b00(sizeDividido, vector<int>(sizeDividido));
        Matrix<int> b01(sizeDividido, vector<int>(sizeDividido));
        Matrix<int> b10(sizeDividido, vector<int>(sizeDividido));
        Matrix<int> b11(sizeDividido, vector<int>(sizeDividido));

        for (auto i = 0; i < sizeDividido; i++)
        {
            for (auto j = 0; j < sizeDividido; j++)
            {
                a00[i][j] = matrix1[i][j];
                a01[i][j] = matrix1[i][j + sizeDividido];
                a10[i][j] = matrix1[sizeDividido + i][j];
                a11[i][j] = matrix1[i + sizeDividido][j + sizeDividido];
                b00[i][j] = matrix2[i][j];
                b01[i][j] = matrix2[i][j + sizeDividido];
                b10[i][j] = matrix2[sizeDividido + i][j];
                b11[i][j] = matrix2[i + sizeDividido][j + sizeDividido];
            }
        }

        Matrix<int> p = Multiply_Matrices_Strassen(a00,(b01 - b11));
        Matrix<int> q = Multiply_Matrices_Strassen((a00 + a01), b11);
        Matrix<int> r = Multiply_Matrices_Strassen((a10 + a11), b00);
        Matrix<int> s = Multiply_Matrices_Strassen(a11,(b10 - b00));
        Matrix<int> t = Multiply_Matrices_Strassen((a00 + a11),(b00 + b11));
        Matrix<int> u = Multiply_Matrices_Strassen((a01 - a11), (b10 + b11));
        Matrix<int> v = Multiply_Matrices_Strassen((a00 - a10), (b00 + b01));

        Matrix<int> result_matrix_00 = ((t + s) + u) - q;
        Matrix<int> result_matrix_01 = p + q;
        Matrix<int> result_matrix_10 = r + s;
        Matrix<int> result_matrix_11 = ((t + p) - r) - v;

        for (auto i = 0; i < sizeDividido; i++)
        {
            for (auto j = 0; j < sizeDividido; j++)
            {
                resultado[i][j] = result_matrix_00[i][j];
                resultado[i][j + sizeDividido] = result_matrix_01[i][j];
                resultado[sizeDividido + i][j] = result_matrix_10[i][j];
                resultado[i + sizeDividido][j + sizeDividido] = result_matrix_11[i][j];
            }
        }
    }
    return resultado;
}

void printMatrix(std::ostream& os, const Matrix<int> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            os << matrix[i][j] << "\t";
        }
        os << endl;
    }
    os << endl;
}

std::ostream& operator<<(std::ostream& os, Matrix<int>& matrix)
{
    printMatrix(os, matrix);
    return os;
}

// Multiplicacion de Matrices O(n^3) solo para comprobar el resultado
void multiply_On3(Matrix<int> &A, Matrix<int> &B, Matrix<int> &C)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < A.size(); k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    Matrix<int> A = {{0, 4, 3, 3},
                     {-4, 5, -2, -2},
                     {-5, -5, 2, -1},
                     {-1, -3, 5, -1}};
    Matrix<int> B = {{4, 0, 1, -2},
                     {-2, -2, 3, -1},
                     {4, 4, 2, -5},
                     {0, 4, -2, 5}};

    cout << "Matriz A:\n" <<A <<  "Matriz B:\n" << B;
    cout << "Matriz C (Multiplicacion AxB):\n";
    Matrix<int> MMS(Multiply_Matrices_Strassen(A, B));
    cout << MMS;

    return 0;
}