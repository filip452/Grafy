#include <iostream>
#include <fstream>
#include <chrono>
#include "algorytmy_macierz.cpp"
#include "algorytmy_lista.cpp"

using namespace std;

#define rozmiar 75 //10, 25, 50, 75, 100

int main()
{
    float gestosc;

    float GEST[4]={0.25, 0.5, 0.75, 1};

    ofstream czasy("Macierz75.txt");
    //ofstream czasy("Lista.txt");

    for(int G=0; G<4; G++)
    {
        gestosc = GEST[G];

        float czas_prim = 0;
        float czas_kruskal = 0;

        for(int j=0;j<100;j++)
        {
            graf_macierz<rozmiar> graf;
            graf.stworz(gestosc);

            //graf_lista<rozmiar> graf;
            //graf = gr_li_stworz<rozmiar>(gestosc);

            auto t_start=std::chrono::high_resolution_clock::now();
            prim(graf);
            auto t_koniec=std::chrono::high_resolution_clock::now();
            czas_prim+=std::chrono::duration<double,std::milli>(t_koniec-t_start).count();

            t_start=std::chrono::high_resolution_clock::now();
            kruskal(graf);
            t_koniec=std::chrono::high_resolution_clock::now();
            czas_kruskal+=std::chrono::duration<double,std::milli>(t_koniec-t_start).count();
        }
        czasy << "Czas dzia³ania algorytmu Prima dla grafu o gestosci " << gestosc*100 << "%:\n";
        czasy << "O rozmiarze " << rozmiar << " wierzcholkow:\n";
        czasy << "  " << czas_prim/100 << "s\n";

        czasy << "Czas dzia³ania algorytmu Kruskala dla grafu o gestosci " << gestosc*100 << "%:\n";
        czasy << "O rozmiarze " << rozmiar << " wierzcholkow:\n";
        czasy << "  " << czas_kruskal/100 << "s\n";
    }

    czasy.close();

    return 0;
}
