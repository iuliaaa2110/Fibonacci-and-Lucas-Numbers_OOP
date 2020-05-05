#ifndef BAZALUCAS_H_INCLUDED
#define BAZALUCAS_H_INCLUDED

class BazaLucas:public NrMare
{
    protected:
    NrMare *zero;

    BazaLucas(){
        zero=new NrMare("0");
    }

    ~BazaLucas(){
        delete zero;
    }

     void descompunere(NrMare &p1,NrMare &p2)
     {
        NrMare c,a,b;
        NrMare n=*this;

        while(*zero<n)
        {
            a=p1;
            b=p2;

            while(b<n || b==n)
            {
                c=a+b;
                a=b;
                b=c;

            }
            std::cout<<a<<" ";
            n=n-a;
        }
     }
};

#endif // BAZALUCAS_H_INCLUDED
