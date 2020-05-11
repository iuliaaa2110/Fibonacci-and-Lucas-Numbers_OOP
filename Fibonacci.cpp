#include "Fibonacci.h"

int Fibonacci::firstTimeF = 0;
std::vector<NrMare*> Fibonacci::vF;

Fibonacci::Fibonacci(){

    if (firstTimeF == 0)
    {
        vF.push_back(new NrMare("0"));
        vF.push_back(new NrMare("1"));
        firstTimeF = 1;
    }
    
}
