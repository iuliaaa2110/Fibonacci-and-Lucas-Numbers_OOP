#ifndef LUCAS_H_INCLUDED
#define LUCAS_H_INCLUDED

class Lucas: public BazaLucas ///suma de numere Lucas
{
public:

    NrMare *unu, *trei;

    Lucas() {
        unu = new NrMare("1");
        trei = new NrMare("3");
    }

    ~Lucas(){
        delete unu;
        delete trei;
    }

    void descompunere()
    {
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Lucas este:"<<std::endl;
        BazaLucas::descompunere(*unu,*trei);
        std::cout<<std::endl;
    }

};


#endif // LUCAS_H_INCLUDED
