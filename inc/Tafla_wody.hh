#ifndef TAFLA_WODY_HH
#define TAFLA_WODY_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Plaszczyzna.hh"

class Tafla : public Plaszczyzna
{
    public:
    Tafla(){};
    int rysuj(shared_ptr<Draw3DAPI> api) override;
};

#endif