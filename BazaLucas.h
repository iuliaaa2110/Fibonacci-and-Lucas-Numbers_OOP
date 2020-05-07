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

    NrMare *zero;

    BazaLucas()
    {
        zero=new NrMare("0");

        if (firstTimeL == 0)
        {
            vL.push_back(new NrMare("1"));
            vL.push_back(new NrMare("3"));
            firstTimeL = 1;
        }

         if (firstTimeF == 0)
        {
            vF.push_back(zero);
            vF.push_back(new NrMare("1"));
            firstTimeF = 1;
        }
    }

    ~BazaLucas(){
        delete zero;
    }

    int find_(std::vector<NrMare*> v, NrMare x)    //imi returneaza pozitia celui mai mare element<=x in vector
    {
        for(int i=0;i<v.size();i++)
            if(x<*v[i])  //daca am depasit valoarea lui x
                return i-1;

        return v.size()-1;
    }

    void generate_(std::vector<NrMare*> &v,NrMare n,int i)
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

    void descompunere(std::vector<NrMare*> v)
    {
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
};

#endif // BAZALUCAS_H_INCLUDED
