#ifndef PRZESZKODA_PROSTOPADLOSCIAN_HH
#define PRZESZKODA_PROSTOPADLOSCIAN_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Prostopadloscian.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Przeszkoda.hh"

class Przeszkoda_Prostopadloscian : public Przeszkoda, public Prostopadloscian
{
    protected:
    Przeszkoda_Prostopadloscian () {}; 

    public:
    Przeszkoda_Prostopadloscian (double AA, double BB, double CC);
    bool czy_kolizja (shared_ptr<Interfejs> X) override;
    //int rysuj (shared_ptr<Draw3DAPI>);
};

#endif