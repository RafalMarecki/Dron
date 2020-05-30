#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Bryla.hh"

class Plaszczyzna : public Bryla
{
    public:
    double Poziom;
    void ustaw_poziom (double poz);
    virtual int rysuj(shared_ptr<Draw3DAPI> api) = 0;
};
#endif