#ifndef TABLICA_HPP
#define TABLICA_HPP

#include <iostream>

class Tablica{
    public:

    int* tablica;
    int rozmiar;

    Tablica(int rozmiar);
    
    void wyswietlOdPoczatku();
    void wyswietlOdKonca();
    void wpiszWartosc(int element, int indeks);
    void dodajPoczatek(int element);
    void dodajWybraneMiejsce(int element, int indeks);
    void dodajKoniec(int element);
    void usunPoczatek();
    void usunWybraneMiejsce(int indeks);
    void usunKoniec();
    void wyszukajElement(int element);
};

#endif