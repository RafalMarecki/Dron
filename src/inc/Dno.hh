
#ifndef DNO_HH
#define DNO_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Plaszczyzna.hh"

class Dno : public Plaszczyzna
{
    public:
    Dno(){};
    int rysuj(shared_ptr<Draw3DAPI> api) override;
};

#endif