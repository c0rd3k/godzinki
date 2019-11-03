#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdio>
//#include <string>
using namespace std;

fstream plik_godziny;

void zamknij_plik()
{
    plik_godziny.close();
}
void otworz_plik(int msc)
{
    if (msc==1)
        plik_godziny.open("1.txt", ios::out | ios::app);
    else if (msc==2)
        plik_godziny.open("2.txt", ios::out | ios::app);
    else if (msc==3)
        plik_godziny.open("3.txt", ios::out | ios::app);
    else if (msc==4)
        plik_godziny.open("4.txt", ios::out | ios::app);
    else if (msc==5)
        plik_godziny.open("5.txt", ios::out | ios::app);
    else if (msc==6)
        plik_godziny.open("6.txt", ios::out | ios::app);
    else if (msc==7)
        plik_godziny.open("7.txt", ios::out | ios::app);
    else if (msc==8)
        plik_godziny.open("8.txt", ios::out | ios::app);
    else if (msc==9)
        plik_godziny.open("9.txt", ios::out | ios::app);
    else if (msc==10)
        plik_godziny.open("10.txt", ios::out | ios::app);
    else if (msc==11)
        plik_godziny.open("11.txt", ios::out | ios::app);
    else if (msc==12)
        plik_godziny.open("12.txt", ios::out | ios::app);
    else
    {
        cout<<"BLAD - Wprowadzono zly nr miesiaca ( void otworz_plik() )"<<endl;
        Sleep(3000);
        exit(0);
    }
}
void otworz_plik_in(int msc)
{
    if (msc==1)
        plik_godziny.open("1.txt", ios::in);
    else if (msc==2)
        plik_godziny.open("2.txt", ios::in);
    else if (msc==3)
        plik_godziny.open("3.txt", ios::in);
    else if (msc==4)
        plik_godziny.open("4.txt", ios::in);
    else if (msc==5)
        plik_godziny.open("5.txt", ios::in);
    else if (msc==6)
        plik_godziny.open("6.txt", ios::in);
    else if (msc==7)
        plik_godziny.open("7.txt", ios::in);
    else if (msc==8)
        plik_godziny.open("8.txt", ios::in);
    else if (msc==9)
        plik_godziny.open("9.txt", ios::in);
    else if (msc==10)
        plik_godziny.open("10.txt", ios::in);
    else if (msc==11)
        plik_godziny.open("11.txt", ios::in);
    else if (msc==12)
        plik_godziny.open("12.txt", ios::in);
    else
    {
        cout<<"BLAD - Wprowadzono zly nr miesiaca ( void otworz_plik_in() )"<<endl;
        Sleep(3000);
        exit(0);
    }
}
int policz_linie(int msc)
{
    int ile_linii=0;
    string line;
    otworz_plik(msc);
    zamknij_plik();
    otworz_plik_in(msc);
    if(plik_godziny.good()==false)
    {
        cout<<"Blad wczytwywania pliku! ( policz_linie() )";
        Sleep (3000);
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
        cout<<"Wpisano juz wszystkie dni miesiaca!"<<endl;

    }
    else
    {
        cout<<"W tym miesiacu jest kilka dni do wpisania."<<endl;
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

    dlugosc_pliku=policz_linie(miesiac);

//    cout<< "LINIE: "<<dlugosc_pliku<<endl;

    czy_za_dlugie(dlugosc_pliku, miesiac, rok);

    cout<<"Wpisuj: [czas rozpoczecia] [spacja] [czas zakonczenia]"<<endl;
    cout<<"Wpisuj: 0 0 jesli wolne || 951 aby zakonczyc program."<<endl;
    otworz_plik(miesiac);
    i=dlugosc_pliku;
    while (i<=ile_dni)
    {
        if (i<10)
        {
            if (miesiac<10)
            {
                cout<<endl<<"0"<<i<<".0"<<miesiac<<") ";
                cin>>start_h>>stop_h;
                if (start_h==951 || stop_h==951)
                {
                    zamknij_plik();
                    exit(0);
                }
                plik_godziny<<"0"<<i<<".0"<<miesiac<<") ";
            }
            else
            {
                cout<<endl<<"0"<<i<<"."<<miesiac<<") ";
                cin>>start_h>>stop_h;
                if (start_h==951 || stop_h==951)
                {
                    zamknij_plik();
                    exit(0);
                }
                plik_godziny<<"0"<<i<<"."<<miesiac<<") ";
            }
        }
        else
        {
            if (miesiac<10)
            {
                cout<<endl<<i<<".0"<<miesiac<<") ";
                cin>>start_h>>stop_h;
                if (start_h==951 || stop_h==951)
                {
                    zamknij_plik();
                    exit(0);
                }
                plik_godziny<<i<<".0"<<miesiac<<") ";
            }
            else
            {
                cout<<endl<<i<<"."<<miesiac<<") ";
                cin>>start_h>>stop_h;
                if (start_h==951 || stop_h==951)
                {
                    zamknij_plik();
                    exit(0);
                }
                plik_godziny<<i<<"."<<miesiac<<") ";
            }
        }

        if (start_h==0 && stop_h==0)
        {
            plik_godziny<<" "<<endl;
        }
        else
        {
            if (start_h==24)
                start_h=0;
            else if (stop_h==0)
                stop_h==24;

            if (start_h<10)
            {
                if (stop_h<10)
                    plik_godziny<<"0"<<start_h<<" - "<<"0"<<stop_h<<endl;
                else
                    plik_godziny<<"0"<<start_h<<" - "<<stop_h<<endl;
            }
            else
            {
                if (stop_h<10)
                    plik_godziny<<start_h<<" - "<<"0"<<stop_h<<endl;
                else
                    plik_godziny<<start_h<<" - "<<stop_h<<endl;
            }
        }
        i++;
    }
    zamknij_plik();

    system("PAUSE");
    return 0;
}

/*
string intToStr(int n)
{
    string tmp, ret;
    if(n < 0)
    {
        ret = "-";
        n = -n;
    }
    do
    {
        tmp += n % 10 + 48;
        n -= n % 10;
    }
    while(n /= 10);
    for(int i = tmp.size()-1; i >= 0; i--)
        ret += tmp[i];
    return ret;
}

*/
