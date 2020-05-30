#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Bryla.hh"


class Graniastoslup : public Bryla 
{
    protected:
    double Bok;
    double H;
  
    Graniastoslup() {}; 
    void get_global_wspolrzedne (Wektor3D Wspolrzedne[]) const;

    public:
    Graniastoslup (double bok, double h);
    void pozycja(const Wektor3D &wek);
    int rysuj (shared_ptr<Draw3DAPI> api) override;
};


#endif