#ifndef FIBONACCI_H_INCLUDED
#define FIBONACCI_H_INCLUDED

class Fibonacci: public BazaLucas ///suma de numere fibonacci
{
public:
    NrMare *unu;

    Fibonacci() {
        unu = new NrMare("1");
    }

    ~Fibonacci(){
        delete unu;
    }

    virtual void descompunere()
    {
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Fibonacci este:"<<std::endl;
        BazaLucas::descompunere(*zero,*unu);    //pe zero il mosteneste din BazaLucas
        std::cout<<std::endl;
    }
};


#endif // FIBONACCI_H_INCLUDED
