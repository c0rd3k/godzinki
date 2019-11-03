#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

fstream plik_godziny;

void zamknij_plik()
{
    plik_godziny.close();
}
void otworz_plik(int msc)
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
        cout<<"NIE MA TAKIEGO MIESIACA!"<<endl;
        Sleep(3000);
        exit(0);
    }

    if (plik_godziny.good()==false)
    {
        cout<<"Blad wczytwywania pliku! Program ulega zamknieciu.\nPrawdopodobnie jeszcze nie wypisales/as tego miesiaca...";
        Sleep(5000);
        exit(0);
    }
}
int main()
{
    float start_h, stop_h, czas_h, suma_h=0;
    int ile_dni=0, msc=0;
    string linia, bufor, day;

    while (msc<1 || msc>12)
    {
        cout << "Podaj nr miesiaca: " << endl;
        cin >> msc;

        if (msc<1 || msc>12)
            cout << "Nie ma takiego miesiaca! Jeszcze raz - ";
    }
    otworz_plik(msc);
///------------------------------------------------------------------------------------------- while sa dane w pliku
    while(!plik_godziny.eof())
    {
        getline(plik_godziny, linia);
        /*   if (linia[0]<48 && linia[0]>57)
           {
               for (int i=0; i<linia.length(); i++)
               {
                   linia[i]=linia[i+1];
               }
           }
        */
        day = linia.substr(0,5);
        if(linia.length()>10)       // dzien wolny 8 znakow - 2 znaki na "zapas"
        {
///--------------------------------------------------------------------------------------- oblicza czas pracy
            ile_dni++;
            for (int i=0; i<linia.length(); i++)
            {
                if (linia[i]==32)   //  <- spacja
                {
                    if (linia[i-1]==41) // ) <- nawias
                    {
                        bufor = linia.substr (i+1,2);
                        start_h = atof(bufor.c_str());
                        //        cout<<"start_h ) = "<<start_h<<endl;          /// --- kontrola ---
                    }
                    else if (linia[i-1]==45)    // - <- minus, myslnik
                    {
                        bufor = linia.substr (i+1,2);
                        stop_h = atof(bufor.c_str());
                        //        cout<<"stop_h - = "<<stop_h<<endl;           /// --- kontrola ---
                    }
                }
            }
            czas_h = stop_h - start_h;
            suma_h += czas_h;
///--------------------------------------------------------------------------------------- pokazuje czas pracy
            cout<<day<<" ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
            cout<<czas_h<<"h"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        }
        else
        {
            cout<<day<<" --"<<endl;
        }
    }
///------------------------------------------------------------------------------------------- WHILE koniec
///------------------------------------------------------------------------- ZAKONCZENIE: czas pracy w miesiacu
    zamknij_plik();
    cout<<"Suma godzin w miesiacu = ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout<<suma_h <<"h"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout<<"Dni pracy: "<<ile_dni<<endl;
    if (ile_dni==0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout << "PLIK JEST PUSTY" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    }
    system("PAUSE");
    return 0;
}

