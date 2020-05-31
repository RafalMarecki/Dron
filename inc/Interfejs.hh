#ifndef INTERFEJS_HH
#define INTERFEJS_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Dr3D_gnuplot_api.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using drawNS::Draw3DAPI;
using namespace std;

class Interfejs
{   
    public:
    Interfejs () {};
    //virtual void ObrotX (double kat) = 0;
    virtual void ObrotY (double kat) = 0;
    virtual void ObrotZ (double kat) = 0;
    virtual void Przesun (double dlugosc) = 0;
    //virtual void Obrot_AnimX (shared_ptr<Draw3DAPI> api, double kat) = 0;
    virtual void Obrot_AnimY (shared_ptr<Draw3DAPI> api, double kat) = 0;
    virtual void Obrot_AnimZ (shared_ptr<Draw3DAPI> api, double kat) = 0;
    virtual void plyn (shared_ptr<Draw3DAPI> api, double odleglosc, double kat) = 0;
    virtual void Przesun_Anim (shared_ptr<Draw3DAPI> api, double odleglosc) = 0;
};
#endif