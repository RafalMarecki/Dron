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
    int rysuj (shared_ptr<Draw3DAPI> api) override;
    void Przesun (double odleglosc);
};
#endif