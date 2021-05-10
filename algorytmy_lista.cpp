#include "algorytmy_lista.hh"
#include "graf_lista.cpp"

template<int ROZMIAR>
graf_lista<ROZMIAR>* prim(graf_lista<ROZMIAR> *gl)
{
    graf_lista<ROZMIAR> *wynik;
    krawedz krawedz;
    int W[ROZMIAR];
    int kraw;
    bool petla;
    int min;
    int poz[2];

    wynik = new graf_lista<ROZMIAR>[ROZMIAR];

    for(int i=0; i<ROZMIAR; i++)
        W[i] = 0;

    for(int i=1; i<ROZMIAR; i++)
    {
        min = 100;

        for(int w=0; w<i; w++)
            for(int k=0; k<gl[W[w]].get_ik(); k++)
            {
                petla = 1;

                for(int j=0; j<ROZMIAR; j++)
                    if(gl[W[w]].get_k(k).docel == W[j])
                        petla = 0;

                kraw = gl[W[w]].get_k(k).waga;
                if(kraw < min && kraw != 0 && petla)
                {
                    min = kraw;
                    poz[0] = W[w];
                    poz[1] = gl[W[w]].get_k(k).docel;
                }
            }

        W[i] = poz[1];

        gl[poz[0]].usun(poz[1]);

        gl[poz[1]].usun(poz[0]);

        krawedz.waga=min;

        krawedz.docel=poz[1];
        wynik[poz[0]].set_k(krawedz);

        krawedz.docel=poz[0];
        wynik[poz[1]].set_k(krawedz);
    }

    return wynik;
}

template<int ROZMIAR>
graf_lista<ROZMIAR>* kruskal(graf_lista<ROZMIAR> *gl)
{
    graf_lista<ROZMIAR> *wynik;
    krawedz krawedz;
    int W[ROZMIAR];
    int kraw;
    bool petla;
    int min;
    int poz[2];

    wynik = new graf_lista<ROZMIAR>[ROZMIAR];

    for(int i=0; i<ROZMIAR; i++)
        W[i]=ROZMIAR;

    for(int i=0; i<ROZMIAR-1; i++)
    {
        min = 100;

        for(int w=0; w<ROZMIAR; w++)
            for(int k=0; k<gl[w].get_ik(); k++)
            {
                petla = 1;

                for(int j=0; j<ROZMIAR; j++)
                    if(gl[w].get_k(k).docel == W[j])
                        petla = 0;

                kraw = gl[w].get_k(k).waga;
                if(kraw < min && kraw != 0 && petla)
                {
                    min = kraw;
                    poz[0] = w;
                    poz[1] = gl[w].get_k(k).docel;
                }
            }

    W[i] = poz[1];

    gl[poz[0]].usun(poz[1]);

    gl[poz[1]].usun(poz[0]);

    krawedz.waga=min;

    krawedz.docel=poz[1];
    wynik[poz[0]].set_k(krawedz);

    krawedz.docel=poz[0];
    wynik[poz[1]].set_k(krawedz);
    }

    return wynik;
}
