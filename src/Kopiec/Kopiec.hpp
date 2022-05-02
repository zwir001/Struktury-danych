#ifndef KOPIEC_HPP
#define KOPIEC_HPP

#include <iostream>
#include <iomanip>
#include <math.h>

class Kopiec{
    public:

    int* kopiec;
    int rozmiar=0;

    Kopiec(int rozmiar);

    void wyswietlKopiec();
    void dodajElement(int element);
    void usunKorzen();
    void wyszukajElement(int element);

    private:
    void rysujKopiec(int nrPietra, int przerwa, int obecnyIndeks, int przesuniecie);
    int rodzic(int index);
    int lewySyn(int index);
    int prawySyn(int index);
};

#endif