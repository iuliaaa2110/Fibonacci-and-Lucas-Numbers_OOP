#ifndef NRMARE_H_INCLUDED
#define NRMARE_H_INCLUDED

#include<iostream>
#include<cstring>
#include<climits>
//#define MAX 1000000
const int MAX=1000000;

class NrMare{
protected:
    int n,*v;

public:
    NrMare();   //constructor de initializare
    NrMare(char s[MAX]);//constructor de initializare cu un sir dat
    NrMare(NrMare&); //constructor de copiere
    ~NrMare();
    
    friend void Swap(NrMare &ob1,NrMare &ob2);

    NrMare &operator =(NrMare ob2)
    {
        Swap(*this,ob2);
        return *this;
    }

    virtual void read()
    {
        char s[MAX];
        int i;

        std::cin>>s;
        this->n=strlen(s);
        this->v=new int[this->n];

        for(i=0;i<this->n;i++)
            this->v[i]=(s[i]-'0');

    }

    friend std::ostream& operator <<(std::ostream &out, NrMare &ob1);
    friend NrMare &operator +(NrMare &ob1,NrMare &ob2);
    friend NrMare &operator -(NrMare &ob1,NrMare &ob2);
    friend bool operator ==(NrMare &ob1,NrMare &ob2);
    friend bool operator <(NrMare &ob1,NrMare &ob2);
    virtual void descompunere(){};
};

#endif // NRMARE_H_INCLUDED
