
#ifndef DNO_HH
#define DNO_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Plaszczyzna.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Przeszkoda.hh"

class Dno : public Plaszczyzna, public Przeszkoda
{
    public:
    Dno(){};
    int rysuj(shared_ptr<Draw3DAPI> api) override;
    bool czy_kolizja (shared_ptr<Interfejs> X) override;
};

#endif