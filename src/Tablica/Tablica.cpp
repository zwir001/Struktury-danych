#include<Tablica.hpp>

Tablica::Tablica(int rozmiar){  //Konstruktor obiektu klasy Tablica
    this->rozmiar=rozmiar;
    this->tablica = new int[this->rozmiar];
    for(int i=0; i<rozmiar; i++){
        *((this->tablica)+i)=0;
    }
}

void Tablica::wyswietlOdPoczatku(){ //Funkcja wyświetlająca zawartość tablicy od początku
    std::cout<<std::endl<<"Zawartość tablicy od początku: "<<std::endl;
    for(int i=0; i<this->rozmiar; i++){
        std::cout<<*(this->tablica+i)<<" ";
    }
    std::cout<<std::endl;
}

void Tablica::wyswietlOdKonca(){    //Funkcja wyświetlająca zawartość tablicy od końca
    std::cout<<std::endl<<"Zawartość tablicy od końca: "<<std::endl;
    for(int i=rozmiar-1; i>=0; i--){
        std::cout<<*((this->tablica)+i)<<" ";
    }
    std::cout<<std::endl;
}

void Tablica::wpiszWartosc(int element, int indeks){    //Funkcja zmiany wartości elementu w tablicy o danym indeksie
    *(this->tablica+indeks)=element;
}

void Tablica::dodajPoczatek(int element){   //Funkcja wstawienia elementu o zadanej wartości na początek tablicy
    int* tmp=new int[this->rozmiar+1];
    std::copy(this->tablica, this->tablica+this->rozmiar, tmp+1);
    *tmp=element;
    delete[] this->tablica;
    tablica=tmp;
    this->rozmiar++;
}

void Tablica::dodajWybraneMiejsce(int element, int indeks){ //Funkcja wstawienia elementu o zadanej wartości na miejsce o zadanym indeksie w tablicy
    if(indeks==this->rozmiar){
        dodajKoniec(element);
        return;
    }
    if(indeks==0){
        dodajPoczatek(element);
        return;
    }
    if(indeks>rozmiar){
        std::cout<<std::endl<<"Indeks przekracza rozmiar tablicy"<<std::endl;
    }
    int* tmp=new int[this->rozmiar+1];
    std::copy(this->tablica, this->tablica+indeks, tmp);
    std::copy(this->tablica+indeks, this->tablica+this->rozmiar, tmp+indeks+1);
    *(tmp+indeks)=element;
    delete[] this->tablica;
    tablica=tmp;
    this->rozmiar++;
}

void Tablica::dodajKoniec(int element){ //Funkcja wstawienia elementu o zadanej wartości na koniec tablicy
    int* tmp=new int[this->rozmiar+1];
    std::copy(this->tablica, this->tablica+this->rozmiar, tmp);
    *(tmp+rozmiar)=element;
    delete[] this->tablica;
    tablica=tmp;
    this->rozmiar++;
}

void Tablica::usunPoczatek(){   //Funkcja usunięcia elementu z początku tablicy
    if(rozmiar==0){
        std::cout<<"Tablica jest pusta, nie można usunąć więcej elementów";
        return;
    }
    int* tmp=new int[this->rozmiar-1];
    std::copy(this->tablica+1, this->tablica+this->rozmiar, tmp);
    delete[] this->tablica;
    tablica=tmp;
    this->rozmiar--;
}

void Tablica::usunWybraneMiejsce(int indeks){   //Funkcja usunięcia elementu o zadanym indeksie z tablicy
    if(indeks==this->rozmiar-1){
        usunKoniec();
        return;
    }
    if(indeks==0){
        usunPoczatek();
        return;
    }
    if(indeks>rozmiar-1){
        std::cout<<std::endl<<"Indeks przekracza rozmiar tablicy"<<std::endl;
        return;
    }
    int* tmp=new int[this->rozmiar-1];
    std::copy(this->tablica, this->tablica+indeks, tmp);
    std::copy(this->tablica+indeks+1, this->tablica+this->rozmiar, tmp+indeks);
    delete[] this->tablica;
    tablica=tmp;
    this->rozmiar--;
}

void Tablica::usunKoniec(){ //Funkcja usunięcia elementu z końca tablicy
    if(rozmiar==0){
        std::cout<<"Tablica jest pusta, nie można usunąć więcej elementów";
        return;
    }
    int* tmp=new int[this->rozmiar-1];
    std::copy(this->tablica, this->tablica+this->rozmiar-1, tmp);
    delete[] this->tablica;
    tablica=tmp;
    this->rozmiar--;
}

void Tablica::wyszukajElement(int element){ //Funkcja sprawdzająca czy element o zadanej wartości znajduje się w tablicy
    for(int i=0; i<rozmiar; i++){
        if(*((this->tablica)+i)==element){
            std::cout<<std::endl<<"Wyszukiwany element o wartości "<<element<<" znajduje się na miejscu o indeksie: "<<i<<std::endl;
            return;
        }
    }
    std::cout<<std::endl<<"Poszukiwanego elementu o wartości "<<element<<" nie ma w tablicy"<<std::endl;
}




