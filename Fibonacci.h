#ifndef FIBONACCI_H_INCLUDED
#define FIBONACCI_H_INCLUDED
#include<algorithm>
#include<vector>

class Fibonacci: public BazaLucas ///suma de numere fibonacci
{
public:

    virtual void descompunere()
    {
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Fibonacci este:"<<std::endl;
        BazaLucas::descompunere(vF);    //vF e declarat in Baza
        std::cout<<std::endl;
    }
};


#endif // FIBONACCI_H_INCLUDED
