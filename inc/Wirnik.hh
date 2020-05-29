#ifndef WIRNIK_HH
#define WIRNIK_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Graniastoslup.hh"

class Wirnik : public Graniastoslup
{
    protected:
    MacierzObr Obrot;
    void get_global_wspolrzedne (Wektor3D Wspolrzedne[]) const;

    public:
    Wirnik () {};
    Wirnik (double bok, double h);
    void Set_Wymiary (double bok, double h);
    void Przesun (double dlugosc);
    void Obrot_Wirnik (double kat);
    void Obrot_Wirnik (Wektor3D Odsuniecie, MacierzObr Orientacja_Drona, MacierzObr Obrot_Wirnik);
    int rysuj (shared_ptr<Draw3DAPI> api) override;
    //void Przesun (double odleglosc);
};
#endif