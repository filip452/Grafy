#ifndef GRAF_LISTA_HH_INCLUDED
#define GRAF_LISTA_HH_INCLUDED

struct krawedz
{
    int docel, waga;
};

template<int ROZMIAR>
class graf_lista
{
private:
    krawedz kraw[ROZMIAR];
    int ilosc_kraw;
public:
    graf_lista();

    int get_ik();
    krawedz get_k(int index);
    void set_k(krawedz k);
    void usun(int docel);
};

template<int ROZMIAR>
graf_lista<ROZMIAR>* gr_li_stworz(float gestosc);

#endif // GRAF_LISTA_HH_INCLUDED
