#ifndef FIBONACCI_H_INCLUDED
#define FIBONACCI_H_INCLUDED

class Fibonacci: public NrMare ///suma de numere fibonacci
{
public:

    void read()
    {
        char s[Max];
        int i;

        std::cin>>s;
        this->n=strlen(s);
        this->v=new int[this->n];

        for(i=0;i<this->n;i++)
            this->v[i]=(s[i]-'0');
    }

    void descompunere()
    {
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Fibonacci este:"<<std::endl;
        NrMare c,zero("0"),k,unu("1"),trei("3"),a,b;
        NrMare n=*this; /// poate nu o sa iti placa ca am facut asa(poate asteptai sa am Fibonacci n;), ideea e ca m am blocat la scadere (^)
        int i;
        while(zero<n)
        {
            a=zero;
            b=unu;

            while(a+b<n || a+b==n)
            {
                c=a+b;
                a=b;
                b=c;
            }
                        std::cout<<c<<" ";
            n=n-c;   ///(^) aici cand am incercat sa folosesc this si sa fac cast nu a mers sub nici o forma, din cauza atribuirii
    }                   ///this ul era de tip Fibonacci si c ul de tip NrMare si nu m a lasat sa fac *this=*this-c;
             std::cout<<std::endl;               ///Am incercat si *this=const_cast<NrMare>(*this-c)
    }                   ///exista vreo modalitate sa pot sa fac  Fibonacci=Fibonacci-NrMare?
};                      ///sau e bine asa cum am facut?


#endif // FIBONACCI_H_INCLUDED
