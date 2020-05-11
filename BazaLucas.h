#ifndef BAZALUCAS_H_INCLUDED
#define BAZALUCAS_H_INCLUDED

#include<vector>

class BazaLucas:public NrMare
{
    protected:

    static std::vector<NrMare*> vL;
    static int firstTimeL;

    static std::vector<NrMare*> vF;
    static int firstTimeF;

    BazaLucas();

    int find_(std::vector<NrMare*> v, NrMare x);    //imi returneaza pozitia celui mai mare element<=x in vector
    void generate_(std::vector<NrMare*> &v,NrMare n,int i);
    void descompunere(std::vector<NrMare*> v);
};

#endif // BAZALUCAS_H_INCLUDED
