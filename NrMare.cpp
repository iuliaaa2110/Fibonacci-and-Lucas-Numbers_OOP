#include "NrMare.h"

NrMare::NrMare()
{
    n=0;
    v=NULL;
}

NrMare::NrMare(char s[MAX])
{
    n=strlen(s);
    v=new int[n];

    for(int i=0;i<n;i++)
        v[i]=(s[i]-'0');
}

NrMare::NrMare(NrMare &ob1)
{
    n=ob1.n;
    v=new int[n];
    for(int i=0;i<n;i++)
        v[i]=ob1.v[i];
}

NrMare::~NrMare()
{
    delete &n;
    delete []v;
}

void NrMare::read()
    {
        char s[MAX];
        int i;

        std::cin>>s;
        this->n=strlen(s);
        this->v=new int[this->n];

        for(i=0;i<this->n;i++)
            this->v[i]=(s[i]-'0');

    }

void Swap(NrMare &ob1, NrMare &ob2)
    {
        std::swap(ob1.n,ob2.n);
        std::swap(ob1.v,ob2.v);
    }

std::ostream& operator <<(std::ostream &out, NrMare &ob1)
{
    int i;
    for(i=0;i<ob1.n;i++)
        out<<ob1.v[i];
    return out;
}

NrMare &operator +(NrMare &ob1,NrMare &ob2)
{
    int i,i1=ob1.n-1,i2=ob2.n-1,s=0,n2=std::max(ob1.n,ob2.n)+1;
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

