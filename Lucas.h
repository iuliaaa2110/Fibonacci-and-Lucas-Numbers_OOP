#ifndef LUCAS_H_INCLUDED
#define LUCAS_H_INCLUDED
#include "BazaLucas.h"

class Lucas: public BazaLucas ///suma de numere Lucas
{
public:

    static std::vector<NrMare*> vL;
    static int firstTimeL;

    Lucas();

    void descompunere();

};


#endif // LUCAS_H_INCLUDED
