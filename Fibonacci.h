#ifndef FIBONACCI_H_INCLUDED
#define FIBONACCI_H_INCLUDED
#include "BazaLucas.h"

class Fibonacci: public BazaLucas ///suma de numere fibonacci
{
public:

    static int firstTimeF;
    static std::vector<NrMare*> vF;

    Fibonacci();

    virtual void descompunere()
    {
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Fibonacci este:"<<std::endl;
        BazaLucas::descompunere(vF);    //pe zero il mosteneste din BazaLucas
        std::cout<<std::endl;
    }
};


#endif // FIBONACCI_H_INCLUDED
