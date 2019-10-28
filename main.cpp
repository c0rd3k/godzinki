#include <iostream>
#include <windows.h>
#include <fstream>
//#include <cstdlib>
//#include <string>
using namespace std;

fstream plik_godziny;

void zamknij_plik()
{
    plik_godziny.close();
}
void otworz_plik()
{
    plik_godziny.open("godziny.txt", ios::out | ios::app);
}
int policz_linie()
{
    int ile_linii=0;
    string line;
    otworz_plik();
    zamknij_plik();
    plik_godziny.open("godziny.txt", ios::in);
    if(plik_godziny.good()==false)
    {
        cout<<"Blad wczytwywania pliku, plik nie istnieje!";
        exit(0);
    }
    while(!plik_godziny.eof())
    {
        getline(plik_godziny,line);
        ile_linii++;
    }
    zamknij_plik();

    return ile_linii;
}
void czy_za_dlugie(int dlug, int miesiac, int rok)
{
    if  (((miesiac == 1 ||miesiac == 3 ||miesiac == 5 ||miesiac == 7 ||miesiac == 8 ||miesiac == 10 ||miesiac == 12) && dlug>31)
        || ((miesiac == 4 ||miesiac == 6 ||miesiac == 9 ||miesiac == 11) && dlug>30)
        || ((miesiac == 2 && rok==1) && dlug>29)
        || ((miesiac == 2 && rok==0) && dlug>28))
    {
        cout<<"Wpisano juz wszystkie dni miesiaca!"
            <<"\nPrzenies plik godziny.txt do innego folderu, aby wypisac kolejny miesiac."
            <<"\nProgram ulega zamknieciu."<<endl;
        system("PAUSE");
        exit(0);
    }
}

int main()
{
    int miesiac=0, ile_dni, rok=0, i, dlugosc_pliku;
    float start_h, stop_h;

    cout<<"Wpisz nr miesiaca: "<<endl;
    while (miesiac<1 || miesiac>12 && miesiac!=99)
    {
        cin>>miesiac;

        if (miesiac == 1 ||miesiac == 3 ||miesiac == 5 ||miesiac == 7 ||miesiac == 8 ||miesiac == 10 ||miesiac == 12)
            ile_dni=31;
        else if (miesiac == 4 ||miesiac == 6 ||miesiac == 9 ||miesiac == 11)
            ile_dni=30;
        else if (miesiac == 2)
        {
            cout<<"Podaj rok: ";
            cin>>rok;
            if((rok%4==0 && rok%100!=0) || rok%400==0)
            {
                ile_dni=29;
                rok=1;
            }
            else
            {
                ile_dni=28;
                rok=0;
            }
        }
        else if (miesiac==99)                   /// <<<--------KONTROLA--------<<<
            ile_dni=5;
        else
            cout<<"Nie ma takiego miesiaca! Wpisz ponownie:"<<endl;
    }

    dlugosc_pliku=policz_linie();

    cout<< "LINIE: "<<dlugosc_pliku<<endl;

    czy_za_dlugie(dlugosc_pliku, miesiac, rok);

    cout<<"Wpisuj: [czas rozpoczecia] [spacja] [czas zakonczenia]"<<endl;
    cout<<"Wpisuj: 0 0 jesli wolne || 951 aby zakonczyc program."<<endl;
    otworz_plik();
    i=dlugosc_pliku;
    while (i<=ile_dni)
    {
        if (i<10)
        {
            if (miesiac<10)
            {
                cout<<endl<<"0"<<i<<".0"<<miesiac<<") ";
                plik_godziny<<"0"<<i<<".0"<<miesiac<<") ";
            }
            else
            {
                cout<<endl<<"0"<<i<<"."<<miesiac<<") ";
                plik_godziny<<"0"<<i<<"."<<miesiac<<") ";
            }
        }
        else
        {
            if (miesiac<10)
            {
                cout<<endl<<i<<".0"<<miesiac<<") ";
                plik_godziny<<i<<".0"<<miesiac<<") ";
            }
            else
            {
                cout<<endl<<i<<"."<<miesiac<<") ";
                plik_godziny<<i<<"."<<miesiac<<") ";
            }
        }
        cin>>start_h>>stop_h;               /// SKOMBINUJ ABY PRZY 951 NIE ZAPISYWALO PUSTEGO DNIA

        if (start_h==951 || stop_h==951)
        {
            zamknij_plik();
            exit(0);
        }
        else if (start_h==0 && stop_h==0)
        {
            plik_godziny<<" "<<endl;
        }
        else
        {
            if (start_h<10)
                plik_godziny<<"0"<<start_h<<" - "<<stop_h<<endl;
            else
                plik_godziny<<start_h<<" - "<<stop_h<<endl;
        }
        i++;
    }
    zamknij_plik();



    system("PAUSE");
    return 0;
}
