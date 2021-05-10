#include "graf_lista.hh"
#include <cstdlib>
#include <ctime>

template<int ROZMIAR>
graf_lista<ROZMIAR>::graf_lista()
{
    ilosc_kraw = 0;
}

template<int ROZMIAR>
graf_lista<ROZMIAR>::get_ik()
{
    return ilosc_kraw;
}

template<int ROZMIAR>
krawedz graf_lista<ROZMIAR>::get_k(int index)
{
    return kraw[index];
}

template<int ROZMIAR>
void graf_lista<ROZMIAR>::set_k(krawedz k)
{
    kraw[ilosc_kraw++] = k;
}

template<int ROZMIAR>
void graf_lista<ROZMIAR>::usun(int docel)
{
    int poz = 0;
    while(kraw[poz].docel != docel)
    {
        poz++;
    }

    for(int i = poz; i < ilosc_kraw-1; i++)
        kraw[i] = kraw [i+1];

    ilosc_kraw--;
}

template<int ROZMIAR>
graf_lista<ROZMIAR>* gr_li_stworz(float gestosc)
{
    graf_lista<ROZMIAR> *lista_w;
    graf_lista<ROZMIAR> elem;
    krawedz kraw;
    int wierzcholek = 0;
    int nast;
    int koniec = ROZMIAR-1;
    int zmiana = 1;
    int suma = 0;

    lista_w = new graf_lista<ROZMIAR>[ROZMIAR];
    srand(time(NULL));

    for(int i=0; i<ROZMIAR; i++)
        suma += i;

    for(int i=0; i<=(suma-1)*gestosc; i++)
    {
        nast = wierzcholek + zmiana;

        kraw.waga = rand()%99 + 1;
        kraw.docel = nast;

        lista_w[wierzcholek].set_k(kraw);

        kraw.docel = wierzcholek;

        lista_w[nast].set_k(kraw);

        wierzcholek++;
        if(wierzcholek == koniec)
            {
                wierzcholek = 0;
                zmiana ++;
                koniec --;
            }
    }

    return lista_w;
}
