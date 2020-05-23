#ifndef FIBONACCI_H_INCLUDED
#define FIBONACCI_H_INCLUDED
#include "BazaLucas.h"

class Fibonacci: public BazaLucas ///suma de numere fibonacci
{
public:

    static int firstTimeF;
    static std::vector<NrMare*> vF;

    Fibonacci();

    void descompunere();
    
};


#endif // FIBONACCI_H_INCLUDED
