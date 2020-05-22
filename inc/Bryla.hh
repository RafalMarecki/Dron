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
    int id;
    Wektor3D PozycjaSrodka;
    Wektor3D Odniesienie;
    MacierzObr Orientacja;

    public:
    void ustaw_pozycja (const Wektor3D & PozycjaSrodka);
    void ustaw_orientacja (const MacierzObr &);    //
    virtual int rysuj(shared_ptr<Draw3DAPI>) = 0;
    //virtual void rerysuj() = 0;
    //Bryla() = delete;
    //virtual void wymaz() = 0;

};

#endif