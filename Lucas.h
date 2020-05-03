#ifndef LUCAS_H_INCLUDED
#define LUCAS_H_INCLUDED

class Lucas: public NrMare ///suma de numere Lucas
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
        std::cout<<"Descompunerea numarului "<<*this<<" in suma de numere Lucas este:"<<std::endl;
        NrMare c,zero("0"),k,unu("1"),trei("3"),a,b;
        NrMare n=*this;
        int i;
        while(zero<n)
        {
            a=unu;
            b=trei;

            while(b<n || b==n)
            {
                c=a+b;
                a=b;
                b=c;

            }

            std::cout<<a<<" ";
            n=n-a;
        }
        std::cout<<std::endl;
    }
};


#endif // LUCAS_H_INCLUDED
