#include "algorytmy_macierz.hh"
#include "graf_macierz.cpp"
#include <iostream>

template<int ROZMIAR>
graf_macierz<ROZMIAR> prim(graf_macierz<ROZMIAR> gm)
{
    graf_macierz<ROZMIAR> wynik;
    int W[ROZMIAR];
    int kraw;
    bool petla;
    int min;
    int poz[2];

    for(int i=0;i<ROZMIAR;i++)
        W[i]=0;
    for(int i=1;i<ROZMIAR;i++)
    {
        min = 100;

        for(int v=0;v<i;v++)
            for(int j=0;j<ROZMIAR;j++)
            {
                petla=1;

                for(int l=0;l<ROZMIAR;l++)
                    if(W[l]==j)
                        petla=0;

                kraw = gm.get(W[v],j);
                if(kraw < min && kraw != 0 && petla)
                {
                    min = kraw;
                    poz[0]=v;
                    poz[1]=j;
                }
            }

        W[i]=poz[1];
        wynik.set(W[poz[0]],poz[1], gm.get(W[poz[0]],poz[1]));
        gm.set(W[poz[0]],poz[1],0);
    }

    for(int i=0;i<ROZMIAR;i++)
        for(int j=0;j<=i;j++)
            if(wynik.get(j,i) != 0)
                wynik.set(i,j,wynik.get(j,i));
            else
                wynik.set(j,i,wynik.get(i,j));

    return wynik;
}


template<int ROZMIAR>
graf_macierz<ROZMIAR> kruskal(graf_macierz<ROZMIAR> gm)
{
    graf_macierz<ROZMIAR> wynik;
    int W[ROZMIAR];
    int kraw;
    bool petla;
    int min;
    int poz[2];

    for(int i=0; i<ROZMIAR; i++)
        W[i] = ROZMIAR;
    for(int i=0; i<ROZMIAR-1; i++)
    {
        min = 100;

        for(int w=0; w<ROZMIAR; w++)
            for(int k=0; k<ROZMIAR; k++)
            {
                petla = 1;

                for(int j=0; j<ROZMIAR; j++)
                    if(W[j] == k)
                    {
                        petla = 0;
                    }

                kraw = gm.get(w,k);
                if(kraw < min && kraw != 0 && petla)
                {
                    min=kraw;
                    poz[0] = w;
                    poz[1] = k;
                }

            }

        W[i]=poz[1];
        wynik.set(poz[0],poz[1], gm.get(poz[0],poz[1]));
        gm.set(poz[0],poz[1],0);
        gm.set(poz[1],poz[0],0);
    }

    for(int i=0;i<ROZMIAR;i++)
        for(int j=0;j<=i;j++)
            if(wynik.get(j,i) != 0)
                wynik.set(i,j,wynik.get(j,i));
            else
                wynik.set(j,i,wynik.get(i,j));

    return wynik;
}
