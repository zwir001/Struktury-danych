#include<Kopiec.hpp>

Kopiec::Kopiec(int element){    //Konstruktor obiektu klasy Kopiec
    this->rozmiar++;
    this->kopiec = new int[this->rozmiar];
    *(this->kopiec)=element;
    for(int i=1; i<rozmiar; i++){
        *((this->kopiec)+i)=0;
    }
}

void Kopiec::wyswietlKopiec(){  //Funkcja wyświetlenia kopca
    std::cout<<std::endl;
    rysujKopiec(0, 64, 0, 0);
}

void Kopiec::dodajElement(int element){ //Funkcja wstawiająca element o zadanej wartości na odpowiednią pozycję w kopcu
    int* tmp=new int[this->rozmiar+1];
    std::copy(this->kopiec, this->kopiec+this->rozmiar, tmp);
    *(tmp+rozmiar)=element;
    delete[] this->kopiec;
    kopiec=tmp;
    this->rozmiar++;

    kopiec[rozmiar-1] = element;
    int index = rozmiar-1;
    while ((index!=0) && (kopiec[rodzic(index)] < kopiec[index]))
    {
    int temp=kopiec[rodzic(index)];
    kopiec[rodzic(index)]=kopiec[index];
    kopiec[index]=temp;
    index=rodzic(index);
    }
}

void Kopiec::usunKorzen(){  //Funkcja usunięcia korzenia kopca
    kopiec[0]=kopiec[rozmiar-1];
    if(rozmiar==0){
        std::cout<<"Tablica jest pusta, nie można usunąć więcej elementów";
        return;
    }
    int* tmp=new int[this->rozmiar-1];
    std::copy(this->kopiec, this->kopiec+this->rozmiar-1, tmp);
    delete[] this->kopiec;
    kopiec=tmp;
    this->rozmiar--;
 
    int index = 0;
    while(true){
        if (lewySyn(index) > rozmiar) break;
        int a = kopiec[lewySyn(index)];
        if (prawySyn(index) > rozmiar){
            if (kopiec[index] >= kopiec[lewySyn(index)])
            break;
            int temp=kopiec[lewySyn(index)];
            kopiec[lewySyn(index)]=kopiec[index];
            kopiec[index]=temp;
            index=lewySyn(index);
        }
        else if (kopiec[lewySyn(index)] > kopiec[prawySyn(index)]){
            if (kopiec[index] >= kopiec[lewySyn(index)]) break;
            int temp=kopiec[lewySyn(index)];
            kopiec[lewySyn(index)]=kopiec[index];
            kopiec[index]=temp;
            index=lewySyn(index);
        }
        else{
            if (kopiec[index] >= kopiec[prawySyn(index)]) break;
            int temp=kopiec[prawySyn(index)];
            kopiec[prawySyn(index)]=kopiec[index];
            kopiec[index]=temp;
            index=prawySyn(index);
            index=prawySyn(index);
        }
    }
}

void Kopiec::wyszukajElement(int element){  //Funkcja wyszukania elementu o zadanej wartości z kopca
    for(int i=0; i<rozmiar; i++){
        if(*((this->kopiec)+i)==element){
            std::cout<<std::endl<<"Wyszukiwany element o wartości "<<element<<" znajduje się w kopcu"<<std::endl;
            return;
        }
    }
    std::cout<<std::endl<<"Poszukiwanego elementu o wartości "<<element<<" nie ma w kopcu"<<std::endl;
}

void Kopiec::rysujKopiec(int nrPietra, int przerwa, int obecnyIndeks, int przesuniecie){    //Funkcja rysująca strukturę kopca
    if(obecnyIndeks<rozmiar){
        if(nrPietra==0){
            std::cout<<std::setw(przerwa)<<kopiec[obecnyIndeks]<<std::setw(przerwa)<<" ";
        }
        else
        for(int i=obecnyIndeks; i<pow(2, nrPietra+1)-1; i++ ){
            if(i<rozmiar){
            std::cout<<std::setw(przerwa)<<kopiec[i]<<std::setw(przerwa)<<" ";
            }
        }
        std::cout<<std::endl<<std::endl;
        rysujKopiec(nrPietra+1, przerwa/2, obecnyIndeks+pow(2, nrPietra), przesuniecie+1);
    }
}

int Kopiec::rodzic(int index){  //Funkcja zwracająca indeks rodzica dla węzła o danym indeksie
    return (index-1)/2;
}

int Kopiec::lewySyn(int index){    //Funkcja zwracająca indeks lewego syna dla węzła o danym indeksie
    return index*2+1;
}

int Kopiec::prawySyn(int index){    //Funkcja zwracająca indeks prawego syna dla węzła o danym indeksie
    return index*2+2;
}