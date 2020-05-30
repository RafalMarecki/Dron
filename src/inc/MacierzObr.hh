#ifndef MACIERZOBR_HH
#define MACIERZOBR_HH

#include <iostream>
#include <cmath>
#include "/home/rafaeldali/Pulpit/Dane do programów/droniarz/inc/Macierz.hh"
using namespace std;

class MacierzObr: public Macierz<double,3>
{
    public:
    MacierzObr();
    MacierzObr(const Macierz<double,3> &M);
    MacierzObr(double stopnie, char os);
  
};
#endif
  /*  
    public:
    MacierzObr () {this->jednostkowa();}
    MacierzObr (double kat, char os_obrotu) : Macierz<double,3> (Stworz_MacierzObr (kat,os_obrotu)) {}

    private:
    Macierz<double,3> Stworz_MacierzObr (double kat, char os_obrotu) 
    {
     //Macierz<double,3> A;
        switch (os_obrotu)
    {
        case 'x':
        {
            tabM[1][1]=cos(kat);
            tabM[1][2]=-sin(kat);
            tabM[2][1]=sin(kat);
            tabM[2][2]=cos(kat);
        }break;

        case 'y':
        {
            tabM[0][0]=cos(kat);
            tabM[0][2]=sin(kat);
            tabM[2][0]=-sin(kat);
            tabM[2][2]=cos(kat);
        }break;

        case 'z':
        {
            tabM[0][0]=cos(kat);
            tabM[0][1]=-sin(kat);
            tabM[1][0]=sin(kat);
            tabM[1][1]=cos(kat);
        }break;

        default:
        {
            cerr<<"Podales zly wymiar!"<<endl;
            exit (1);
        }break;
    }
    }
};
*/