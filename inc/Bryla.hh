#ifndef OBIEKT_HH
#define OBIEKT_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Dr3D_gnuplot_api.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/MacierzObr.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wektor.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using drawNS::Draw3DAPI;
using namespace std;

class Bryla
{
    protected:
    shared_ptr<Draw3DAPI> api;
    int id = 0;
    Wektor3D PozycjaSrodka;
    Wektor3D Odniesienie;
    MacierzObr Orientacja;

    public:
    void ustaw_pozycja (const Wektor3D & srodek) {PozycjaSrodka = srodek;};
    void ustaw_orientacja (const MacierzObr & orientacja) {Orientacja = orientacja;};
    virtual int rysuj(shared_ptr<Draw3DAPI>) = 0;
};

#endif