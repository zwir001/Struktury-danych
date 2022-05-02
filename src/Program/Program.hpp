#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "src/Bst/Bst.hpp"
#include "src/DrzewoCzerwonoCzarne/DrzewoCzerwonoCzarne.hpp"
#include "src/Lista/Lista.hpp"
#include "src/Tablica/Tablica.hpp"
#include "src/Kopiec/Kopiec.hpp"

#include <string>
#include <iostream>
#include <random>
#include <windows.h>
#include <iomanip>
#include <fstream>

class Program{
    public:

    static void projektUI();

    private:

    struct file{
        int tab[40];
        int rozmiar;
    };

    static void wyborStruktury(char tryb);
    static void projektUITablica(char& tryb);
    static void projektUILista(char& tryb);
    static void projektUIKopiec(char& tryb);
    static void projektUIBst(char& tryb);
    static void projektUIDrzewoCzerwonoCzarne(char& tryb);
    static bool wczytajDaneTestowe(file* plik);
    
};

#endif