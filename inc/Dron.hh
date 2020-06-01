#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Bryla.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Prostopadloscian.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Wirnik.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Interfejs.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Przeszkoda.hh"

class Dron : public Prostopadloscian, public Interfejs, public Przeszkoda
{
    protected:
    Wirnik L;
    Wirnik P;
    Wektor3D Odsuniecie_L;
    Wektor3D Odsuniecie_P;
    Dron () {};

    public:
    Dron (double bokA, double bokB, double bokC);
    void Obroc_L_Wirnik ();
    void Obroc_P_Wirnik ();
    //void ObrotX (double kat) override;
    void ObrotY (double kat) override;
    void ObrotZ (double kat) override;
    //void Obrot_AnimX (shared_ptr<Draw3DAPI> api, double kat) override;
    void Obrot_AnimY (shared_ptr<Draw3DAPI> api, double kat) override;
    void Obrot_AnimZ (shared_ptr<Draw3DAPI> api, double kat) override;
    void plyn (shared_ptr<Draw3DAPI> api, double odleglosc, double kat) override;
    void Przesun (double dlugosc) override;
    void Przesun_Anim (shared_ptr<Draw3DAPI> api, double odleglosc) override;
    void narysuj (shared_ptr<Draw3DAPI> api);
    //bool czy_kolizja (shared_ptr<Interfejs> X) override;

    //void plyn (shared_ptr<Draw3DAPI> api, double odleglosc);
    //void przesun_o_wektor (Wektor3D & W);
    //void Przesun (double dlugosc, double kat);
    //void Przesun_Anim (shared_ptr<Draw3DAPI> api, double odleglosc, double kat);
};
#endif