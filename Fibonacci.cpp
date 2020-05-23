#include "Fibonacci.h"

int Fibonacci::firstTimeF = 0;
std::vector<NrMare*> Fibonacci::vF;

Fibonacci::Fibonacci(){

    if (firstTimeF == 0)
    {
        vF.push_back(new NrMare("0"));
        vF.push_back(new NrMare("1"));
        firstTimeF = 1;
    }
    
}

void Fibonacci:: descompunere(){
    
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Fibonacci este:"<<std::endl;
        BazaLucas::descompunere(vF);    //pe zero il mosteneste din BazaLucas
        std::cout<<std::endl;
    }
