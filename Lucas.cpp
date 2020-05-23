#include "Lucas.h"

int Lucas::firstTimeL = 0;
std::vector<NrMare*> Lucas::vL;

Lucas::Lucas(){

    if (firstTimeL == 0)
    {
        vL.push_back(new NrMare("1"));
        vL.push_back(new NrMare("3"));
        firstTimeL = 1;
    }
    
}

void Lucas::descompunere(){
    
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Lucas este:"<<std::endl;
        BazaLucas::descompunere(vL);
        std::cout<<std::endl;
}
