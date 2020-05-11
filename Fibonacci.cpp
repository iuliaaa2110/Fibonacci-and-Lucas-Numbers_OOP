#include "Fibonacci.h"
#include<iostream>
int Fibonacci::firstTimeF = 0;
std::vector<NrMare*> Fibonacci::vF;

Fibonacci::Fibonacci(){

    if (firstTimeF == 0)
    {
        vF.push_back(new NrMare("0"));
        vF.push_back(new NrMare("1"));
        firstTimeF = 1;
    }

/*    for(int i=0;i<v.size();i++)
        std::cout<<v[i]<<" ";
    std::cout<<std::endl;*/
}
