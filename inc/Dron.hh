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
    vector<shared_ptr<Przeszkoda>> kolekcja_przeszkod;
    vector<shared_ptr<Interfejs>> kolekcja_dronow;
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
    bool czy_kolizja (shared_ptr<Interfejs> X) override;
    double wez_promien () override;
    Wektor3D zwroc_odniesienie () override {return Odniesienie;};
    void ustaw_pozycja1 (const Wektor3D & srodek); //To potrzebne tylko do ustawienia pozycji drona2 na poczatku, bo zwykle ustaw pozycja nie przesuwalo wirników MOŻE TU JEST PROBLEM W WIRNIKACH!!!
    void set_kolekcja_dronow (vector<shared_ptr<Interfejs>> kolekcja)
    {kolekcja_dronow = kolekcja;}
    void set_kolekcja_przeszkod (vector<shared_ptr<Przeszkoda>> kolekcja)
    {kolekcja_przeszkod = kolekcja;}
};
#endif