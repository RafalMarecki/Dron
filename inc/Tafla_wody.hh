#ifndef TAFLA_WODY_HH
#define TAFLA_WODY_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Plaszczyzna.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Przeszkoda.hh"

class Tafla : public Plaszczyzna, public Przeszkoda
{
    public:
    Tafla(){};
    int rysuj(shared_ptr<Draw3DAPI> api) override;
    bool czy_kolizja (shared_ptr<Interfejs> X) override;
};

#endif