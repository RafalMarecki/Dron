#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Prostopadloscian.hh"

class Dron : public Prostopadloscian
{
    public:
    Dron ();
    Dron (double bokA, double bokB, double bokC);
    void ObrotX (double kat);
    void ObrotY (double kat);
    void ObrotZ (double kat);
    //void Obrot_AnimX (shared_ptr<Draw3DAPI> api, double kat);
    //void Obrot_AnimY (shared_ptr<Draw3DAPI> api, double kat);
    void Obrot_AnimZ (shared_ptr<Draw3DAPI> api, double kat);
    //void plyn (shared_ptr<Draw3DAPI> api, double odleglosc);
    void plyn (shared_ptr<Draw3DAPI> api, double odleglosc, double kat);
    //void przesun_o_wektor (Wektor3D & W);
    void Przesun (double dlugosc, double kat);
    void Przesun_Anim (shared_ptr<Draw3DAPI> api, double odleglosc, double kat);
};
#endif