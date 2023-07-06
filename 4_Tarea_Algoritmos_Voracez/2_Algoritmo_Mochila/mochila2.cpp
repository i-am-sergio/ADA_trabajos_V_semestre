#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Bag {
    int peso;
    float beneficio;
    
};
typedef std::vector<Bag>::iterator it;


it seleccionarCrit1(std::vector<Bag> & C)
{
       it i = std::max_element(C.begin(),C.end(),[](const Bag &a, const Bag &b){return a.beneficio <  b.beneficio;} );
      
       return i;
}

it seleccionarCrit2(std::vector<Bag> & C)
{
       it i = std::min_element(C.begin(),C.end(),[](const Bag &a, const Bag &b){return a.beneficio <  b.beneficio;} );
        
       return i;
}

it seleccionarCrit3(std::vector<Bag> & C)
{
       it i = std::max_element(C.begin(),C.end(),[](const Bag &a, const Bag &b){return a.beneficio/a.peso <  b.beneficio/b.peso;} );
      
       return i;
}

void getBag(int M, std::vector<Bag> &candidatos, std::vector<Bag> &solucion, it (*func)(std::vector<Bag> &))
{
    solucion.clear();
    int pesoAct = 0;
    
    while (pesoAct<M)
    {
        it i = func(candidatos);

        if(pesoAct + i->peso <= M)
        {
            
            int numBag =1;
            float beneficio = numBag*i->beneficio;
            solucion.push_back(Bag {i->peso,beneficio});
            pesoAct+= i->peso;
        }else
        {
            int numBag = M-pesoAct;
            float beneficio = std::round((numBag*i->beneficio / i->peso )*1000)/1000;
            
            solucion.push_back(Bag{M-pesoAct, beneficio});
            pesoAct=M;
        }
        if(candidatos.empty()) return;

        candidatos.erase(i);
    }
    

}

float getBeneficio(std::vector<Bag>&S )
{
    float s=0;
    for(auto a: S)
        s+=a.beneficio;
    return s;
}

void printBenecios(std::vector<Bag> &solucion)
{
    std::cout << "\tObjetos en la mochila: " << std::endl;
    for (Bag& Bag : solucion) {
        std::cout << "\tPeso: " << Bag.peso << ", beneficio: " << Bag.beneficio << std::endl;
    }
    std::cout<<"\tBeneficio total: "<<getBeneficio(solucion)<<std::endl;
    std::cout<<std::endl;
    solucion.clear();
}
int main() {
    int capacidadMochila = 10;
    //int capacidadMochila = 20;
    std::vector<Bag> candidatos;
    //std::vector<Bag> candidatos =  {{18, 25}, {15, 24}, {10, 15}};
    std::vector<Bag> solucion;
    
    candidatos =  {{10, 10}, {3, 9}, {3, 9}, {4, 9}};
    std::cout<<"Candidatos"<<std::endl;
    for (Bag& Bag: candidatos)
    {
        std::cout << "\tPeso: " << Bag.peso << ", beneficio: " << Bag.beneficio << std::endl;
    }
    

    std::cout<<"Solucion Criterio 1: "<<std::endl;
    getBag(capacidadMochila, candidatos, solucion, seleccionarCrit1);
    printBenecios(solucion);
    
    candidatos =  {{10, 10}, {3, 9}, {3, 9}, {4, 9}};
    std::cout<<"Solucion Criterio 2: "<<std::endl;
    getBag(capacidadMochila, candidatos, solucion, seleccionarCrit2);
    printBenecios(solucion);
    
    candidatos =  {{10, 10}, {3, 9}, {3, 9}, {4, 9}};
    std::cout<<"Solucion Criterio 3: "<<std::endl;
    getBag(capacidadMochila, candidatos, solucion, seleccionarCrit3);
    printBenecios(solucion);

    
    
    
    return 0;
}