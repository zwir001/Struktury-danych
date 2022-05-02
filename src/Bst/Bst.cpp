#include<Bst.hpp>

Bst::Bst(int element){  //Konstruktor obiektu klasy Bst
    korzen=new wezel;
    korzen->wartosc=element;
    korzen->lewy=nullptr;
    korzen->prawy=nullptr;
    korzen->rodzic=nullptr;
}

void Bst::wyswietlBst(){  //Funkcja do wyświetlania zawartości drzewa BST
    printBT(korzen);
}

void Bst::dodajElement(int element){    //Funkcja dodania elementu o zadanej wartości do drzewa Bst
    dodaj(element, korzen);
}

void Bst::usunElement(int element){     //Funkcja do usuwania elementu o zadanej wartości z drzewa Bst
    if(korzen==nullptr){
        std::cout<<std::endl<<"Nie można usunąć elementu, drzewo jest puste"<<std::endl;
    }
    wezel *i=szukaj(korzen, element);
    if(i!=nullptr) usun(szukaj(korzen, element));
    else std::cout<<"Nie ma takiego elementu";
}

void Bst::wyszukajElement(int element){ //Funkcja odpowiadająca czy element o zadanym indeksie znajduje się w drzewie Bst
    if(szukaj(korzen, element)!=nullptr){
        std::cout<<"Znaleziono poszukiwany element o wartości "<<element<<std::endl;
    }
    else std::cout<<std::endl<<"Nie znaleziono poszukiwanego elementu"<<std::endl;
}

void Bst::rotacjaWLewo(int element){    //Rotacja w lewo dla węzła o zadanej wartości
    rot_L(szukaj(korzen, element));
}

void Bst::rotacjaWPrawo(int element){   //Rotacja w prawo dla węzła o zadanej wartości
    rot_P(szukaj(korzen, element));
}

void Bst::rownowazenieDrzewa(){     //Funkcja równoważenia drzewa Bst według algorytmu DSW

}

Bst::wezel* Bst::szukaj(wezel* start, int wartosc){ //Funkcja zwracająca wskaźnik na węzeł o zadanej zawartości
    if (start->wartosc == wartosc) return start;
    else if (wartosc < start->wartosc && start->lewy != nullptr) return szukaj(start->lewy, wartosc);     
    else if (wartosc > start->wartosc && start->prawy != nullptr) return szukaj(start->prawy, wartosc);
    return nullptr;
}

void Bst::dodaj(int element, wezel* start){ //Funkcja wstawienia elementu o zadanej wartości do drzewa Bst
    if (korzen == nullptr){
        korzen = new wezel;
        korzen->wartosc = element;
        korzen->lewy = nullptr;
        korzen->prawy = nullptr;
        korzen->rodzic = nullptr;
    }
    else if(element < start->wartosc){ 
            if(start->lewy != nullptr){
            dodaj(element,start->lewy);
        }
        else{
            wezel *nowy = new wezel;
            nowy->wartosc = element;
            nowy->lewy = nullptr;
            nowy->prawy = nullptr;
            nowy->rodzic = start;
            start->lewy=nowy;
        }
    } 
    else{     
        if(start->prawy!=nullptr){
            dodaj(element, start->prawy);
        } 
        else{
            wezel *nowy = new wezel;
            nowy->wartosc = element;
            nowy->lewy = nullptr;
            nowy->prawy = nullptr;
            nowy->rodzic = start;
            start->prawy=nowy;
        }
    }
}

void Bst::usun(wezel* start){   //Funkcja usuwająca element o zadanej wartości z drzewa Bst
    if(start->lewy==nullptr && start->prawy==nullptr){
        if(start->rodzic==nullptr){
            korzen=nullptr;
        }
        else if(start->rodzic->lewy==start){
            start->rodzic->lewy=nullptr;
        }
        else{    
        start->rodzic->prawy=nullptr;
        }
        delete start;
    }
    else if(start->lewy==nullptr || start->prawy==nullptr){
        if(start->lewy==nullptr){
            if(start->rodzic==nullptr){
                korzen=start->prawy;
            }
            else if(start->rodzic->lewy==start){
                start->rodzic->lewy=start->prawy;
            }
            else{
                start->rodzic->prawy=start->prawy;
            }
        }
        else{
            if(start->rodzic==nullptr){
                korzen=start->lewy;
            }
            else if(start->rodzic->lewy==start){
                start->rodzic->lewy=start->lewy;
            }
            else{
                start->rodzic->prawy=start->lewy;
            }
        }
        delete start;
    }
    else
    {
        struct wezel *temp;
        temp=najLewy(start->prawy);
        start->wartosc = temp->wartosc;
        usun(temp);
    }
}

Bst::wezel* Bst::najLewy(wezel* start){ //Funkcja zwracająca wskaźnik na element znajdujący się najbardziej w lewo w zadanym poddrzewie
    if(start->lewy != nullptr)
        return najLewy(start->lewy);
    else
        return start;
}

void Bst::printBT(const std::string& prefix, Bst::wezel* wezel, bool isLeft)    //Funkcja rysująca strukturę drzewa Bst (1)
{
    if( wezel != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << wezel->wartosc << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), wezel->lewy, true);
        printBT( prefix + (isLeft ? "│   " : "    "), wezel->prawy, false);
    }
}

void Bst::printBT(wezel* wezel){ //Funkcja rysująca strukturę drzewa Bst (2)
    printBT("", wezel, false);    
}

void Bst::rot_L(wezel* A){  //Funkcja rotacji w lewo dla zadanego węzła

    Bst::wezel *B = A->prawy, *rodzic = A->rodzic;

    if(B){
        A->prawy = B->lewy;
        if( A->prawy ) A->prawy->rodzic = A;

        B->lewy = A;
        B->prawy = rodzic;
        A->prawy = B;

        if(rodzic){
            if( rodzic->lewy == A ) rodzic->lewy = B; 
            else rodzic->prawy = B;
        }
        else korzen = B;
    }
}

void Bst::rot_P(wezel* A){  //Funkcja rotacji w prawo dla zadanego węzła
    Bst::wezel *B = A->lewy, *rodzic = A->prawy;

    if( B ){
        A->lewy = B->prawy;
        if( A->lewy ) A->lewy->rodzic = A;

        B->prawy = A;
        B->rodzic = rodzic;
        A->rodzic = B;

        if(rodzic){
            if( rodzic->lewy == A ) rodzic->lewy = B; 
            else rodzic->prawy = B;
        }
        else korzen = B;
    }
}