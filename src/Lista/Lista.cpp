#include<Lista.hpp>

Lista::Lista(int element){ //Konstruktor obiektu klasy lista
    this->glowa = new ElementListy;
    (this->glowa)->wartosc=element;
    (this->glowa)->next=nullptr;
    (this->glowa)->prev=nullptr;
    ogon=glowa;
}

void Lista::wyswietlOdPoczatku(){   //Funkcja wyświetlająca zawartość listy od początku
    ElementListy* head = this->glowa;
    while(head!=nullptr){
        std::cout<<head->wartosc<<" ";
        head=head->next;
    }
    std::cout<<std::endl;
}

void Lista::wyswietlOdKonca(){  //Funkcja wyświetlająca zawartość listy od końca
    ElementListy* tail = znajdzOgon();
    while(tail!=nullptr){
        std::cout<<tail->wartosc<<" ";
        tail=tail->prev;
    }
    std::cout<<std::endl;
}

void Lista::dodajPoczatek(int element){ //Funkcja dodania elementu na początek listy
    ElementListy *elem = new ElementListy;
    elem->wartosc=element;
    elem->next=this->glowa;
    elem->prev=nullptr;
    glowa->prev=elem;
    this->glowa=elem;
}

void Lista::dodajWybraneMiejsce(int element, int index){    //Funkcja dodania elementu na miejsce o wybranym indeksie
    ElementListy *miejsce = this->glowa;
    ElementListy *poprzedni;
    ElementListy *elem = new ElementListy;
    if(index==0){
            dodajPoczatek(element);
            return;
        }
    for(int i=0; i<index; i++){
        if(miejsce->next==nullptr){
            if(i==index-1){
                dodajKoniec(element);
                return;
            }
            std::cout<<std::endl<<"Indeks przekracza rozmiar listy"<<std::endl;
            return;
        }
        poprzedni=miejsce;
        miejsce=miejsce->next;
    }
    elem->prev=miejsce->prev;
    elem->next=miejsce;
    elem->wartosc=element;
    poprzedni->next=elem;
    std::cout<<miejsce->wartosc<<::std::endl;
    miejsce->prev=elem;
    std::cout<<miejsce->wartosc<<::std::endl;
}

void Lista::dodajKoniec(int element){   //Funkcja dodania elementu na koniec listy
    ElementListy* tail=ogon;
    ElementListy* elem=new ElementListy;
    elem->wartosc=element;
    elem->next=nullptr;
    elem->prev=tail;
    tail->next=elem;
    ogon=tail->next;
}

void Lista::usunPoczatek(){    //Funkcja usunięcia elementu z początku listy
    ElementListy *elem=this->glowa;
    if(this->glowa != nullptr){
        if(elem->next!=nullptr){
             this->glowa=(this->glowa)->next;
            (this->glowa)->prev=nullptr;
        }
        else{
            elem->wartosc=0;
            std::cout<<std::endl<<"Nie można usunąć więcej początkowych elementów"<<std::endl;
            return;
        }
    }
    delete elem;
}

void Lista::usunWybraneMiejsce(int index){  //Funkcja usunięcia elementu z miejsca o wybranym indeksie
    ElementListy *miejsce = this->glowa;
    if(index==0){
        usunPoczatek();
        return;
    }
    for(int i = 0; i < index-1; i++)
    {
        if(miejsce->next == nullptr)
        {
            std::cout<<std::endl<<"Indeks przekracza rozmiar listy"<<std::endl;
            return;
        }
        miejsce = miejsce->next;
    }
    ElementListy *tmp = miejsce->next;
    miejsce->next = tmp->next;
    miejsce->next->prev = miejsce;

    delete tmp;
}

void Lista::usunKoniec(){   //Funkcja usunięcia elementu z końca listy
    ElementListy *elem=ogon;
    if(elem != nullptr){
        if(elem->prev!=0){
            (elem->prev)->next=nullptr;
        }
        else{
            elem->wartosc=0;
            std::cout<<std::endl<<"Nie można usunąć więcej początkowych elementów"<<std::endl;
            return;
        }
    }
    ogon=elem->prev;
    delete elem;
}

void Lista::wyszukajElement(int element){   //Funkcja wyszukiwania elementu o zadanej wartości w liście
    ElementListy* head = this->glowa;
    bool flag=false;
    while(head!=nullptr){
        if(head->wartosc==element)
        {
            std::cout<<"Znaleziono poszukiwany element o wartości "<<element<<std::endl;
            flag=true;
            break;
        } 
        
        head=head->next;
    }
    if(flag==false)
        std::cout<<"Nie znaleziono poszukiwanego elementu"<<std::endl;
    
}

Lista::ElementListy* Lista::znajdzOgon(){   //Funkcja zwracająca wskaźnik na ostatni element listy
    ElementListy* head = this->glowa;
    if(head != nullptr){
        while(head->next!=nullptr)
        {
            head = head->next;
        }
    }
    return head;
}