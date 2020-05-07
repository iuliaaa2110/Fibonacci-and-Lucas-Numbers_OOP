#ifndef LUCAS_H_INCLUDED
#define LUCAS_H_INCLUDED
#include<algorithm>
#include<vector>

class Lucas: public BazaLucas ///suma de numere Lucas
{
public:

    void descompunere()
    {
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Lucas este:"<<std::endl;
        BazaLucas::descompunere(vL);
        std::cout<<std::endl;
    }

};


#endif // LUCAS_H_INCLUDED
