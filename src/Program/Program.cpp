#include<Program.hpp>

void trybTekst(){ //Funkcja pomocnicza do wyświetlania informacji użytkownika dla funkcji projektUI
    std::cout<<std::endl<<"Dostępne tryby programu:"<<std::endl;
    std::cout<<"(P) - tryb pomiarowy, użytkownik wybiera typ struktury i wprowadza jedynie jej rozmiar początkowy, struktura zostaje wypełniona losowymi danymi, nie jest wyświetlana jej zawartość, wyswietlany jest czas wykonania poszczególnych operacji"<<std::endl;
    std::cout<<"(N) - tryb normalny, użytkownik wybiera typ struktury, wprowadza jej rozmiar i dane do jej wypelnienia za pomocą linii komend lub z pliku"<<std::endl<<std::endl;
    std::cout<<"Wprowadź znak trybu, który wybierasz (P/N), lub (E) - aby wyjść: ";
}

void Program::projektUI(){  //Główna funkcja obsługi dialogu z użytkownikiem
    std::cout<<"Zadanie projektowe 1"<<std::endl;
    std::cout<<"Struktury Danych i Złożoność Obliczeniowa - projekt"<<std::endl;
    std::cout<<"Autor: Jakub Wirwis 259128"<<std::endl;

    trybTekst();

    while(1){
        char tryb;
        std::cin>>tryb;
        if(tryb=='E'||tryb=='e') break;
        if(tryb=='P'||tryb=='p'){
            std::cout<<std::endl<<"==============TRYB POMIAROWY=============="<<std::endl;
            wyborStruktury('P');
            trybTekst();
            continue;
        } 
        if(tryb=='N'||tryb=='n')
        {
            std::cout<<std::endl<<"==============TRYB  NORMALNY=============="<<std::endl;
            wyborStruktury('N');
            trybTekst();
            continue;
        }
        std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Czy chcesz spróbować jeszcze raz? (E) - by wyjść, lub powtórz znak wyboru trybu by kontynuować: ";
    }
    std::cout<<"KONIEC PROGRAMU"<<std::endl;
}

void Program::wyborStruktury(char tryb){ //Funkcja wyboru struktury danych do sprawdzania
    while(1){
        std::cout<<std::endl<<"Struktury do wyboru:"<<std::endl;
        std::cout<<"(1) - tablica dynamiczna"<<std::endl<<"(2) - lista dwukierunkowa"<<std::endl<<"(3) - kopiec binarny"<<std::endl<<"(4) - BST"<<std::endl;
        std::cout<<"Wprowadź znak struktury, którą wybierasz (1/2/3/4/5), lub (E) - aby wyjść: ";
        char struktura;
        std::cin>>struktura;
        if(struktura=='E'||struktura=='e') break;
        switch(struktura){
            case '1':
            projektUITablica(tryb);
            break;
            case '2':
            projektUILista(tryb);
            break;
            case '3':
            projektUIKopiec(tryb);
            break;
            case '4':
            projektUIBst(tryb);
            break;
            /*case '5':
            projektUIDrzewoCzerwonoCzarne(tryb);
            break;*/
            default:
            std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
            break;
        }
    }
}

long long int read_QPC(){    //Funkcja do pomiaru czasu
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
} 

void wyswietlCzas(long long int &frequency, long long int &start, long long int &elapsed){    //Funkcja do wyświetlenia czasu
    std::cout << "Czas [s] = " << std::fixed << std::setprecision(3) << (float)elapsed /
    frequency << std::endl;
    std::cout << "Czas [ms] = " << std::setprecision(0) << (1000.0 * elapsed) /
    frequency << std::endl;
    std::cout << "Czas [us] = " << std::setprecision(0) << (1000000.0 * elapsed) /
    frequency << std::endl << std::endl;
}

void zawartoscTablicy(Tablica tablica){ //Funkcja pomocnicza wyświetlająca zawartość tablicy dla funkcji TNoperacjeNaTablicy
    tablica.wyswietlOdPoczatku();
    tablica.wyswietlOdKonca();
}

void TPoperacjeNaTablicy(Tablica tablica){  //Obsługa dialogu z użytkownikiem w trybie pomiarowym dla tablicy
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    while(1){
        std::cout<<std::endl<<"Operacje do wyboru:"<<std::endl;
        std::cout<<"(1) - dodaj element na początek"<<std::endl<<"(2) - dodaj element na koniec"<<std::endl<<"(3) - dodaj element w miejsce o wybranym indeksie"<<std::endl<<"(4) - wyszukaj element o wybranej wartości"<<std::endl<<"(5) - usuń pierwszy element"<<std::endl;
        std::cout<<"(6) - usuń ostatni element"<<std::endl<<"(7) - usuń element o wybranym indeksie";
        std::cout<<"Wprowadź znak operacji, którą wybierasz (1/2/3/4/5/6/7), lub (E) - aby wyjść: ";
        char operacja;
        std::cin>>operacja;
        if(operacja=='E'||operacja=='e') break;
        int wartosc, indeks;
        switch(operacja){
            case '1':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                start = read_QPC();
                tablica.dodajPoczatek(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '2':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                start = read_QPC();
                tablica.dodajKoniec(wartosc);
                elapsed = read_QPC() - start; 
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '3':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                std::cout<<std::endl<<"Indeks miejsca do dodania elementu: ";
                std::cin>>indeks;
                start = read_QPC();
                tablica.dodajWybraneMiejsce(wartosc, indeks);
                elapsed = read_QPC() - start; 
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '4':
                std::cout<<std::endl<<"Wprowadź wartość elementu do wyszukania: ";
                std::cin>>wartosc;
                start = read_QPC();
                tablica.wyszukajElement(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed); 
                break;
            case '5':
                start = read_QPC();
                tablica.usunPoczatek();
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed); 
                break;
            case '6':
                start = read_QPC();
                tablica.usunKoniec();
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed); 
                break;
            case '7':
                int indeks;
                std::cout<<std::endl<<"Indeks elementu do usunięcia: ";
                std::cin>>indeks;
                start = read_QPC();
                tablica.usunWybraneMiejsce(indeks);
                elapsed = read_QPC() - start; 
                wyswietlCzas(frequency, start, elapsed);
                break;
            default:
            std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
            break;
        }
    }
    system("PAUSE");
}

void TNoperacjeNaTablicy(Tablica tablica){  //Obsługa dialogu z użytkownikiem w trybie normalnym dla tablicy
    while(1){
            zawartoscTablicy(tablica);
            std::cout<<std::endl<<"Operacje do wyboru:"<<std::endl;
            std::cout<<"(1) - dodaj element na początek"<<std::endl<<"(2) - dodaj element na koniec"<<std::endl<<"(3) - dodaj element w miejsce o wybranym indeksie"<<std::endl<<"(4) - wyszukaj element o wybranej wartości"<<std::endl<<"(5) - usuń pierwszy element"<<std::endl;
            std::cout<<"(6) - usuń ostatni element"<<std::endl<<"(7) - usuń element o wybranym indeksie"<<std::endl;
            std::cout<<"Wprowadź znak operacji, którą wybierasz (1/2/3/4/5/6/7), lub (E) - aby wyjść: ";
            char operacja;
            std::cin>>operacja;
            if(operacja=='E'||operacja=='e') break;
            int wartosc, indeks;
            switch(operacja){
                case '1':
                    std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                    std::cin>>wartosc;
                    tablica.dodajPoczatek(wartosc);
                    break;
                case '2':
                    std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                    std::cin>>wartosc;
                    tablica.dodajKoniec(wartosc);
                    break;
                case '3':
                    std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                    std::cin>>wartosc;
                    std::cout<<std::endl<<"Indeks miejsca do dodania elementu: ";
                    std::cin>>indeks;
                    tablica.dodajWybraneMiejsce(wartosc, indeks);
                    break;
                case '4':
                    std::cout<<std::endl<<"Wprowadź wartość elementu do wyszukania: ";
                    std::cin>>wartosc;
                    tablica.wyszukajElement(wartosc);
                    break;
                case '5':
                    tablica.usunPoczatek();
                    break;
                case '6':
                    tablica.usunKoniec();
                    break;
                case '7':
                    int indeks;
                    std::cout<<std::endl<<"Indeks elementu do usunięcia: ";
                    std::cin>>indeks;
                    tablica.usunWybraneMiejsce(indeks);
                    break;
                default:
                std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
                break;
            }
        }
}

void Program::projektUITablica(char &tryb){ //Dialog z użytkownikiem dla tablicy
    std::cout<<std::endl<<"============Tablica Dynamiczna============"<<std::endl<<std::endl;
    switch(tryb){
        case 'P':
        while(1){
            std::cout<<std::endl<<"Wprowadź rozmiar struktury do pomiaru (minimalny rozmiar to 1): ";
            int rozmiar;
            std::cin>>rozmiar;
            if(rozmiar<=0){
                std::cout<<"Wprowadzono niewłaściwy rozmiar, spróbuj jeszcze raz";
                continue;
            }
            int wartosc;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1, 1000000);
            Tablica tablica=Tablica(rozmiar);
            for(int i=0 ; i < rozmiar ; i++ ){
                wartosc=dist(gen);
                tablica.wpiszWartosc(wartosc, i);
            }
            TPoperacjeNaTablicy(tablica);
            break;
        }
        break;
        case 'N':
            while(1){
                char wybor;
                Tablica tablica = Tablica(0);
                std::cout<<"Wybierz tryb wprowadzania danych: "<<std::endl;
                std::cout<<"(1) - ręczne wprowadzanie wartości i rozmiaru początkowego: "<<std::endl;
                std::cout<<"(2) - pobranie wartości z pliku"<<std::endl;
                std::cout<<"Wprowadź znak typu wprowadzania, który wybierasz (1/2), lub (E) - aby wyjść: ";
                std::cin>>wybor;
                if(wybor=='E'||wybor=='e') break;
                if(wybor=='1'){
                    int rozmiar, element;
                    std::cout<<std::endl<<"Wprowadź ilość elementów początkowych: ";
                    std::cin>>rozmiar;
                    if(rozmiar>0){
                        for(int i=0; i < rozmiar ; i++){
                            std::cout<<std::endl<<"Wprowadź element: ";
                            std::cin>>element;
                            tablica.dodajKoniec(element);
                        }
                        TNoperacjeNaTablicy(tablica);
                        break;
                    }
                }
                if(wybor=='2'){
                    file *plik=new file;  
                    if(!wczytajDaneTestowe(plik)){
                        for(int i=0; i<plik->rozmiar; i++){
                        tablica.dodajKoniec(plik->tab[i]);
                        }
                        TNoperacjeNaTablicy(tablica);
                    }
                    else std::cout<<std::endl<<"Wystąpił błąd odczytu z pliku"<<std::endl;
                    break;
                }
                std::cout<<"Wprowadzono niewłaściwe dane, spróbuj jeszcze raz";
            }
            break;
        default:
            break;
    }
}

void zawartoscListy(Lista& lista){  //Funkcja pomocnicza wyświetlająca zawartość tablicy dla funkcji TNoperacjeNaLiście
    std::cout<<std::endl<<"Zawartość listy od przodu: "<<std::endl;
    lista.wyswietlOdPoczatku();
    std::cout<<std::endl<<"Zawartość listy od tyłu: "<<std::endl;
    lista.wyswietlOdKonca();
}

void TPoperacjeNaLiscie(Lista &lista){  //Obsługa dialogu z użytkownikiem w trybie pomiarowym dla listy
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    while(1){
        std::cout<<std::endl<<"Operacje do wyboru:"<<std::endl;
        std::cout<<"(1) - dodaj element na początek"<<std::endl<<"(2) - dodaj element na koniec"<<std::endl<<"(3) - dodaj element w miejsce o wybranym indeksie"<<std::endl<<"(4) - wyszukaj element o wybranej wartości"<<std::endl<<"(5) - usuń pierwszy element"<<std::endl;
        std::cout<<"(6) - usuń ostatni element"<<std::endl<<"(7) - usuń element o wybranym indeksie";
        std::cout<<"Wprowadź znak operacji, którą wybierasz (1/2/3/4/5/6/7), lub (E) - aby wyjść: ";
        char operacja;
        std::cin>>operacja;
        if(operacja=='E'||operacja=='e') break;
        int wartosc, indeks;
        switch(operacja){
            case '1':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                start = read_QPC();
                lista.dodajPoczatek(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '2':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                start = read_QPC();
                lista.dodajKoniec(wartosc);
                elapsed = read_QPC() - start; 
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '3':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                std::cout<<std::endl<<"Indeks miejsca do dodania elementu: ";
                std::cin>>indeks;
                start = read_QPC();
                lista.dodajWybraneMiejsce(wartosc, indeks);
                elapsed = read_QPC() - start; 
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '4':
                std::cout<<std::endl<<"Wprowadź wartość elementu do wyszukania: ";
                std::cin>>wartosc;
                start = read_QPC();
                lista.wyszukajElement(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed); 
                break;
            case '5':
                start = read_QPC();
                lista.usunPoczatek();
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed); 
                break;
            case '6':
                start = read_QPC();
                lista.usunKoniec();
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed); 
                break;
            case '7':
                int indeks;
                std::cout<<std::endl<<"Indeks elementu do usunięcia: ";
                std::cin>>indeks;
                start = read_QPC();
                lista.usunWybraneMiejsce(indeks);
                elapsed = read_QPC() - start; 
                wyswietlCzas(frequency, start, elapsed);
                break;
            default:
            std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
            break;
        }
    }
    system("PAUSE");
}

void TNoperacjeNaLiscie(Lista &lista){  //Obsługa dialogu z użytkownikiem w trybie normalnym dla listy
    while(1){
        zawartoscListy(lista);
        std::cout<<std::endl<<"Operacje do wyboru:"<<std::endl;
        std::cout<<"(1) - dodaj element na początek"<<std::endl<<"(2) - dodaj element na koniec"<<std::endl<<"(3) - dodaj element w miejsce o wybranym indeksie"<<std::endl<<"(4) - wyszukaj element o wybranej wartości"<<std::endl<<"(5) - usuń pierwszy element"<<std::endl;
        std::cout<<"(6) - usuń ostatni element"<<std::endl<<"(7) - usuń element o wybranym indeksie"<<std::endl;
        std::cout<<"Wprowadź znak operacji, którą wybierasz (1/2/3/4/5/6/7), lub (E) - aby wyjść: ";
        char operacja;
        std::cin>>operacja;
        if(operacja=='E'||operacja=='e') break;
        int wartosc, indeks;
        switch(operacja){
            case '1':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                lista.dodajPoczatek(wartosc);
                break;
            case '2':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                lista.dodajKoniec(wartosc);
                break;
            case '3':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                std::cout<<std::endl<<"Indeks miejsca do dodania elementu: ";
                std::cin>>indeks;
                lista.dodajWybraneMiejsce(wartosc, indeks);
                break;
            case '4':
                std::cout<<std::endl<<"Wprowadź wartość elementu do wyszukania: ";
                std::cin>>wartosc;
                lista.wyszukajElement(wartosc);
                break;
            case '5':
                lista.usunPoczatek();
                break;
            case '6':
                lista.usunKoniec();
                break;
            case '7':
                int indeks;
                std::cout<<std::endl<<"Wprowadź indeks elementu do usunięcia: ";
                std::cin>>indeks;
                lista.usunWybraneMiejsce(indeks);
                break;
            default:
            std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
            break;
        }
    }
}

void Program::projektUILista(char& tryb){   //Dialog z użytkownikiem dla listy
    std::cout<<std::endl<<"===========Lista  Dwukierunkowa==========="<<std::endl<<std::endl;
    switch(tryb){
        case 'P':
        while(1){
            std::cout<<std::endl<<"Wprowadź rozmiar struktury do pomiaru (minimalny rozmiar to 1): ";
            int rozmiar;
            std::cin>>rozmiar;
            if(rozmiar<=0){
                std::cout<<"Wprowadzono niewłaściwy rozmiar, spróbuj jeszcze raz";
                continue;
            }
            int wartosc;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1, 1000000);
            wartosc=dist(gen);
            Lista lista=Lista(wartosc);
            for(int i=0 ; i < rozmiar-1 ; i++ ){
                wartosc=dist(gen);
                lista.dodajKoniec(wartosc);
            }
            TPoperacjeNaLiscie(lista);
            break;
        }
        break;
        case 'N':
            while(1){
                char wybor;
                std::cout<<"Wybierz tryb wprowadzania danych: "<<std::endl;
                std::cout<<"(1) - ręczne wprowadzanie wartości i rozmiaru początkowego: "<<std::endl;
                std::cout<<"(2) - pobranie wartości z pliku"<<std::endl;
                std::cout<<"Wprowadź znak typu wprowadzania, który wybierasz (1/2), lub (E) - aby wyjść: ";
                std::cin>>wybor;
                if(wybor=='E'||wybor=='e') break;
                if(wybor=='1'){
                    int rozmiar, element;
                    std::cout<<std::endl<<"Wprowadź ilość elementów początkowych: ";
                    std::cin>>rozmiar;
                    if(rozmiar>0){
                        std::cout<<std::endl<<"Wprowadź element: ";
                        std::cin>>element;
                        Lista lista=Lista(element);
                        for(int i=0; i < rozmiar - 1 ; i++){
                            std::cout<<std::endl<<"Wprowadź element: ";
                            std::cin>>element;
                            lista.dodajKoniec(element);
                        }
                        TNoperacjeNaLiscie(lista);
                        break;
                    }
                }
                if(wybor=='2'){ 
                    file *plik=new file;  
                    if(!wczytajDaneTestowe(plik)){
                        Lista lista=Lista(plik->tab[0]);
                        for(int i=1; i<plik->rozmiar; i++){
                            lista.dodajKoniec(plik->tab[i]);
                        }
                        TNoperacjeNaLiscie(lista);
                    }
                    else std::cout<<std::endl<<"Wystąpił błąd odczytu z pliku"<<std::endl;
                    break;

                }
                std::cout<<"Wprowadzono niewłaściwe dane, spróbuj jeszcze raz";
            }
            break;
        default:
            break;
    }
    
}

void TPoperacjeNaKopcu(Kopiec &kopiec){ //Obsługa dialogu z użytkownikiem w trybie pomiarowym dla kopca
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    while(1){
        std::cout<<std::endl<<"Operacje do wyboru:"<<std::endl;
        std::cout<<"(1) - dodaj element"<<std::endl<<"(2) - wyszukaj element o wybranej wartości"<<std::endl<<"(3) - usuń korzeń"<<std::endl;
        std::cout<<"Wprowadź znak operacji, którą wybierasz (1/2/3), lub (E) - aby wyjść: ";
        char operacja;
        std::cin>>operacja;
        if(operacja=='E'||operacja=='e') break;
        int wartosc, indeks;
        switch(operacja){
            case '1':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                start = read_QPC();
                kopiec.dodajElement(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '2':
                std::cout<<std::endl<<"Wprowadź wartość elementu do wyszukania: ";
                std::cin>>wartosc;
                start = read_QPC();
                kopiec.wyszukajElement(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '3':
                start = read_QPC();
                kopiec.usunKorzen();
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed);
                break;
            default:
            std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
            break;
        }
    }
    system("PAUSE");
}

void TNoperacjeNaKopcu(Kopiec &kopiec){ //Obsługa dialogu z użytkownikiem w trybie normalnym dla kopca
     while(1){
        std::cout<<std::endl<<"Zawartość kopca: "<<std::endl;
        kopiec.wyswietlKopiec();
        std::cout<<std::endl<<"Operacje do wyboru:"<<std::endl;
        std::cout<<"(1) - dodaj element"<<std::endl<<"(2) - wyszukaj element o wybranej wartości"<<std::endl<<"(3) - usuń korzeń "<<std::endl;
        std::cout<<"Wprowadź znak operacji, którą wybierasz (1/2/3), lub (E) - aby wyjść: ";
        char operacja;
        std::cin>>operacja;
        if(operacja=='E'||operacja=='e') break;
        int wartosc, indeks;
        switch(operacja){
            case '1':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                kopiec.dodajElement(wartosc);
                break;
            case '2':
                std::cout<<std::endl<<"Wprowadź wartość elementu do wyszukania: ";
                std::cin>>wartosc;
                kopiec.wyszukajElement(wartosc);
                break;
            case '3':
                kopiec.usunKorzen();
                break;
            default:
            std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
            break;
        }
    }
}

void Program::projektUIKopiec(char& tryb){  //Dialog z użytkownikiem dla kopca
    std::cout<<std::endl<<"==============Kopiec Binarny=============="<<std::endl<<std::endl;  
    switch(tryb){
        case 'P':
        while(1){
            std::cout<<std::endl<<"Wprowadź rozmiar struktury do pomiaru (minimalny rozmiar to 1): ";
            int rozmiar;
            std::cin>>rozmiar;
            if(rozmiar<=0){
                std::cout<<"Wprowadzono niewłaściwy rozmiar, spróbuj jeszcze raz";
                continue;
            }
            int wartosc;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1, 1000000);
            wartosc=dist(gen);
            Kopiec kopiec=Kopiec(wartosc);
            for(int i=0 ; i < rozmiar-1 ; i++ ){
                wartosc=dist(gen);
                kopiec.dodajElement(wartosc);
            }
            TPoperacjeNaKopcu(kopiec);
            break;
        }
        break;
        case 'N':
            while(1){
                char wybor;
                std::cout<<"Wybierz tryb wprowadzania danych: "<<std::endl;
                std::cout<<"(1) - ręczne wprowadzanie wartości i rozmiaru początkowego: "<<std::endl;
                std::cout<<"(2) - pobranie wartości z pliku"<<std::endl;
                std::cout<<"Wprowadź znak typu wprowadzania, który wybierasz (1/2), lub (E) - aby wyjść: ";
                std::cin>>wybor;
                if(wybor=='E'||wybor=='e') break;
                if(wybor=='1'){
                    int rozmiar, element;
                    std::cout<<std::endl<<"Wprowadź ilość elementów początkowych: ";
                    std::cin>>rozmiar;
                    if(rozmiar>0){
                        std::cout<<std::endl<<"Wprowadź element: ";
                        std::cin>>element;
                        Kopiec kopiec=Kopiec(element);
                        for(int i=0; i < rozmiar - 1 ; i++){
                            std::cout<<std::endl<<"Wprowadź element: ";
                            std::cin>>element;
                            kopiec.dodajElement(element);
                        }
                        TNoperacjeNaKopcu(kopiec);
                        break;
                    }
                }
                if(wybor=='2'){ 
                    file *plik=new file;  
                    if(!wczytajDaneTestowe(plik)){
                        Kopiec kopiec=Kopiec(plik->tab[0]);
                        for(int i=1; i<plik->rozmiar; i++){
                            kopiec.dodajElement(plik->tab[i]);
                        }
                        TNoperacjeNaKopcu(kopiec);
                    }
                    else std::cout<<std::endl<<"Wystąpił błąd odczytu z pliku"<<std::endl;
                    break;
                }
                std::cout<<"Wprowadzono niewłaściwe dane, spróbuj jeszcze raz";
            }
            break;
        default:
            break;
    }
}

void TPoperacjeNaBst(Bst &bst){ //Obsługa dialogu z użytkownikiem w trybie pomiarowym dla drzewa BST
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    while(1){
        std::cout<<std::endl<<"Operacje do wyboru:"<<std::endl;
        std::cout<<"(1) - dodaj element"<<std::endl<<"(2) - wyszukaj element o wybranej wartości"<<std::endl<<"(3) - usuń element o zadanej wartości"<<std::endl;
        std::cout<<"Wprowadź znak operacji, którą wybierasz (1/2/3), lub (E) - aby wyjść: ";
        char operacja;
        std::cin>>operacja;
        if(operacja=='E'||operacja=='e') break;
        int wartosc;
        switch(operacja){
            case '1':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                start = read_QPC();
                bst.dodajElement(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '2':
                std::cout<<std::endl<<"Wprowadź wartość elementu do wyszukania: ";
                std::cin>>wartosc;
                start = read_QPC();
                bst.wyszukajElement(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed);
                break;
            case '3':
                std::cout<<std::endl<<"Wprowadź wartość elementu do usunięcia: ";
                std::cin>>wartosc;
                start = read_QPC();
                bst.usunElement(wartosc);
                elapsed = read_QPC() - start;
                wyswietlCzas(frequency, start, elapsed);
                break;
            default:
            std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
            break;
        }
    }
    system("PAUSE");
}

void TNoperacjeNaBst(Bst &bst){ //Obsługa dialogu z użytkownikiem w trybie normalnym dla drzewa BST
    while(1){
        std::cout<<std::endl<<"Zawartość kopca: "<<std::endl;
        bst.wyswietlBst();
        std::cout<<std::endl<<"Operacje do wyboru:"<<std::endl;
        std::cout<<"(1) - dodaj element"<<std::endl<<"(2) - wyszukaj element o wybranej wartości"<<std::endl<<"(3) - usuń element o zadanej wartości "<<std::endl;
        std::cout<<"Wprowadź znak operacji, którą wybierasz (1/2/3), lub (E) - aby wyjść: ";
        char operacja;
        std::cin>>operacja;
        if(operacja=='E'||operacja=='e') break;
        int wartosc;
        switch(operacja){
            case '1':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                bst.dodajElement(wartosc);
                break;
            case '2':
                std::cout<<std::endl<<"Wprowadź wartość elementu do wyszukania: ";
                std::cin>>wartosc;
                bst.wyszukajElement(wartosc);
                break;
            case '3':
                std::cout<<std::endl<<"Wprowadź wartość elementu: ";
                std::cin>>wartosc;
                bst.usunElement(wartosc);
                break;
            default:
            std::cout<<"Nie można zidentyfikować wprowadzonego wyboru. Spróbuj jeszcze raz."<<std::endl;
            break;
        }
    }
}

void Program::projektUIBst(char& tryb){ //Dialog z użytkownikiem dla drzewa BST
    std::cout<<std::endl<<"=======Drzewo poszukiwań binarnych======="<<std::endl<<std::endl;
    switch(tryb){
        case 'P':
        while(1){
            std::cout<<std::endl<<"Wprowadź rozmiar struktury do pomiaru (minimalny rozmiar to 1): ";
            int rozmiar;
            std::cin>>rozmiar;
            if(rozmiar<=0){
                std::cout<<"Wprowadzono niewłaściwy rozmiar, spróbuj jeszcze raz";
                continue;
            }
            int wartosc;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(1, 1000000);
            wartosc=dist(gen);
            Bst drzewo=Bst(wartosc);
            for(int i=0 ; i < rozmiar-1 ; i++ ){
                wartosc=dist(gen);
                drzewo.dodajElement(wartosc);
            }
            TPoperacjeNaBst(drzewo);
            break;
        }
        break;
        case 'N':
            while(1){
                char wybor;
                std::cout<<"Wybierz tryb wprowadzania danych: "<<std::endl;
                std::cout<<"(1) - ręczne wprowadzanie wartości i rozmiaru początkowego: "<<std::endl;
                std::cout<<"(2) - pobranie wartości z pliku"<<std::endl;
                std::cout<<"Wprowadź znak typu wprowadzania, który wybierasz (1/2), lub (E) - aby wyjść: ";
                std::cin>>wybor;
                if(wybor=='E'||wybor=='e') break;
                if(wybor=='1'){
                    int rozmiar, element;
                    std::cout<<std::endl<<"Wprowadź ilość elementów początkowych: ";
                    std::cin>>rozmiar;
                    if(rozmiar>0){
                        std::cout<<std::endl<<"Wprowadź element: ";
                        std::cin>>element;
                        Bst drzewo=Bst(element);
                        for(int i=0; i < rozmiar - 1 ; i++){
                            std::cout<<std::endl<<"Wprowadź element: ";
                            std::cin>>element;
                            drzewo.dodajElement(element);
                        }
                        TNoperacjeNaBst(drzewo);
                        break;
                    }
                }
                if(wybor=='2'){ 
                    file *plik=new file;  
                    if(!wczytajDaneTestowe(plik)){
                        Bst drzewo=Bst(plik->tab[0]);
                        for(int i=1; i<plik->rozmiar; i++){
                            drzewo.dodajElement(plik->tab[i]);
                        }
                        TNoperacjeNaBst(drzewo);
                    }
                    else std::cout<<std::endl<<"Wystąpił błąd odczytu z pliku"<<std::endl;
                    break;
                }
                std::cout<<"Wprowadzono niewłaściwe dane, spróbuj jeszcze raz";
            }
            break;
        default:
            break;
    }

}

void Program::projektUIDrzewoCzerwonoCzarne(char& tryb){ //Funkcja nieużywana - brak impementacji drzewa czerwono czarnego
    std::cout<<std::endl<<"==========Drzewo czerwono-czarne=========="<<std::endl<<std::endl;
}

bool Program::wczytajDaneTestowe(file *plik){ //Funkcja obsługi pliku tekstowego z danymi wejściowymi
    std::ifstream fIn;
    std::cout<<std::endl<<"Przed wprowadzeniem nazwy pliku, upewnij się że znajduje się on w folderze głównym projektu"<<std::endl;
    std::cout<<std::endl<<"Wprowadź nazwę pliku: ";
    std::string plikNazwa;
    std::cin>>plikNazwa;
    fIn.open("..\\"+plikNazwa);
    if(fIn.is_open()){
        int val, size;
        fIn >> size;
        int elementy[size];
        if(fIn.fail()){
            std::cout << "File error - READ SIZE" << std::endl;
            return true;
        }
        else{
            for(int i = 0; i < size; i++){
                fIn >> val;
                if(fIn.fail())
                {
                std::cout << "File error - READ DATA" << std::endl;
                return true;
                }
                else{
                    elementy[i] = val;
                    plik->tab[i]=val;
                } 
            }
        }
        fIn.close();
        plik->rozmiar=size;
        }
        else{
            std::cout << "File error - OPEN" << std::endl;
            return true;
        }
        return false;
}