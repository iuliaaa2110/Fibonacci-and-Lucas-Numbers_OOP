#include <iostream>
#include "NrMare.h"
#include "BazaLucas.h"
#include "Fibonacci.h"
#include "Lucas.h"

int main()
{
    int n;
    char a;

    std::cout<<"n=";
    std::cin>>n;

    NrMare **v=new NrMare*[n+1];

    for(int i=0;i<n;i++)
    {
        std::cout<<std::endl<<i+1<<") Tasteaza F pentru Fibonacci sau L pentru Lucas"<<std::endl;
        std::cin>>a;

        if(a=='F')
            v[i]=new Fibonacci();
        if(a=='L')
            v[i]=new Lucas();

        ///numarul nu trebuie sa fie de vreun tip anume, dar descompunerea lui se va face in suma de numere de tip F/L
        std::cout<<"Acum tasteaza numarul pe care vrei sa l descompui"<<std::endl<<"nr"<<i+1<<"= ";

        v[i]->read();
        v[i]->descompunere();

        std::cout<<std::endl;
    }

    return 0;
}
