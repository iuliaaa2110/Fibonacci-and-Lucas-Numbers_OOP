#ifndef LUCAS_H_INCLUDED
#define LUCAS_H_INCLUDED
#include "BazaLucas.h"

class Lucas: public BazaLucas ///suma de numere Lucas
{
public:

    static std::vector<NrMare*> vL;
    static int firstTimeL;

    Lucas();

    void descompunere()
    {
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Lucas este:"<<std::endl;
        BazaLucas::descompunere(vL);
        std::cout<<std::endl;
    }

};


#endif // LUCAS_H_INCLUDED
