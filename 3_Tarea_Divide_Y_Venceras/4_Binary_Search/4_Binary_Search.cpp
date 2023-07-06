#include <iostream>
#include <vector>
using namespace std;

int BinarySearchRecursivo(const vector<int>& Array,int elemento, int posIni = 0, int posFin = -1){
    if(posIni > posFin)
        return -1;
    int posMedioActual = posIni + (posFin - posIni) / 2;
    if(Array[posMedioActual] == elemento){
        return posMedioActual;
    } else if(elemento < Array[posMedioActual]) {
        int pos = BinarySearchRecursivo(Array,elemento,posIni,posMedioActual-1);
        return pos;
    } else if(elemento > Array[posMedioActual]) {
        int pos = BinarySearchRecursivo(Array,elemento,posMedioActual+1,posFin);
        return pos;
    }
    return -1;
}

int main(){
    vector<int> numeros = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    cout <<"Array:\n";
    for(int i=0; i<numeros.size(); i++){
        cout << numeros[i] << " ";
    }
    cout<<"\n\nElementoBuscado: 67\n";
    int indice = BinarySearchRecursivo(numeros, 67, 0, numeros.size()-1);
    if (indice != -1) {
        cout<<"Elemento: "<<numeros[indice]<<" - Posicion: "<<indice<<endl;
    } else {
        cout<<"Elemento no encontrado en el arreglo"<<endl;
    }
    return 0;
}