#include "graf_macierz.hh"
#include <cstdlib>
#include <ctime>

template<int ROZMIAR>
graf_macierz<ROZMIAR>::graf_macierz()
{
    for(int i=0; i<ROZMIAR; i++)
        for(int j=0; j<ROZMIAR; j++)
            macierz[i][j] = 0;              //Zapelnij macierz zerami
}

template<int ROZMIAR>
void graf_macierz<ROZMIAR>::stworz(float gestosc)
{
    int i = 0;
    int zmiana = 1;
    int koniec = ROZMIAR-1;

    int suma = 0;
    srand(time(NULL));

    for(int i=0; i<ROZMIAR; i++)
        for(int j=0; j<ROZMIAR; j++)
            macierz[i][j] = 0;              //Zapelnij macierz zerami

    for(int i=0; i<ROZMIAR; i++)
        suma += i;                          //Policz najwieksza mozliwa ilosc wierzcholkow

    for(int l=0; l<=(suma-1)*gestosc; l++)
    {
        macierz[i][i+zmiana] = rand()%99+1;    //Uzupelniaj do uzyskania zadanej gestosci

        i++;
        if(i == koniec)                     //Jezeli i doszlo do konca wiersza
        {
            i = 0;                          //Ustaw kolumne na zero
            zmiana ++;                    //Ustaw startowa kolumnê na +1
            koniec --;                    //Przestaw koniec wiersza
        }
    }

    for(i=0; i<ROZMIAR; i++)
        for(int j=0; j<=i; j++)
            macierz[i][j] = macierz[j][i];  //Ustaw dolny trójkat macierzy na identyczny do gornego
}

template<int ROZMIAR>
int graf_macierz<ROZMIAR>::get(int rzad,int kolumna)
{
    return macierz[rzad][kolumna];
}

template<int ROZMIAR>
void graf_macierz<ROZMIAR>::set(int rzad,int kolumna,int x)
{
    macierz[rzad][kolumna] = x;
}
