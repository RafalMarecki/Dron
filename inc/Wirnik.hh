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
    //void ustaw_orientacja_razy (const MacierzObr & XD) {Orientacja = Orientacja * XD; Obrot = Obrot * XD;};
    void Krec_Wirnik (double kat);
    void Obrot_Wirnik (double kat);
    //void Obrot_Wirnik_Dron (Wektor3D odsuniecie_wirnika, MacierzObr mac_obrotu, MacierzObr orient_dron);
    int rysuj (shared_ptr<Draw3DAPI> api) override;
};
#endif