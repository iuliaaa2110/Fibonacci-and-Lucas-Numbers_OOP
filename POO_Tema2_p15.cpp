#include<iostream>
#include<string.h>
#include<climits>
#define Max 1000000

using namespace std;

class NrMare{
protected:
    int n,*v;

public:
    NrMare();   //constructor de initializare
    NrMare(char s[Max]);
    NrMare(NrMare&); //constructor de copiere

    NrMare &operator =(NrMare &ob2)
    {
        int i;

        if(this->n<ob2.n)
        {
            for(i=this->n;i<ob2.n;i++)
                this->v=new int();
            this->n=ob2.n;
        }

        if(this->n>ob2.n)
            for(i=ob2.n;i<this->n;i++)
                delete [] &this->v[i];

        //acum au aceeasi lungime:
        this->n=ob2.n;
        for(i=0;i<this->n;i++)
            this->v[i]=ob2.v[i];

        return *this;
    }

    virtual void read()
    {
        char s[Max];
        int i;

        cin>>s;
        this->n=strlen(s);
        this->v=new int[this->n];

        for(i=0;i<this->n;i++)
            this->v[i]=(s[i]-'0');

    }

    friend ostream& operator <<(ostream &out, NrMare &ob1);
    friend NrMare &operator +(NrMare &ob1,NrMare &ob2);
    friend NrMare &operator -(NrMare &ob1,NrMare &ob2);
    friend bool operator ==(NrMare &ob1,NrMare &ob2);
    friend bool operator <(NrMare &ob1,NrMare &ob2);
    virtual void descompunere(){};

};

NrMare::NrMare()
{
    n=0;
    v=NULL;
}

NrMare::NrMare(char s[Max])
{
    n=strlen(s);
    v=new int[n];

    for(int i=0;i<n;i++)
        v[i]=(s[i]-'0');
}

NrMare::NrMare(NrMare &ob1)
{
    n=ob1.n;
    v=new int[n+1];
    for(int i=0;i<n;i++)
        v[i]=ob1.v[i];
}

ostream& operator <<(ostream &out, NrMare &ob1)
{
    int i;
    for(i=0;i<ob1.n;i++)
        out<<ob1.v[i];
    return out;
}

NrMare &operator +(NrMare &ob1,NrMare &ob2)
{
    int i,i1=ob1.n-1,i2=ob2.n-1,s=0,n2=max(ob1.n,ob2.n)+1;
    NrMare *ob3 = new NrMare();
    ob3->v=new int[n2+1];
    for(i=n2-1;i>=0;i--)
    {
        if(i1>=0)
            s+=ob1.v[i1];

        if(i2>=0)
            s+=ob2.v[i2];

        ob3->v[i]=s%10;

        if(s<10)
            s=0;
        else
            s=1;    ///tin 1 in minte
        i1--;
        i2--;
    }

    if(ob3->v[0]==0)
    {
        for(i=0;i<n2-1;i++)
            ob3->v[i]=ob3->v[i+1];
        n2--;
    }

    ob3->n=n2;
    return *ob3;
}

NrMare &operator -(NrMare &ob1,NrMare &ob2)
{
    if(ob1<ob2)
    {
        NrMare *ob3 = new NrMare("0");
        return *ob3;
    }
    if(ob1==ob2)
    {
        NrMare *ob3 = new NrMare("0");
        return *ob3;
    }
    NrMare *ob3 = new NrMare();
    int i1=ob1.n-1, i2=ob2.n-1, y,i;
    ob3->n=ob1.n;
    ob3->v=new int[ob3->n];

    while(i1>=0)
    {
        if(i2>=0)
        {
            if(ob1.v[i1]<ob2.v[i2])
            {
                ob3->v[i1]=ob1.v[i1]+10-ob2.v[i2];

                y=i1-1;

                while(ob1.v[y]==0)
                {
                    ob1.v[y]=9;
                    y--;
                }
                ob1.v[y]--;
            }
            else
                {ob3->v[i1]=ob1.v[i1]-ob2.v[i2];}
        }
        else
            ob3->v[i1]=ob1.v[i1];
        i1--;
        i2--;
    }

    if(ob3->v[0]==0)
    {
        y=0;
        while(ob3->v[y]==0)
            y++;

        for(i=0;i<ob1.n-y;i++)
            ob3->v[i]=ob3->v[i+y];
        ob3->n-=y;
    }

    return *ob3;
}

bool operator ==(NrMare &ob1,NrMare &ob2)
{
    if(ob1.n!=ob2.n)
        return false;

    int i=0;

    while(i<ob1.n && ob1.v[i]== ob2.v[i])
        i++;

    if(i==ob1.n)
        return true;

    return false;

}

bool operator <(NrMare &ob1,NrMare &ob2)
{
    if(ob1==ob2)
        return false;

    if(ob1.n>ob2.n)
        return false;

    if(ob1.n<ob2.n)
        return true;

    int i=0;    //daca au aceeasi lungime dar sunt diferite.

    while(ob1.v[i]==ob2.v[i])    //nu e nevoie de i<ob1.n, daca am ajuns pana aici inseamna ca sigur au o cifra diferita!
        i++;

    if(ob1.v[i]>ob2.v[i])
        return false;

    return true;

}


class Fibonacci: public NrMare ///suma de numere fibonacci
{
public:

    void read()
    {
        char s[Max];
        int i;

        cin>>s;
        this->n=strlen(s);
        this->v=new int[this->n];

        for(i=0;i<this->n;i++)
            this->v[i]=(s[i]-'0');
    }

    virtual void descompunere()
    {
        cout<<"Descompunerea numarului "<<*this<<" in suma de numere Fibonacci este:"<<endl;
        NrMare c,zero("0"),k,unu("1"),trei("3"),a,b;
        NrMare n=*this; /// poate nu o sa iti placa ca am facut asa, ideea e ca m am blocat la scadere (^)
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
                        cout<<c<<" ";
            n=n-c;   ///(^) aici cand am incercat sa folosesc this si sa fac cast nu a mers sub nici o forma, din cauza atribuirii
    }                   ///this ul era de tip Fibonacci si c ul de tip NrMare si nu m a lasat sa fac *this=*this-c;
             cout<<endl;               ///Am incercat si *this=const_cast<NrMare>(*this-c)
    }                   ///exista vreo modalitate sa pot sa fac  Fibonacci=Fibonacci-NrMare?
};                      ///sau e bine asa cum am facut?

class Lucas: public NrMare ///suma de numere Lucas
{
public:

    void read()
    {
        char s[Max];
        int i;

        cin>>s;
        this->n=strlen(s);
        this->v=new int[this->n];

        for(i=0;i<this->n;i++)
            this->v[i]=(s[i]-'0');
    }

    void descompunere()
    {
        cout<<"Descompunerea numarului "<<*this<<" in suma de numere Lucas este:"<<endl;
        NrMare c,zero("0"),k,unu("1"),trei("3"),a,b;
        NrMare n=*this; /// poate nu o sa iti placa ca am facut asa, ideea e ca m am blocat la scadere (^)
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

            cout<<a<<" ";
            n=n-a;   ///(^) aici cand am incercat sa folosesc this si sa fac cast nu a mers sub nici o forma, din cauza atribuirii
        }                   ///this ul era de tip Fibonacci si c ul de tip NrMare si nu m a lasat sa fac *this=*this-c;
                  cout<<endl;          ///Am incercat si *this=const_cast<NrMare>(*this-c)
    }                   ///exista vreo modalitate sa pot sa fac  Fibonacci=Fibonacci-NrMare?
};                      ///sau e bine asa cum am facut?


int main()
{

    NrMare **v=new NrMare*[3];
    int n;
    char a;

    cout<<"n=";
    cin>>n;

    for(int i=0;i<=n;i++)
    {
        cout<<endl<<i+1<<") Tasteaza F pentru Fibonacci sau L pentru Lucas"<<endl;
        cin>>a;

        if(a=='F')
            v[i]=new Fibonacci();
        if(a=='L')
            v[i]=new Lucas();

        cout<<"Acum tasteaza numarul pe care vrei sa l descompui"<<endl<<"nr"<<i+1<<"= ";

        v[i]->read();
        v[i]->descompunere();

        cout<<endl;
    }

    return 0;
}
