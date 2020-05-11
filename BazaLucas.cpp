#include "BazaLucas.h"


int BazaLucas:: find_(std::vector<NrMare*> &v, NrMare x)    //imi returneaza pozitia celui mai mare element<=x in vector
    {
        for(int i=0;i<v.size();i++)
            if(x<*v[i])  //daca am depasit valoarea lui x
                return i-1;

        return v.size()-1;
    }

void BazaLucas:: generate_(std::vector<NrMare*> &v,NrMare n,int i)
    {
        NrMare a=*v[v.size()-2], b=*v[v.size()-1], c;

        while(b<n)
        {
            c=a+b;
            a=b;
            b=c;
            v.push_back(new NrMare(b));
        }

    }

void BazaLucas::descompunere(std::vector<NrMare*> &v)
    {
        NrMare *zero=new NrMare("0");
        NrMare n=*this;
        int i=find_(v,n);

        if(i==v.size()-1)   //inseamna ca nu am toate numerele generate pana la n
            generate_(v,n,i);

        while(*zero<n)
        {
            i=find_(v,n);
            n=n-*v[i];
            std::cout<<*v[i]<<" ";
        }
    }
