#ifndef BST_HPP
#define BST_HPP

#include <iostream>

class Bst{

    public:

    struct wezel{
        int wartosc;
        wezel *lewy, *prawy, *rodzic;
    };

    wezel *korzen;

    Bst(int element);

    void wyswietlBst();
    void dodajElement(int element);
    void usunElement(int element);
    void wyszukajElement(int element);
    void rotacjaWLewo(int element);
    void rotacjaWPrawo(int element);
    void rownowazenieDrzewa();

    private:

    wezel* szukaj(wezel* start, int wartosc);
    void dodaj(int element, wezel* start);
    void usun(wezel* start);
    wezel* najLewy(wezel *start);
    void printBT(const std::string& prefix, Bst::wezel* wezel, bool isLeft);
    void printBT(wezel* wezel);
    void rot_L(wezel* A);
    void rot_P(wezel* A);
};

#endif