#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>

class Lista{
    public:

    struct ElementListy{
        int wartosc;
        ElementListy *prev, *next;
    };

    ElementListy* glowa;
    ElementListy* ogon;
    Lista(int wartosc);

    void wyswietlOdPoczatku();
    void wyswietlOdKonca();
    void dodajPoczatek(int element);
    void dodajWybraneMiejsce(int element, int indeks);
    void dodajKoniec(int element);
    void usunPoczatek();
    void usunWybraneMiejsce(int index);
    void usunKoniec();
    void wyszukajElement(int element);

    private:
    ElementListy* znajdzOgon();
};
#endif