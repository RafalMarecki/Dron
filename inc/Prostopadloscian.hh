#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Bryla.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::vector;

class Prostopadloscian: public Bryla
{
    protected:
    double A;
    double B;
    double C;
    Prostopadloscian () {};

    public:
    Prostopadloscian (double A, double B, double C);

    void ustaw_pozycja (const Wektor3D & Wektor); 

    void ustaw_orientacja (const MacierzObr & MacObrot);

    void ustaw_orientacja_wektor (Wektor3D & Wektor) const; //

    void get_global_wspolrzedne (Wektor3D Wspolrzedne[]); //

    int rysuj(shared_ptr<Draw3DAPI>) override;


    //virtual void ruch(const Wektor3D & Przesuniecie);
    
        
    
};
#endif