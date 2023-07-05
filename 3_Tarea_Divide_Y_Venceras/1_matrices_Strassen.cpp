#include <iostream>
#include <vector>
using namespace std;

template<typename T>
using Matrix = std::vector<std::vector<T>>;

Matrix<int> SumaMatrices(Matrix<int> &matrix1, Matrix<int> &matrix2){    
    Matrix<int> resultado(matrix1.size(),vector<int>(matrix1.size()));
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[0].size(); j++) {
            resultado[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return resultado;
}

Matrix<int> RestaMatrices(Matrix<int> &matrix1, Matrix<int> &matrix2){    
    Matrix<int> resultado(matrix1.size(),vector<int>(matrix1.size()));
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[0].size(); j++) {
            resultado[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return resultado;
}

Matrix<int> Matrices_Strassen(Matrix<int> & matrix1, Matrix<int> & matrix2, int dimension)
{
    // Matrix<int> M1 =  
    if(n<=2){

        // c = 4 formulas ...
    } else {
        int mid = dimension / 2;
        // Matrices_Strassen(A11,B11,mid) + Matrices_Strassen(A12,B21,mid);
        // Matrices_Strassen(A11,B12,mid) + Matrices_Strassen(A12,B22,mid);
        // Matrices_Strassen(A21,B11,mid) + Matrices_Strassen(A22,B21,mid);
        // Matrices_Strassen(A21,B12,mid) + Matrices_Strassen(A22,B22,mid);

        for(int i=0; i<mid; i++){
            for(int j=0; j<mid; j++){
                
            }
        }
    }
    return 0;
}

void printMatrix(const Matrix<int> & matrix){
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Matrix<int> A = {
        {2, 4},
        {5, 3}
    };

    Matrix<int> B = {
        {6, 8},
        {9, 7}
    };
    // Matrix myMatrix1 = {{1, 2, 3, 4},
    //                                  {5, 6, 7, 8},
    //                                  {9, 10, 11, 12},
    //                                  {13, 14, 15, 16}};
    // Matrix myMatrix2 = {{1, 2, 3, 4},
    //                                  {5, 6, 7, 8},
    //                                  {9, 10, 11, 12},
    //                                  {13, 14, 15, 16}};
    printMatrix(A);
    printMatrix(B);
    Matrix<int> suma = SumaMatrices(A,B);
    printMatrix(suma);
    return 0;
}