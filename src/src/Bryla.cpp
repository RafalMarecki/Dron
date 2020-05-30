#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Bryla.hh"

void Bryla::ustaw_pozycja (const Wektor3D & srodek)
{
    PozycjaSrodka = srodek;
}

void Bryla::ustaw_orientacja (const MacierzObr & orientacja)
{
    Orientacja = orientacja;
}