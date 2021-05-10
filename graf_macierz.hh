#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

template<int ROZMIAR>
class graf_macierz
{
private:
    int macierz[ROZMIAR][ROZMIAR];
public:
    graf_macierz();
    void stworz(float gestosc);

    int get(int rzad,int kolumna);
    void set(int rzad,int kolumna,int x);
};

#endif // GRAF_H_INCLUDED
