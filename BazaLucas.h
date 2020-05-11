#ifndef BAZALUCAS_H_INCLUDED
#define BAZALUCAS_H_INCLUDED
#include<vector>
#include "NrMare.h"

class BazaLucas:public NrMare
{
    protected:

    int find_(std::vector<NrMare*> &v, NrMare x);    //imi returneaza pozitia celui mai mare element<=x in vector
    void generate_(std::vector<NrMare*> &v,NrMare n,int i);
    void descompunere(std::vector<NrMare*> &v);
};

#endif // BAZALUCAS_H_INCLUDED
